#include <bits/stdc++.h>
using namespace std;
long long arr[10000009],cnt[10000009];
int vis[10000009];
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);
    int n; cin>>n;
    long long x,c=0,temp,ans=INT_MAX;
    for(int i=1;i<=n;i++)
    {
        cin>>temp;
        c=0;
        int c2=0;
        x=temp;
        while(x>0)
        {
            c2=0;
            x=temp;
            //cout<<"x bara = "<<x<<endl;
            while(x<=1e7)
            {
                if(vis[x]==i)break;
                //cout<<"x gowa = "<<x<<" c = "<<c<<" c2 = "<<c2<<endl;
                cnt[x]++;
                arr[x]+=c+c2;
                vis[x]=i;
                c2++; x*=2;
            }
            vis[temp]=i;
            temp/=2; c++;
        }
        //cout<<endl<<endl<<endl;
    }
    //cout<<cnt[8]<<" "<<arr[8]<<endl;
    for(int i=0;i<=10000000;i++)
    {
        if(cnt[i]==n)ans=min(ans,arr[i]);
    }
    cout<<ans;
    return 0;
}
