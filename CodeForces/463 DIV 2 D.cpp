#include <bits/stdc++.h>
using namespace std;
long long par[400009][21],sum[400009][21],w[400009];
int getpar(int node,int we)
{
    for(int i=20;i>=0;i--)
    {
        if(par[node][i]!=0&&we>w[par[node][i]])
        {
            //cout<<"par = "<<par[node][i]<<" w = "<<w[par[node][i]]<<endl;
            node=par[node][i];
        }
    }
    //cout<<w[par[node][0]]<<" "<<node<<endl;
    if(w[node]>=we)
        return node;
    if(w[par[node][0]]>=we)
        return par[node][0];
    else return 0;
}
void buildmore(int node)
{
    for(int i=1;i<=20;i++)
    {
        par[node][i]=par[par[node][i-1]][i-1];
        sum[node][i]=sum[par[node][i-1]][i-1]+sum[node][i-1];
        //cout<<"node = "<<node<<" i = "<<i<<" sum = "<<sum[node][i]<<endl;
    }
}
int getsum(int node,long long limit)
{
    int ret=0;
    for(int i=20;i>=0;i--)
    {
        //cout<<sum[node][i]<<endl;
        if(par[node][i]!=0&&limit>=sum[node][i])
        {
           // cout<<"node = "<<node;
            limit-=sum[node][i];
            node=par[node][i];
            ret += (1 << i);
           // cout<<" new node = "<<node<<" ret = "<<ret<<" limit = "<<limit<<endl;
        }
    }
    return ret;
}
int main()
{
   ios::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    long long last=0,q,x,pr,a,t,b,idx=2;
    cin>>q;
    while(q--)
    {
        cin>>t>>a>>b;
        a=(a^last); b=(b^last);
        if(t==1)
        {
            //cout<<"A = "<<a<<" b = "<<b<<endl;
            pr=getpar(a,b);
           // cout<<"pr = "<<pr<<endl;
            par[idx][0]=pr;
            sum[idx][0]=w[pr];
            w[idx]=b;
            buildmore(idx++);
        }
        else
        {
            //cout<<"w[a] = "<<w[a]<<" b = "<<b<<endl;
            if(w[a]>b)cout<<0<<endl,last=0;
            else
            {
                last=getsum(a,b-w[a]);
                last++;
                cout<<last<<endl;
            }
        }
    }

  return 0;
}
