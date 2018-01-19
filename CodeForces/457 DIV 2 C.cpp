#include <bits/stdc++.h>
using namespace std;
bool notprime[1000009];
int main()
{
   ios::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);
    int x;
    vector<int>vec;
    for(int i=2;i<=1e6;i++)
    {
        if(!notprime[i])
        {
            x=i; vec.push_back(x);
            while(x<=1e6){notprime[x]=1; x+=i;}
        }
    }
    int n,m,sp,sum;
    cin>>n>>m;
    vector<pair<int,pair<int,int> > >v;
    for(int i=1;i<n-1;i++)v.push_back({i,{i+1,1}});
    sp=(n-2); sum=(n-2);
    for(int i=0;i<vec.size();i++)
    {
        if(vec[i]>sp)
        {
            v.push_back({n-1,{n,vec[i]-sp}});
            sp=sum=vec[i];
            break;
        }
    }
    m-=(n-1);
    cout<<sp<<" "<<sum<<endl;
    for(int i=0;i<v.size();i++)cout<<v[i].first<<" "<<v[i].second.first<<" "<<v[i].second.second<<endl;
    for(int i=1;i<=n&&m>0;i++)
    {
        for(int j=i+2;j<=n&&m>0;j++)cout<<i<<" "<<j<<" 100000000"<<endl,m--;
    }

    return 0;
}
