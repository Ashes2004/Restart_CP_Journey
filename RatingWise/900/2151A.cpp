// A. Incremental Subarray

#include <bits/stdc++.h>
using namespace std;

#define FAST_IO ios_base::sync_with_stdio(false); cin.tie(nullptr);

void solve() {
    int n, m;
    cin >> n >> m;

    vector<int> a(m);
    for (int i = 0; i < m; i++) cin >> a[i];

    int maxi = *max_element(a.begin(), a.end());
    int mini = *min_element(a.begin(), a.end());


    if (maxi == mini) {
        if (m == 1) {
            cout << n - maxi + 1 << "\n";
        } else {
            cout << 1 << "\n";
        }
        return;
    }

    bool fits_inside = true;
    for (int i = 1; i < m; i++) {
        if (a[i] != a[i-1] + 1) {
            fits_inside = false;
            break;
        }
    }

    if (fits_inside) {
        cout << n - maxi + 1 << "\n";
    } else {
        cout << 1 << "\n";
    }
}

int main() {
    FAST_IO
    int t;
    cin >> t;
    while (t--) solve();
    return 0;
}
