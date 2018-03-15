#include <bits/stdc++.h>
using namespace std;
vector< pair<int,int> > edge[100009];
int dp[400009],mx;
int main()
{
   ios::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);
    int n,m,x,y,w;
    cin>>n>>m;
    for(int i=0;i<m;i++)
    {
        cin>>x>>y>>w;
        edge[w].push_back({x,y});
    }
    for(int i=0;i<=1e5;i++)
    {
        int sz=edge[i].size();
        vector<int>temp(sz,0);
        for(int j=0;j<sz;j++)
        {
            x=edge[i][j].first;
            y=edge[i][j].second;
            temp[j]=max(dp[y],dp[x]+1);
        }
        for(int j=0;j<sz;j++)
        {
            x=edge[i][j].first;
            y=edge[i][j].second;
            dp[y]=max(temp[j],dp[y]);
        }
    }
    for(int i=0;i<400009;i++)mx=max(mx,dp[i]);
    cout<<mx;
  return 0;
}
