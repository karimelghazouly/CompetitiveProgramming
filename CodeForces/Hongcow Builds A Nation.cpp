#include <bits/stdc++.h>
using namespace std;
map<int,bool>listt[1002];
vector<int>cnt[10000];
bool vis[100002];
int others[10000],self[10000],n,m,k,x,y,ans,nc,mx,b,o,s,c,p[100002],sum;
int parent(int x)
{
    if(p[x]==x)return x;
    return parent(p[x]);
}
void connect(int x,int y)
{
    int xroot=parent(x);
    int yroot=parent(y);
    if(xroot>n)p[yroot]=xroot;
    else p[xroot]=yroot;
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);
    cin>>n>>m>>k;
    vector<int>vec;
    vector<vector<int> >all;
    for(int i=1;i<=100000;i++)p[i]=i;
    for(int i=0;i<k;i++)
    {
        cin>>x;
        p[x]=x+n;
    }
    for(int i=0;i<m;i++)
    {
        cin>>x>>y;
        listt[x][y]=1;
        listt[y][x]=1;
        connect(x,y);
    }
    //------------------------
    for(int i=1;i<=n;i++)
    {
        if(parent(i)<=n)vec.push_back(i),vis[i]=1;
        if(parent(i)>n)cnt[parent(i)-n].push_back(i);
    }
    for(int i=1;i<=n;i++)
    {
        if(cnt[i].size()>0)all.push_back(cnt[i]);
    }
    for(int i=0;i<all.size();i++)
    {
        o=0;
        for(int j=0;j<all[i].size();j++)
        {
            for(int z=0;z<vec.size();z++)
            {
                if(vec[z]==all[i][j]||listt[vec[z]][all[i][j]])continue;
                o++;
            }
        }
        others[i]=o;
        //cout<<"i = "<<all[i][0]<<" o = "<<o<<endl;
    }
    for(int i=0;i<vec.size();i++)
    {
        for(int j=0;j<vec.size();j++)
        {
            if(vec[i]==vec[j]||listt[vec[i]][vec[j]])continue;
            listt[vec[i]][vec[j]]=listt[vec[j]][vec[i]]=1;
            c++;
        }
    }
    for(int i=0;i<all.size();i++)
    {
        s=0;
        for(int j=0;j<all[i].size();j++)
        {
            for(int z=0;z<all[i].size();z++)
            {
                if(all[i][z]==all[i][j]||listt[all[i][j]][all[i][z]])continue;
                s++;
                listt[all[i][j]][all[i][z]]=1;
                listt[all[i][z]][all[i][j]]=1;
            }
        }
        //cout<<"i = "<<all[i][0]<<" s = "<<s<<" c = "<<c<<endl;
        sum+=s;
    }
    for(int i=0;i<all.size();i++)ans=max(ans,sum+c+others[i]);
    cout<<ans;
    return 0;
}
