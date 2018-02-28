

#include <bits/stdc++.h>
using namespace std;
double sum[500009],q,mx,t,b,s,c;
int leftt,rightt,m1,m2,blck,cnt;
double f(int x)
{
    return (sum[x]+mx)/(x+2);
}
double ternary()
{
    leftt=0; rightt=cnt-1;
    while(rightt-leftt>100)
    {
        blck=(rightt-leftt)/3;
        m1=leftt+blck; m2=leftt+2*blck;
        //cout<<"f(m1) = "<<f(m1)<<" f(m2) = "<<f(m2)<<endl;
        if(f(m1)>=f(m2))leftt=m1;
        else rightt=m2;
    }
    double last=1e9;
    for(int i=leftt;i<=rightt;i++)last=min(last,f(i));
    return last;
}
int main()
{
    scanf("%lf",&q);
    for(int i=0;i<q;i++)
    {
        scanf("%lf",&t);
        if(t==1)
        {
            scanf("%lf",&mx);
            s+=mx;
            sum[cnt]=s;
            cnt++;
        }
        else
        {
            t=ternary();
         //   cout<<"t = "<<t<<endl;
            printf("%.6f\n",mx-t);
        }
    }

  return 0;
}
