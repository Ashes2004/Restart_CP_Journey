// A. Hulk (705A)

#include <bits/stdc++.h>
using namespace std;

int main() {
	int n;
	cin>>n;
	
	string odd = "I hate ";
	string even = "I love ";
	string mid = "that ";
	string end = "it";
	string ans = "";
	
	for(int i = 1 ; i<= n ; i++)
	{
	    if(i > 1)
	    {
	        ans += mid;
	    }
	    
	    if( i % 2 != 0)
	    {
	        ans += odd;
	    }else{
	        ans += even;
	    }
	    
	    
	}
	
	ans += end;
	
	cout<<ans<<endl;

}
