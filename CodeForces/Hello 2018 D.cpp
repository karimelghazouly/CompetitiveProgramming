#include <bits/stdc++.h>
using namespace std;
map<int,int>mapp;
int main()
{
   ios::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);
    int n,t,x,y,cur=0,ans=0;
    cin>>n>>t;
    for(int i=0;i<n;i++)
    {
        cin>>x>>y;
        if(mapp[x]==0)mapp[x]=y;
        else mapp[x]=min(mapp[x],y);
    }
    vector<int>vec;
    for( auto it=mapp.begin();it!=mapp.end();it++)vec.push_back(it->second);
    sort(vec.begin(),vec.end());
    for(int i=0;i<vec.size();i++)
    {
        if(vec[i]+cur<=t)
        {
            cout<<"vec[i] = "<<vec[i]<<endl;
            cur+=vec[i],ans++;
        }
    }
    cout<<ans<<endl;
  return 0;
}
