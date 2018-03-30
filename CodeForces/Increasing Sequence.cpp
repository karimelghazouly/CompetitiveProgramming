#include <bits/stdc++.h>
using namespace std;
int main()
{
   ios::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);
    int n,cnt=0;
    double d;
    cin>>n>>d;
    int arr[n];
    for(int i=0;i<n;i++)cin>>arr[i];
    for(int i=1;i<n;i++)
    {
        if(arr[i]<=arr[i-1])
        {
            double diff=abs(arr[i]-arr[i-1]-1);
            cnt+=ceil(diff/d);
            arr[i]+=d*ceil(diff/d);
            //cout<<"i = "<<i<<" diff = "<<diff<<" cnt = "<<cnt<<endl;
        }
    }
    cout<<cnt<<endl;
  return 0;
}
