#include <bits/stdc++.h>
using namespace std;
int n,m,id,a,pre,b,node,vis[405],ta=1,comp,f;
double ans=1e9,w,cost[405],h[405],all;
vector<int>listt[405],nodes[405];

struct jun{
    int x,y,z,k;
}arr[405];

double dist(int i , int j)
{
    return sqrt(((arr[i].x-arr[j].x)*(arr[i].x-arr[j].x))+((arr[i].y-arr[j].y)*(arr[i].y-arr[j].y))+((arr[i].z-arr[j].z)*(arr[i].z-arr[j].z)));
}

void dfs(int node)
{
    //cout<<"node = "<<node<<" id = " <<id<<" pre = "<<pre<<" z = "<<arr[node].z<<endl;
    vis[node]=id;
    h[id]+=arr[node].k;
    all+=arr[node].k;
    if(arr[node].k>0)nodes[id].push_back(node)/*,cout<<node<<" "*/;
    for(int i=0;i<listt[node].size();i++)
    {
        int nxt=listt[node][i];
        //cout<<"node = "<<node<<" nxt = "<<nxt<<" nxt .z = "<<arr[nxt].z<<endl;
        if(!vis[nxt]&&arr[nxt].z<=pre)
        {
            //cout<<"called"<<endl;
            dfs(nxt);
        }
    }
}

int main()
{
   ios::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);
    while(cin>>n>>m)
    {
        vector<int>heights; ans=1e10;
        for(int i=0;i<405;i++)listt[i].clear();
        for(int i=1;i<=n;i++)
        {
            cin>>arr[i].x>>arr[i].y>>arr[i].z>>arr[i].k;
            heights.push_back(arr[i].z);
        }
        for(int i=0;i<m;i++)
        {
            cin>>a>>b;
            listt[a].push_back(b);
            listt[b].push_back(a);
        }
        sort(heights.begin(),heights.end());
        //cout<<"heights . size = "<<heights.size()<<endl;
        for(int i=0;i<heights.size();i++)
        {
            pre=heights[i]; id=1;
            if(pre<arr[n].z||pre<arr[1].z)continue;
            memset(vis,0,sizeof(vis)); all=0;
            for(int i=0;i<405;i++)cost[i]=1e9,h[i]=0,nodes[i].clear();
            //cout<<"pre = "<<pre<<endl;
            //cout<<"pre = "<<pre<<" pushed = ";
            for(int i=1;i<=n;i++)
            {
                //cout<<"i = "<<i<<" vis[i] = "<<vis[i]<<" arr.z = "<<arr[i].z<<" pre = "<<pre<<endl;
                if(!vis[i]&&arr[i].z<=pre)
                {
                    dfs(i);
                    id++;
                }
            }
            if(vis[1]==vis[n]&&vis[1]!=0&&vis[n]!=0)
            {
                ans=min(ans,h[vis[1]]/2);
                continue;
            }
            //cout<<endl;
            set<pair<double,int> >st;
            st.insert({0,vis[1]});
            while(st.size())
            {
                w=(*st.begin()).first;
                comp=(*st.begin()).second;
                st.erase(st.begin());
                if(comp==vis[n])
                {
                    ans=min(ans,w+(h[vis[1]]-1)*0.5);
                    continue;
                }
                for(int i=0;i<nodes[comp].size();i++)
                {
                    int cur=nodes[comp][i];
                    for(int j=1;j<id;j++)
                    {
                        f=2;
                        if((h[j]<2&&j!=vis[n])||comp==j)continue;
                        if(vis[n]==j)f=1;
                        for(int z=0;z<nodes[j].size();z++)
                        {
                            //cout<<"pre "<<pre<<" comp = "<<comp<<" j = "<<j<<" node = "<<nodes[j][z]<<" cost = "<<dist(cur,nodes[j][z])+w+(h[j]-f)*0.5<<endl;
                            if(dist(cur,nodes[j][z])+w+(h[j]-f)*0.5<cost[j])
                            {
                                if(st.find({cost[j],j})!=st.end())st.erase({cost[j],j});
                                cost[j]=dist(cur,nodes[j][z])+w+(h[j]-f)*0.5;
                                st.insert({cost[j],j});
                            }
                        }
                    }
                }

            }
        }
        cout<<"Case "<<ta<<": ";
        if(ans!=1e10)cout<<setprecision(4)<<fixed<<ans<<endl;
        else cout<<"impossible"<<endl;
        ta++;
    }
  return 0;
}
