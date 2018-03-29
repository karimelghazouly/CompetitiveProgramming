#include <bits/stdc++.h>
using namespace std;
int leftt[200009],rightt[200009],cnt[300][300][10],dist,arr[200009],ans[20],n,m,x;
int ham(int a ,int b)
{
    return __builtin_popcount(a^b);
}
int getleft(int z)
{
    int ret=0;
    for(int i=m/2;i<m;i++)
    {
        int id=i-m/2;
        if(((1<<i)&z))ret+=(1<<id);
    }
    return ret;
}
int getright(int z)
{
    int ret=0;
    for(int i=0;i<m/2;i++)
    {
        if(((1<<i)&z))ret+=(1<<i);
    }
    return ret;
}
void srch(int idx)
{
    for(int i=0;i<=(1<<((m+1)/2));i++)
    {
        for(int j=0;j<=((m+1)/2);j++)
        {
            //cout<<"i = "<<i<<" j = "<<j<<endl;
            dist=ham(i,leftt[idx])+j;
            ans[dist]+=cnt[i][rightt[idx]][j];
        }
    }
}
void insrt(int idx)
{
    for(int i=0;i<=(1<<((m+1)/2));i++)
    {
        //cout<<" i = "<<i<<" left="<<leftt[idx]<<" ham ="<<ham(i,rightt[idx])<<endl;
        cnt[leftt[idx]][i][ham(i,rightt[idx])]++;
    }
}
int main()
{
   ios::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);
    cin>>n>>m;
    for(int i=0;i<n;i++)
    {
        cin>>arr[i];
        leftt[i]=getleft(arr[i]);
        rightt[i]=getright(arr[i]);
        memset(ans,0,sizeof(ans));
        srch(i);
        for(int i=0;i<=m;i++)cout<<ans[i]<<" ";
        cout<<endl;
        insrt(i);
    }
  return 0;
}
