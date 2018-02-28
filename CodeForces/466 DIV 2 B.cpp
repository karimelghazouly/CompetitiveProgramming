#include <bits/stdc++.h>
using namespace std;
long long k,x,y,n,d,r,ans,o=1;
int main()
{
   ios::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);
    cin>>n>>k>>x>>y;
    if(k==1)
    {
        cout<<x*(n-1);
        return 0;
    }
    while(n>1)
    {
        d=n/k;
        r=n%k;
        if(r==0)
        {
            ans+=min(y,(n-d)*x);
            n=d;
        }
        else
        {
            ans+=x*(n-max(o,d*k));
            n=max(o,d*k);
        }
    }
    cout<<ans;

  return 0;
}
