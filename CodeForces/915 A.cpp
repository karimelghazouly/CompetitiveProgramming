#include <bits/stdc++.h>
using namespace std;
int main()
{
   ios::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);
    int n,k,mx=-1,ans=0,x;
    cin>>n>>k;
    int arr[n];
    for(int i=0;i<n;i++)
    {
        cin>>x;
        if(k%x==0&&x>mx)
        {
            ans=k/x;
            mx=x;
        }
    }
    cout<<ans;
  return 0;
}
