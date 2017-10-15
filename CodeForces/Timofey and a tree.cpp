#include <bits/stdc++.h>
using namespace std;
vector<int>listt[100009];
int color[100009];
bool visited[100009];
bool dfs(int node,bool first)
{
    //cout<<"node = "<<node<<endl;
    visited[node]=true;
    for(int i=0;i<listt[node].size();i++)
    {
        if(visited[listt[node][i]])continue;
        if(color[listt[node][i]]!=color[node]&&!first)return false;
        if(!dfs(listt[node][i],0))return false;
    }
    return true;
}
int main()
{
    bool f=false;
    int n,u,v,a=1,b=1;
    cin>>n;
    for(int i=0;i<n-1;i++)
    {
        cin>>u>>v;
        listt[u].push_back(v);
        listt[v].push_back(u);
    }
    for(int i=1;i<=n;i++)cin>>color[i];
    for(int i=1;i<=n;i++)
    {
        for(int j=0;j<listt[i].size();j++)
        {
            //cout<<" i = "<<i<<" colors[i] = "<<color[i]<<" nxt = "<<listt[i][j]<<" colors[nxt] = "<<color[listt[i][j]]<<endl;
            if(color[i]!=color[listt[i][j]])
            {
                a=i;
                b=listt[i][j];
                f=true;
                break;
            }
        }
    }
    if(dfs(a,1)||!f)cout<<"YES"<<endl<<a;
    else
    {
      //  cout<<"Seconddddddddd"<<endl;
        memset(visited,0,sizeof(visited));
        if(dfs(b,1))cout<<"YES"<<endl<<b<<endl;
        else cout<<"NO"<<endl;
    }
    return 0;
}
