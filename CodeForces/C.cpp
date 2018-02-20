#include <bits/stdc++.h>
using namespace std;
int arr[10000],sum[10000],sum2[10000],n;
int solve(int i,int j,bool d)
{
    cout<<"i = "<<i<<" j = "<<j<<" d = "<<d<<endl;
    if(j==n)return 0;
    int ret=0;
    if(i==-1&&!d)
    {
        //hagrb abd2 interva
        if(j>0&&(arr[j]!=2||arr[j-1]!=2))ret+=sum2[j-1]+solve(j,j+1,1);
        else solve(j,j+1,1);
        // aw m3mlsh haga
        ret=max(solve(-1,j+1,0),ret);
    }
    if(i!=-1)
    {
        //hagrb a2fl interval
        if(j+1<n&&(arr[j]!=1||arr[j-1]!=1))ret=max(ret,sum[j+1]+solve(-1,j+1,1))+(j-i+1);
        else ret=max(ret,solve(-1,j+1,1))+(j-i+1);
        //hagrb akml
        if(arr[j-1]!=1||arr[j]!=2)ret=max(solve(i,j+1,1),ret);
    }
    return ret;
}
int main()
{
   ios::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);
    cin>>n;
    sum[n-1]=1;
    for(int i=0;i<n;i++)cin>>arr[i];
    for(int i=n-2;i>=0;i--)
    {
        if(arr[i]<=arr[i+1])sum[i]=sum[i+1]+1;
        else sum[i]=1;
    }
    sum2[0]=1;
    for(int i=1;i<n;i++)
    {
        if(arr[i]>=arr[i-1])sum2[i]=sum2[i-1]+2;
        else sum2[i]=1;
    }
    cout<<solve(-1,0,0);
  return 0;
}
