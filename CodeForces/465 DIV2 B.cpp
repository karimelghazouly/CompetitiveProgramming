#include <bits/stdc++.h>
using namespace std;
int main()
{
   ios::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);
    int n,cnt=0,x=0,y=0,cur;
    cin>>n;
    string s;
    cin>>s;
    if(s[0]=='U')cur=1,y++;
    else cur=2,x++;
    for(int i=1;i<s.size();i++)
    {
        //cout<<x<<" "<<y<<" "<<cur<<endl;
        if(x==y&&cur==1&&s[i]=='R')cnt++,cur=2;
        else if(x==y&&cur==2&&s[i]=='U')cnt++,cur=1;
        if(s[i]=='U')y++;
        else x++;
    }
    cout<<cnt;
  return 0;
}
