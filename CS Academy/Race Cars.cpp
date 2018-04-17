#include <bits/stdc++.h>
using namespace std;
int ans1[100009],ans2[100009],last[100009],idx,ans;
double d[100009],v[100009];
int main()
{
   ios::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);
    float n,x,y;
    vector<pair<double,int> >vec1,vec2;
    cin>>n>>x>>y;
    for(int i=0;i<n;i++)
    {
        cin>>d[i]>>v[i];
        vec1.push_back({(d[i]/(v[i]-y)),i});
        vec2.push_back({d[i]/v[i],i});
    }
    sort(vec1.begin(),vec1.end());
    sort(vec2.begin(),vec2.end());
    //for(int i=0;i<vec2.size();i++)cout<<vec2[i].first<<" "<<vec2[i].second<<" ";
    //cout<<endl;
    for(int i=0;i<vec2.size();i++)
    {
        int ans=lower_bound(vec2.begin(),vec2.end(),make_pair(d[i]/(v[i]+x),i))-vec2.begin();
        //cout<<"i = "<<i<<" ans = "<<ans<<" d = "<<d[i]/(v[i]+x)<<endl;
        ans2[i]=ans+1;
        ans=lower_bound(vec1.begin(),vec1.end(),make_pair(d[i]/v[i],i))-vec1.begin();
        ans1[i]=ans+1;
    }
    for(int i=0;i<n;i++)
    {
        //cout<<ans1[i]<<" "<<ans2[i]<<endl;
        cout<<min(ans1[i],ans2[i])<<endl;
    }
  return 0;
}
