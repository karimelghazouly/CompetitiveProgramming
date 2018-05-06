#include <bits/stdc++.h>
using namespace std;
bool vis[200009],cyc;
int n,m,x,y,cnt;
vector<int>listt[200009];
void dfs(int node)
{
    vis[node]=1; cnt++;
    //cout<<"node = "<<node<<" list = "<<listt[node].size()<<endl;
    if(listt[node].size()!=2)cyc=0;
    for(int i=0;i<listt[node].size();i++)
    {
        int nxt=listt[node][i];
        if(!vis[nxt])dfs(nxt);
    }
}
int main()
{
   ios::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);
    cin>>n>>m;
    int ans=0;
    for(int i=0;i<m;i++)
    {
        cin>>x>>y;
        listt[x].push_back(y);
        listt[y].push_back(x);
    }
    for(int i=1;i<=n;i++)
    {
        cyc=1;
        if(!vis[i])
        {
            dfs(i);
            if(cyc&&cnt>2)ans++;
            //cout<<cyc<<"----------------------"<<endl;
        }
    }
    cout<<ans;
  return 0;
}
/*
8 9
1 2
2 3
3 4
4 5
5 3
5 1
6 7
7 8
8 6*/
