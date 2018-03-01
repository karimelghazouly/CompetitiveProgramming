#include <bits/stdc++.h>
using namespace std;
bool arr[1000009];
int main()
{
   ios::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);
    int k,n,m,sz=0,cnt=0,ans=0,diff,x; cin>>n>>m>>k;
    for(int i=0;i<n;i++)
    {
        cin>>x;
        arr[x]=1;
    }
    for(int i=1;i<=1000000;i++)
    {
        cnt+=arr[i];
        if(cnt==k)ans++,cnt--,arr[i]=0;
        if(i>=m)cnt-=arr[i-m+1];
    }
    cout<<ans;
  return 0;
}
