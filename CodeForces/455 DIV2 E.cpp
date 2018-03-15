#include <bits/stdc++.h>
using namespace std;
int label[100009],in[100009],ans,n,m,x,y;
vector<int>listt[100009];
bool proc;
int main()
{
   ios::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);
    cin>>n>>m;
    for(int i=0;i<n;i++)cin>>label[i];
    for(int i=0;i<m;i++)
    {
        cin>>x>>y;
        in[x]++;
        listt[y].push_back(x);
    }
    queue<int>pq[2];
    for(int i=0;i<n;i++)
    {
        if(in[i]==0)pq[label[i]].push(i);
    }
    while(pq[0].size()||pq[1].size())
    {
        if(proc==0&&pq[0].size()==0)proc=1,ans++;
        else if(proc==1&&pq[1].size()==0)proc=0;
        x=pq[proc].front(); pq[proc].pop();
        //cout<<"x = "<<x<<" proc = "<<proc<<endl;
        for(int i=0;i<listt[x].size();i++)
        {
            y=listt[x][i];
            in[y]--;
            if(in[y]==0)pq[label[y]].push(y);
        }
    }
    cout<<ans<<endl;
  return 0;
}
