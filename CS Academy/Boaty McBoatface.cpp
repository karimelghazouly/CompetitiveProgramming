#include <bits/stdc++.h>
using namespace std;
int main()
{
   ios::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);
    double d,t,v1,v2,diff=0,ans=0;
    cin>>d>>t>>v1>>v2;
    diff=v2-v1;
    while(t>0)
    {
        d+=diff;
        t--; ans++;
        if(d<=0)
        {
            cout<<ans;
            return 0;
        }
    }
    cout<<ceil(d/v1)+ans;
  return 0;
}
