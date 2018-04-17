#include <bits/stdc++.h>
using namespace std;
int incc[1000],decc[1000];
int main()
{
   ios::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);
    int n,sum,x,mx=-1,pass=0;
    cin>>n;
    for(int i=1;i<=n;i++)
    {
        sum=0;
        for(int j=1;j<=n;j++)
        {
            cin>>x;
            sum+=x;
            if(j>=i)decc[j]+=x,decc[j+n]+=x;
            else decc[j+n]+=x;
        }
        incc[i]+=sum;
        incc[i+n]+=sum;
    }
    for(int i=1;i<=n*2;i++)
    {
        //cout<<"i = "<<i<<" incc = "<<incc[i]<<" dec = "<<decc[i]<<endl;
        pass+=incc[i]-decc[i];
        mx=max(pass,mx);
    }
    cout<<mx;
  return 0;
}
