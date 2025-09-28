//A. Word Capitalization

#include <bits/stdc++.h>
using namespace std;

#define int long long
#define endl '\n'

void solve() {
   
    string str;
    cin>>str;
    
    if(islower(str[0])){
        str[0] = toupper(str[0]);
    }
    
    cout<<str<<endl;

   
}

int32_t main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t = 1;
    // cin >> t; 
    while (t--) solve();
}
