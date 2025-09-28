

#include<iostream>


using namespace std;

#define int long long
#define endl '\n'

void solve() {
    int n;
    cin>>n;
    
    int count = 0;
    
    for(int i = 5 ; n / i > 0 ; i *= 5)
    {
        count += n / i ; 
    }
    
    
    cout<<count<<endl;
    

}

int32_t main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t = 1;
    // cin >> t; 
    while (t--) solve();
}
