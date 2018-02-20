#include <bits/stdc++.h>
using namespace std;
int main()
{
   ios::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);
    long long n,m,neg=0,mx,mn=1e18;
    cin>>n>>m;
    long long arr[n],arr2[m];
    for(int i=0;i<n;i++)cin>>arr[i];
    for(int i=0;i<m;i++)cin>>arr2[i];
    for(int i=0;i<n;i++)
    {
        mx=-(1e18);
        for(int z=0;z<n;z++)
        {
            if(z==i)continue;
            //mx=-(1e18);
            for(int j=0;j<m;j++)mx=max(arr2[j]*arr[z],mx);
            //cout<<"mx = "<<mx<<" mn = "<<mn<<" i = "<<i<<" z = "<<z<<endl;
        }
        mn=min(mx,mn);
    }
    cout<<mn<<endl;
  return 0;
}
