#include <bits/stdc++.h>
using namespace std;
int main()
{
   ios::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);
    int n,ans=-1,l=1,r=1e6,mid=(1e6)/2;
    //cout<<"mid = "<<mid-1<<endl;
    cin>>n;
    int arr[n];
    for(int i=0;i<n;i++)
    {
        cin>>arr[i];
        if(arr[i]<=mid)ans=max(arr[i]-l,ans);
        if(arr[i]>mid)ans=max(r-arr[i],ans);
    }
    cout<<ans;
  return 0;
}
