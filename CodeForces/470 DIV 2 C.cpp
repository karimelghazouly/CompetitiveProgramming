#include <bits/stdc++.h>
using namespace std;
long long acc[100009],ans1[100009],ans2[100009],balls[100009],temp[100009],n,x,b,e,mid,diff,cnt;
int main()
{
   ios::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);
    cin>>n;
    for(int i=1;i<=n;i++)cin>>balls[i];
    for(int i=1;i<=n;i++)
    {
        cin>>x;
        temp[i]=x;
        acc[i]=x;
        acc[i]+=acc[i-1];
    }
    for(int i=1;i<=n;i++)
    {
        b=i; e=n;
        while(b<=e)
        {
            mid=(b+e)/2;
            //cout<<"b = "<<b<<" e = "<<e<<" mid = "<<mid<<" acc = "<<acc[mid]-acc[i-1]<<endl;
            if(acc[mid]-acc[i-1]>balls[i])e=mid-1;
            else b=mid+1;
        }
        diff=balls[i]-(acc[b-1]-acc[i-1]);
        ans1[i]++; ans1[b]--; ans2[b]+=diff;
        //cout<<"i = "<<i<<" b = "<<b<<" diff = "<<diff<<endl;
    }
    for(int i=1;i<=n;i++)
    {
        cnt+=ans1[i];
        cout<<cnt*temp[i]+ans2[i]<<" ";
    }
  return 0;
}
