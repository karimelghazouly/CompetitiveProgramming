#include <bits/stdc++.h>
using namespace std;
int main()
{
   ios::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);
    long long n,ans=0;
    cin>>n;
    vector<int>vec(n);
    for(int i=0;i<n;i++)cin>>vec[i];
    sort(vec.rbegin(),vec.rend());
    for(int i=2;i<=n;i=i+2)ans=max(ans,ans+vec[i-1]+vec[i-2]);
    cout<<ans;

  return 0;
}
