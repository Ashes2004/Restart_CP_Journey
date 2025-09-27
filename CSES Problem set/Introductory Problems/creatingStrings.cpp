#include<iostream>
#include<string>
#include<set>
#include<vector>
#include<algorithm>

using namespace std;


void generate(string s , int idx , set<string>&str){
    if(idx == s.size())
    {
        str.insert(s);
        return;
    }


    for(int i = idx ; i<s.size() ; i++)
    {
        swap(s[idx] , s[i]);
        generate(s , idx + 1 , str);
        swap(s[idx] , s[i]);
    }

}


int main()
{
    string str;
    cin>>str;


    set<string>st;
   
    generate(str , 0 , st);
    cout<<st.size()<<endl;
    for(string s : st)
    {
        cout<<s<<endl;
    }
}