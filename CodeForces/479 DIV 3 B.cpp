#include <bits/stdc++.h>
using namespace std;
map<string,int>mapp;
int main()
{
   ios::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);
    int n,mx=-1;
    string s,txt="",ans;
    cin>>n>>s;
    for(int i=0;i+1<s.size();i++)
    {
        txt=s[i];
        txt+=s[i+1];
        mapp[txt]++;
    }
    for(auto it = mapp.begin();it!=mapp.end();it++)
    {
        if(it->second>mx)mx=it->second,ans=it->first;
    }
    cout<<ans;
  return 0;
}
