#include <bits/stdc++.h>
using namespace std;
int main()
{
    long long n,p,q,a,b,mxd,mxc,mnd,mnc,cur,cnt1,cnt2,cnt3;
    cin>>n>>a>>b>>p>>q;
    if(p>q)mxc=p,mxd=a,mnc=q,mnd=b;
    else mxc=q,mxd=b,mnc=p,mnd=a;
    cnt1=n/mxd;
    cnt2=n/mnd;
    long long lcm=(a/__gcd(a,b))*b;
    cnt3=n/lcm;
    //cout<<"cnt1 = "<<cnt1<<" cnt2 = "<<cnt2<<" cnt3 = "<<cnt3<<endl;
    cnt2-=cnt3;
    cout<<cnt1*mxc+cnt2*mnc;
    return 0;
}
