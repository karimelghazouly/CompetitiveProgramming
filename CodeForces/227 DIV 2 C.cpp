#include <bits/stdc++.h>
using namespace std;
long long mod;
long long fp(long long b , long long p)
{
    if(p==0)return 1;
    if(p==1)return b;
    long long r=fp(b,p/2)%mod;
    r=(r*r)%mod;
    if(p%2)
    {
        r=r*(b%mod);
        r=r%mod;
    }
    return r;
}
int main()
{
   ios::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);
    long long n,z=0;
    cin>>n>>mod;
    cout<<((fp(3,n)-1)+mod)%mod;
  return 0;
}
