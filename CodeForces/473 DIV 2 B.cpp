#include <bits/stdc++.h>
using namespace std;
set<int>st[100005];
map<string,int>id;
int n,k,m,x,idx,cost[100005],group[100005];
long long ans;
int main()
{
   ios::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);
    cin>>n>>k>>m;
    string s;
    for(int i=1;i<=n;i++)
    {
        cin>>s;
        id[s]=i;
    }
    for(int i=1;i<=n;i++)cin>>cost[i];
    for(int i=1;i<=k;i++)
    {
        cin>>x;
        for(int j=0;j<x;j++)
        {
            cin>>idx;
            //cout<<"cost[idx] = "<<cost[idx]<<" i ="<<i<<endl;
            st[i].insert(cost[idx]);
            group[idx]=i;
        }
    }
    for(int i=0;i<m;i++)
    {
        cin>>s;
        idx=id[s];
        int gr=group[idx];
        ans+=(*st[gr].begin());
        //cout<<"idx = "<<idx<<" gr = "<<gr<<" cost = "<<(*st[gr].begin())<<endl;
    }
    cout<<ans;

  return 0;
}
