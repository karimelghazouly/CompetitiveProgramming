#include <bits/stdc++.h>
using namespace std;
long long n,cap[100009],ans[100009],t[100009],curt,cur,diff,fil,idx;
int main()
{
   ios::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);
    cin>>n;
    vector<pair<long long,int> >vec;
    set<int>st;
    for(int i=0;i<n;i++)
    {
        cin>>cap[i]>>t[i];
        vec.push_back({t[i],i});
    }
    sort(vec.begin(),vec.end());
    curt=vec[0].first;
    for(int i=0;i<n;i++)
    {
        idx=vec[i].second;
        while(curt<vec[i].first&&st.size())
        {
            cur=(*st.begin());
            if(curt<t[cur])curt=t[cur];
            diff=vec[i].first-curt;
            fil=min(cap[cur],diff);
            //cout<<"t = "<<vec[i].first<<" cur = "<<cur<<" curt = "<<curt<<" diff = "<<diff<<" fil = "<<fil<<" cap = "<<cap[cur]<<endl;
            cap[cur]-=fil;
            curt+=fil;
            if(!cap[cur])
            {
                st.erase(st.begin());
                ans[cur]=curt;
            }
        }
        st.insert(idx);
    }
    while(st.size())
    {
        cur=(*st.begin());
        if(curt<t[cur])curt=t[cur];
        //cout<<"cur = "<<cur<<" cap = "<<cap[cur]<<endl;
        curt+=cap[cur];
        ans[cur]=curt;
        st.erase(st.begin());
    }
    for(int i=0;i<n;i++)cout<<ans[i]<<endl;
  return 0;
}
