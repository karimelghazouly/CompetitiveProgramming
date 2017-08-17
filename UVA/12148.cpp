#include <bits/stdc++.h>
using namespace std;
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);
    int month[12]={31,28,31,30,31,30,31,31,30,31,30,31},n;
    while(cin>>n)
    {
        if(n==0)break;
        int arr[n][4],nxtd,nxtm,nxty,c=0,ans=0;
        for(int i=0;i<n;i++)for(int j=0;j<4;j++)cin>>arr[i][j];
        for(int i=0;i<n;i++)
        {
            if(arr[i][1]==2)
            {
                int m=month[1];
                if(arr[i][2]%4==0&&arr[i][2]%100!=0||(arr[i][2]%400==0))m++;
                if(arr[i][0]==m)nxtd=1,nxtm=3,nxty=arr[i][2];
                else nxtd=arr[i][0]+1,nxtm=arr[i][1],nxty=arr[i][2];
            }
            else
            {
                if(arr[i][0]==month[arr[i][1]-1])
                {
                   if(arr[i][1]==12)nxtd=1,nxtm=1,nxty=arr[i][2]+1;
                   else nxtd=1,nxtm=arr[i][1]+1,nxty=arr[i][2];
                }
                else nxtd=arr[i][0]+1,nxtm=arr[i][1],nxty=arr[i][2];
            }
            if(arr[i+1][0]==nxtd&&arr[i+1][1]==nxtm&&arr[i+1][2]==nxty)c++,ans+=arr[i+1][3]-arr[i][3];
        }
        cout<<c<<" "<<ans<<endl;
    }
    return 0;
}
