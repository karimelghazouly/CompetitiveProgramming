#include <bits/stdc++.h>
using namespace std;
int main()
{
   ios::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);
    long long n,k,x,ans=1e18,idx=1,cnt=0;
    cin>>n>>k;
    for(int i=0;i<k;i++)
    {
        cin>>x;
        if(n!=0&&n%x<ans)
        {
            ans=n%x;
            idx=i+1;
            cnt=n/x;
        }
    }
    cout<<idx<<" "<<cnt<<endl;
  return 0;
}
