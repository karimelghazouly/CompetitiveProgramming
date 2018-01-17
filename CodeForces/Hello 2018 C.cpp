#include <bits/stdc++.h>
using namespace std;
long long cost[50],n,l,w,d,m;
long long dp[50][2];
long long po(long long b,long long p)
{
    long long ret=1;
    for(long long i=1;i<=p;i++)ret*=b;
    return ret;
}

long long solve(long long idx,bool missing)
{
    //cout<<"idx = "<<idx<<" missing = "<<missing<<endl;
    if(idx==31)
    {
        if(missing)return 1e18;
        return 0;
    }
    if(dp[idx][missing]!=-1)return dp[idx][missing];
    long long ret=1e18;
    if(((1<<idx)&l))ret=min(solve(idx+1,1),cost[idx]+solve(idx+1,missing));
    else ret=min(solve(idx+1,missing),cost[idx]+solve(idx+1,0));
    //cout<<"idx = "<<idx<<" ret = "<<ret<<endl;
    return dp[idx][missing]=ret;
}

int main()
{
   ios::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);
    cin>>n>>l;
    for(int i=0;i<50;i++)dp[i][0]=dp[i][1]=-1,cost[i]=1e18;
    for(long long i=0;i<n;i++)cin>>cost[i];
    for(long long i=1;i<=30;i++)
    {
        w=po(2,i);
        for(long long j=0;j<i;j++)
        {
            d=w/po(2,j);
           // cout<<"i = "<<i<<" cost[i] = "<<cost[i]<<" d = "<<d<<" cost[j] = "<<cost[j]<<endl;
            cost[i]=min(cost[i],d*cost[j]);
        }
    }
    cout<<solve(0,0);
  return 0;
}
