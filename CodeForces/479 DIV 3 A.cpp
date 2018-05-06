#include <bits/stdc++.h>
using namespace std;
int main()
{
   ios::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);
    int n,k;
    cin>>n>>k;
    while(k>0)
    {
        if(n%10>0)n--;
        else n/=10;
        k--;
    }
    cout<<n;
  return 0;
}
