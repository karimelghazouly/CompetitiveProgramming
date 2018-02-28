#include <bits/stdc++.h>
using namespace std;
int main()
{
   ios::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);
    int n,x,y,mx=-1,ans=0;
    cin>>n;
    vector<pair<int,int> > vec;
    for(int i=0;i<n;i++)
    {
        cin>>x>>y;
        vec.push_back({x,y});
    }
    sort(vec.begin(),vec.end());
    for(int i=0;i<vec.size();i++)
    {
        x=vec[i].first;
        y=vec[i].second;
        if(y<mx)ans++;
        else mx=y;
    }
    cout<<ans;
  return 0;
}
