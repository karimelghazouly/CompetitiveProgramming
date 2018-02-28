#include <bits/stdc++.h>
using namespace std;
int n,arr[30][30];
bool found,vis[30];
string s1,s2;
vector<pair<int,int> >ans;
void dfs(int cur,int trgt)
{
    if(cur==trgt){found=1; return;}
    vis[cur]=1;
    for(int i=0;i<30;i++)
    {
        if(!vis[i]&&arr[cur][i])dfs(i,trgt);
    }
}
int main()
{
   ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    cin>>n>>s1>>s2;
    for(int i=0;i<s1.size();i++)
    {
        found=0;
        memset(vis,0,sizeof(vis));
        dfs(s1[i]-'a',s2[i]-'a');
        if(!found)
        {
            ans.push_back({s1[i]-'a',s2[i]-'a'});
            arr[s1[i]-'a'][s2[i]-'a']=arr[s2[i]-'a'][s1[i]-'a']=1;
        }
    }
    cout<<ans.size()<<endl;
    for(int i=0;i<ans.size();i++)
    {
        char x='a'+ans[i].first;
        char y='a'+ans[i].second;
        cout<<x<<" "<<y<<endl;
    }
  return 0;
}
