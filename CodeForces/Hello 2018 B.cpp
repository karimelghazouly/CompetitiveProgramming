#include <bits/stdc++.h>
using namespace std;
vector<int>listt[100000];
bool parent[100000];
int main()
{
   ios::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);
    int n,c=0,x;
    cin>>n;
    for(int i=1;i<=n-1;i++)
    {
        cin>>x;
        listt[x].push_back((i+1));

    }
    for(int i=1;i<=n;i++)
    {
        c=0;
        if(listt[i].size()==0)continue;
        for(int j=0;j<listt[i].size();j++)
        {
            int u=listt[i][j];
            if(listt[u].size()==0)c++;
        }
        //cout<<"i = "<<i<<" c = "<<c<<endl;
        if(c<3)
        {
            cout<<"No";
            return 0;
        }
    }
    cout<<"Yes";
  return 0;
}
