// A. Helpful Maths
#include <iostream>
#include <vector>
#include <algorithm>
#include <sstream>
using namespace std;

#define FAST_IO ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);

void solve() {
    string str;
    cin >> str;
    vector<string> parts;
    string token;
    stringstream ss(str);

    while (getline(ss, token, '+')) {
        parts.push_back(token);
    }

    sort(parts.begin(), parts.end());

    string ans = "";
    for (int i = 0; i < parts.size(); i++) {
        ans += parts[i];
        if (i < parts.size() - 1) {   
            ans += "+";
        }
    }

    cout << ans << "\n";
}

int main() {
    FAST_IO
    solve();   
    return 0;
}
