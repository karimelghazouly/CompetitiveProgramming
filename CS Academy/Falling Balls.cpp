#include <bits/stdc++.h>
using namespace std;
int balls[100006],leftt[100006],rightt[100006],memo[100006][2],diff1,diff2,highest[100006],x1[100006],x2[100006],y[100006],n,m,idx,h,x;
vector<int>acc[100006],done[100006];
set<pair<int,int> >st;
int main()
{
   //ios::sync_with_stdio(false);
    //cin.tie(0); cout.tie(0);
    //cin>>n>>m;
    scanf("%d%d",&n,&m);
    memset(highest,-1,sizeof(highest));
    memset(leftt,-1,sizeof(leftt));
    memset(rightt,-1,sizeof(rightt));
    memset(memo,-1,sizeof(memo));
    for(int i=0;i<n;i++)
    {
        //cin>>x1[i]>>x2[i]>>y[i];
        scanf("%d%d%d",&x1[i],&x2[i],&y[i]);
        acc[x1[i]].push_back(i);
        done[x2[i]].push_back(i);
    }
    for(int i=0;i<=100000;i++)
    {
        for(int j=0;j<acc[i].size();j++)
        {
            idx=acc[i][j];
            h=y[idx];
            auto it = lower_bound(st.begin(),st.end(),pair<int,int>{-h,-1});
            if((*it).first==-h)it++;
            if(it!=st.end())leftt[idx]=(*it).second;
            st.insert({-h,idx});
        }
        if(st.size()>0)highest[i]=(*st.begin()).second;
        for(int j=0;j<done[i].size();j++)
        {
            idx=done[i][j];
            h=y[idx];
            auto it = lower_bound(st.begin(),st.end(),pair<int,int>{-h,-1});
            if((*it).second==idx||(*it).first==-h)it++;
            if(it!=st.end())rightt[idx]=(*it).second;
            st.erase({-h,idx});
        }
    }
    for(int i=0;i<m;i++)
    {
        //cin>>x;
        scanf("%d",&x);
        //cout<<"x = "<<x<<endl;
        idx=highest[x];
        vector<pair<int,int> >vec;
        while(idx!=-1)
        {
            //cout<<"idx = "<<idx<<" x = "<<x;
            diff1=abs(x1[idx]-x);
            diff2=abs(x2[idx]-x);
            if(diff1<=diff2)
            {
                if(memo[idx][0]!=-1)
                {
                    //cout<<" memo left = "<<memo[idx][0]<<endl;
                    x=memo[idx][0];
                    break;
                }
                vec.push_back({idx,0});
                x=x1[idx];
                idx=leftt[idx];
                //cout<<" left "<<endl;
            }
            else
            {
                if(memo[idx][1]!=-1)
                {
                    //cout<<"memo right = "<<memo[idx][1]<<endl;
                    x=memo[idx][1];
                    break;
                }
                vec.push_back({idx,1});
                x=x2[idx];
                idx=rightt[idx];
                //cout<<" right"<<endl;
            }

        }
        for(int i=0;i<vec.size();i++)memo[vec[i].first][vec[i].second]=x;
        printf("%d\n",x);
    }
  return 0;
}
