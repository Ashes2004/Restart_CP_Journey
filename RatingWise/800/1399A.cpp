    //A. Remove Smallest 

    #include <iostream>

    #include <vector>

    #include <algorithm>

    #include <cmath>

    #include <map>

    #include <set>

    #include <queue>

    #include <stack>

    #include <deque>

    #include <unordered_map>

    #include <unordered_set>

    #include <cstring>

    #include <sstream>

    #include <iomanip>

    #include <bitset>

    #include <functional>

    #include <numeric>

    #include <limits>

    #include <climits>

    using namespace std;

    #define FAST_IO ios_base::sync_with_stdio(false);
   
    #define ll long long
    #define ull unsigned long long
    #define vi vector < int >
        #define vll vector < long long >
        #define pii pair < int, int >
        #define pll pair < long long, long long >
        #define pb push_back
    #define mp make_pair
    #define ff first
    #define ss second
    #define all(v) v.begin(), v.end()
    #define rep(i, a, b) for (int i = a; i < b; i++)
        #define per(i, a, b) for (int i = a; i >= b; i--)
            #define sz(x)((int)(x).size())

    const int MOD = 1e9 + 7;
    const int INF = 1e9;
    const ll LINF = 1e18;

    template < typename T > void read(vector < T > & v) {
        for (auto & x: v) cin >> x;
    }
    template < typename T > void print(const vector < T > & v) {
        for (const auto & x: v) cout << x << ' ';
        cout << '\n';
    }
    template < typename T1, typename T2 > void print(const pair < T1, T2 > & p) {
        cout << p.ff << ' ' << p.ss << '\n';
    }

    void solve() {
        int n;
        cin >> n;
        vector < int > arr(n);
        rep(i, 0, n) {
            cin >> arr[i];
        }

        sort(arr.begin(), arr.end());

        bool ok = true;
        for (int i = 1; i < n; i++) {
            if (arr[i] - arr[i - 1] > 1) {
                ok = false;
                break;
            }
        }

        cout << (ok ? "YES" : "NO") << "\n";
    }


    int main() {
        FAST_IO

        int t;
        cin >> t;
        while (t--)
        {
            solve();
        }

        return 0;
    }
