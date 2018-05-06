#include <bits/stdc++.h>
using namespace std;
bool vis[1000];
long long arr[1000],n;
vector<int>listt[1000];
void solve(int idx,vector<int>vec)
{
    //cout<<"sz = "<<vec.size()<<" n -1 = "<<n-1<<endl;
    if(vec.size()==n-1)
    {
        //cout<<"hena"<<endl;
        for(int i=0;i<vec.size();i++)
                cout<<arr[vec[i]]<<" ";
        cout<<arr[idx]<<endl;
        exit(0);
    }
    vis[idx]=1;
    for(int i=0;i<listt[idx].size();i++)
    {
        int nxt=listt[idx][i];
        //cout<<"idx = "<<idx<<" nxt = "<<nxt<<endl;
        if(!vis[nxt])
        {
            vec.push_back(idx);
            solve(nxt,vec);
            vec.pop_back();
        }
    }
    vis[idx]=0;
}
int main()
{
   ios::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);
    cin>>n;
    for(int i=0;i<n;i++)cin>>arr[i];
    for(int i=0;i<n;i++)
    {
        for(int j=0;j<n;j++)
        {
            if(arr[j]==arr[i]*2||(arr[i]%3==0&&arr[j]==arr[i]/3))
                listt[i].push_back(j);
        }

    }
    vector<int>s;
    for(int i=0;i<n;i++)
    {
        solve(i,s);
    }
  return 0;
}
