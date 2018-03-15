#include <bits/stdc++.h>
using namespace std;
int mod=(1e9)+7,dp[25][1000005],last[1000009];
long long poow[1000009];
long long solve(int x,int y)
{
    if(x<0)return 0;
    //cout<<"X = "<<x<<" y = "<<y<<endl;
    if(y<0)
    {
        //cout<<"y = "<<y<<" !x = "<<!x<<endl;
        return !x;
    }
    if(dp[x][y]!=-1)
    {
        //1cout<<"returning dp = "<<dp[x][y]<<endl;
        return dp[x][y];
    }
    return dp[x][y]=((solve(x-1,y)%mod)+(solve(x,y-1)%mod))%mod;
}
int main()
{
   ios::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);
    memset(dp,-1,sizeof(dp));
    int q,x,y;
    long long ans,t=2;
    poow[0]=1;
    for(int i=1;i<=1000000;i++)
    {
        poow[i]=(poow[i-1]*t)%mod;
        if(last[i]==0&&i!=1)
        {
            x=i;
            while(x<=1000009)
            {
                last[x]=i;
                x+=i;
            }
        }
    }
    cin>>q;
    while(q--)
    {
        cin>>x>>y;
        map<int,int>cnt;
        while(x>1)
        {
            cnt[last[x]]++;
            x=x/last[x];
        }
        ans=1;
        for(auto it =cnt.begin();it!=cnt.end();it++)
        {
            x=it->second;
            ans=(ans*(solve(x,y-1)))%mod;
            //cout<<"solve = "<<solve(x,y-1)<<endl;
        }
        ans=(ans*poow[y-1])%mod;
        cout<<ans<<endl;
    }
  return 0;
}
