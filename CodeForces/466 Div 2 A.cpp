#include <bits/stdc++.h>
using namespace std;
int main()
{
   ios::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);
    int n,d,ans=1e9;
    cin>>n>>d;
    int arr[n]; for(int i=0;i<n;i++)cin>>arr[i];
    sort(arr,arr+n);
    for(int i=0;i<n;i++)
    {
      for(int j=n-1;j>=i;j--)
        {
            if(arr[j]-arr[i]<=d)
            {

                ans=min(i+(n-j-1),ans);
            }
        }
    }
    cout<<ans;
  return 0;
}
