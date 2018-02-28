#include <bits/stdc++.h>
using namespace std;
int main()
{
   ios::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);
    int n,ans=-1;
    cin>>n;
    int arr[n],sum[n]; sum[n-1]=1;
    for(int i=0;i<n;i++)cin>>arr[i];
    for(int i=n-2;i>=0;i++)
    {
        if(arr[i]<=arr[i+1])sum[i]=sum[i+1]+1;
        else sum[i]=1;
    }
    for(int i=0;i<n;i++)
    {
        int cnt=1;
        vector<int>temp;
        temp.push_back(arr[i]);
        if(arr[i]==1)arr[i]=2;
        else arr[i]=1;
        //-----------------
        for(int j=i-1;j>=0;j--)
        {
            if(arr[j]<=arr[j+1])cnt++;
            else break;
        }
        //--------------------
        for(int j=i+1;j<n;j++)
        {
            if(j+1<n&&arr[j]<=arr[j+1])mx=max(mx,cnt+sum[j+1])
            temp.push_back(arr[j]);
            if(arr[j]==1)arr[j]=2;
            else arr[j]=1;
            if(j+1<n&&arr[j]<=arr[j+1])mx=max(mx,cnt+sum[j+1])
            //cout<<"Arr[j] = "<<arr[j]<<" j = "<<j<<endl;
            if(arr[j]>=arr[j-1])cnt++;
            else break;
        }
        for(int j=0;j<temp.size();j++)arr[i+j]=temp[j];
       // cout<<"cnt all = "<<cnt<<endl;
        ans=max(cnt,ans);
    }
    cout<<ans<<endl;
  return 0;
}
