#include <bits/stdc++.h>
using namespace std;
#define long long ll
int main()
{
   ios::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);
    int n,mn=INT_MAX,pre=-1,ans=INT_MAX;
    cin>>n;
    int arr[n];
    for(int i=0;i<n;i++)cin>>arr[i],mn=min(mn,arr[i]);
    for(int i=0;i<n;i++)
    {
        if(arr[i]==mn)
        {
            if(pre==-1)
            {
                pre=i;
                continue;
            }
            ans=min(i-pre,ans);
            pre=i;
        }
    }
    cout<<ans;
  return 0;
}
