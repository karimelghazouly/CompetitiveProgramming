#include <bits/stdc++.h>
using namespace std;
#define long long ll
int main()
{
   ios::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);
    int n,a,b,ans=INT_MIN,mn;
    cin>>n>>a>>b;
    for(int i=1;i<n;i++)
    {
        mn=INT_MAX;
        int j=n-i;
        mn=min(a/i,b/j);
        //cout<<" i = "<<i<<" j = "<<j<<" a/i = "<<a/i<<" b/j = "<<b/j<<" mn  = "<<mn<<endl;
        ans=max(ans,mn);
    }
    cout<<ans;

  return 0;
}
