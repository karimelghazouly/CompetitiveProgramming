#include <bits/stdc++.h>
using namespace std;
int arr[1000000];
int main()
{
   ios::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);
    int n,k;
    cin>>n>>k;
    for(int i=0;i<n;i++)cin>>arr[i];
    sort(arr,arr+n);
    if(k==0)
    {
        if(arr[0]==1)cout<<"-1";
        else cout<<"1";
        return 0;
    }
    if(k==n||arr[k-1]!=arr[k])cout<<arr[k-1]<<endl;
    else cout<<"-1";
  return 0;
}
