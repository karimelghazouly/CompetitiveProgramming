#include <bits/stdc++.h>
using namespace std;
int f[100],d[100],t[100],n,h;
int ans[50][200][200];
int dp[100][500];
int solve(int idx, int left)
{
    if(idx==n||left<=0)return 0;
    int ret=0,mx=0;
    if(dp[idx][left]!=-1)return dp[idx][left];
    ans[idx][left][0]=solve(idx+1,left-t[idx]);
    mx=max(mx,ans[idx][left][0]);
    for(int i=1;i<=left;i++)
    {
        ret+=max((f[idx]-((i-1)*d[idx])),0);
        ans[idx][left][i]=ret+solve(idx+1,left-i-t[idx]);
        mx=max(mx,ans[idx][left][i]);
    }
    //cout<<"idx = "<<idx<<" left = "<<left<<" mx = "<<mx<<endl;
    return dp[idx][left]=mx;

}
int main()
{
    freopen("ayhaga.txt","w",stdout);
    bool first=true;
    while(cin>>n)
    {
        int mxhere=0,timehere=0,last=0;
        for(int i=0;i<50;i++)for(int j=0;j<200;j++)for(int z=0;z<200;z++)ans[i][j][z]=-1;
        for(int i=0;i<100;i++)for(int j=0;j<500;j++)dp[i][j]=-1;
        if(n==0)break;
        cin>>h;
        for(int i=0;i<n;i++)cin>>f[i];
        for(int i=0;i<n;i++)cin>>d[i];
        for(int i=0;i<n-1;i++)cin>>t[i];
        last=solve(0,(h*60)/5);
        int left=(h*60)/5;
        if(!first)cout<<endl;
        for(int i=0;i<n;i++)
        {
            mxhere=0; timehere=0;
            for(int j=0;j<=left;j++)
            {
                //cout<<"ans[i][left][j] = "<<ans[i][left][j]<<" i = "<<i<<" j = "<<j<<endl;
                if(ans[i][left][j]>=mxhere&&ans[i][left][j]!=-1)
                {
                   timehere=j;
                   mxhere=ans[i][left][j];
                }
            }
            if(!i)cout<<(timehere)*5;
            else cout<<", "<<(timehere)*5;
            left-=timehere+t[i];
            left=max(left,0);
        }
        cout<<endl<<"Number of fish expected: "<<last<<endl;
        first=false;
    }
    return 0;
}
