//B. Drinks

#include <bits/stdc++.h>

using namespace std;

#define int long long
#define endl '\n'

void solve() {
    int n;
    cin >> n;
    float d = 0;
    int i = n;
    while(i--)
    {
        float temp;
        cin>>temp;
        d += (temp/100);
    }
    
    
    float ans = (d / n) * 100;
    cout<<ans<<endl;

}

int32_t main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t = 1;
    // cin >> t; 
    while (t--) solve();
}
