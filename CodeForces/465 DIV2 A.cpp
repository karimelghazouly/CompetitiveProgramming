#include <bits/stdc++.h>
using namespace std;
int main()
{
   ios::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);
    int n,c=0;
    cin>>n;
    for(int i=2;i<=n;i++)
    {
        if(n%i==0)c++;
    }
    cout<<c<<endl;
  return 0;
}
