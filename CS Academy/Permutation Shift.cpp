#include <bits/stdc++.h>
using namespace std;
int main()
{
   ios::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);
    int n ,cnt,ans=-1;
    cin>>n;
    vector<int>vec(n);
    for(int i=0;i<n;i++)cin>>vec[i];
    for(int i=0;i<n;i++)
    {
        int x=vec.back();
        vec.pop_back(); cnt=0;
        vec.insert(vec.begin(),x);
        for(int j=0;j<n;j++)
        {
            if(vec[j]==j+1)cnt++;
        }
        ans=max(ans,cnt);
    }
    cout<<ans;
  return 0;
}
