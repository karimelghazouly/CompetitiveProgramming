#include <bits/stdc++.h>
using namespace std;
int main()
{
   ios::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);
    long long n,m;
    cin>>n>>m;
    if(n>=32)cout<<m;
    else
    {
        long long p=1;
        for(int i=1;i<=n;i++)p*=2;
        cout<<m%p;
    }
  return 0;
}
