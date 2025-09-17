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

# ---- Fetch LeetCode solved problems ----
def get_lc_solved(username):
    url = f"https://alfa-leetcode-api.onrender.com/{username}/solved"
    res = requests.get(url).json()
    return res.get("solvedProblem", 0)

# ---- Update README.md ----
def update_readme(cf_count, lc_count):
    readme = README_FILE.read_text()

    new_section = f"""
# 📊 Current Ratings & Progress

- **Codeforces:** ✅ Problems Solved: **{cf_count}**
- **LeetCode:** ✅ Problems Solved: **{lc_count}**
"""

    updated = re.sub(
        r"#.*Current Ratings & Progress[\s\S]*?(?=\n#|$)",
        new_section,
        readme,
    )

    README_FILE.write_text(updated)


if __name__ == "__main__":
    cf_solved = get_cf_solved(CODEFORCES_HANDLE)
    lc_solved = get_lc_solved(LEETCODE_USERNAME)
    update_readme(cf_solved, lc_solved)
