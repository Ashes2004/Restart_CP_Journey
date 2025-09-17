import requests
import re
from pathlib import Path

# ---- Config ----
CODEFORCES_HANDLE = "Mr_Ashes_2004"
LEETCODE_USERNAME = "ashes_2004"
README_FILE = Path("README.md")

# ---- Fetch Codeforces solved problems ----
def get_cf_solved(handle):
    url = f"https://codeforces.com/api/user.status?handle={handle}"
    res = requests.get(url).json()
    solved = set()
    for sub in res["result"]:
        if sub["verdict"] == "OK":
            pid = f"{sub['problem']['contestId']}{sub['problem']['index']}"
            solved.add(pid)
    return len(solved)

# ---- Fetch Codeforces rating ----
def get_cf_rating(handle):
    url = f"https://codeforces.com/api/user.info?handles={handle}"
    res = requests.get(url).json()
    if res["status"] == "OK":
        return res["result"][0].get("rating", "Unrated")
    return "N/A"

# ---- Fetch LeetCode solved problems ----
def get_lc_solved(username):
    url = f"https://alfa-leetcode-api.onrender.com/{username}/solved"
    res = requests.get(url).json()
    return res.get("solvedProblem", 0)

# ---- Fetch LeetCode contest rating ----
def get_lc_rating(username):
    url = f"https://alfa-leetcode-api.onrender.com/{username}/contest"
    res = requests.get(url).json()
    return res.get("contestRating", "Unrated")

# ---- Update README.md ----
def update_readme(cf_count, lc_count, cf_rating, lc_rating):
    readme = README_FILE.read_text()

    new_section = f"""
# 📊 Current Ratings & Progress

- **Codeforces:** `Rating: {cf_rating}`  ✅ Problems Solved: **{cf_count}**
- **LeetCode:** `Rating: {lc_rating}`  ✅ Problems Solved: **{lc_count}**
"""

    updated = re.sub(
        r"#.*Current Ratings & Progress[\s\S]*?(?=\n#|$)",
        new_section,
        readme,
    )

    README_FILE.write_text(updated)


if __name__ == "__main__":
    cf_solved = get_cf_solved(CODEFORCES_HANDLE)
    cf_rating = get_cf_rating(CODEFORCES_HANDLE)
    lc_solved = get_lc_solved(LEETCODE_USERNAME)
    lc_rating = get_lc_rating(LEETCODE_USERNAME)

    print("CF Solved:", cf_solved, "CF Rating:", cf_rating)
    print("LC Solved:", lc_solved, "LC Rating:", lc_rating)

    update_readme(cf_solved, lc_solved, cf_rating, lc_rating)
