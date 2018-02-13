#include <bits/stdc++.h>
using namespace std;
long long solve(string s)
{
    long long ans=0,ss=0;
    for(int i=0;i<s.size();i++)
    {
        if(s[i]=='s')ss++;
        else ans+=ss;
    }
    return ans;
}
bool cmp(string a ,string b)
{
    return (solve(a+b)>solve(b+a));
}

int main()
{
   ios::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);
    int n;
    cin>>n;
    vector<string> vec;
    string st;
    while(n--)
    {
        cin>>st;
        vec.push_back(st);
    }
    sort(vec.begin(),vec.end(),cmp);
    st="";
    for(int i=0;i<vec.size();i++)st+=vec[i];
    cout<<solve(st);

  return 0;
}
