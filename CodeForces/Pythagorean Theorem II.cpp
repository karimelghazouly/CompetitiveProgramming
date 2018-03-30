#include <bits/stdc++.h>
using namespace std;
int main()
{
   ios::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);
    int n,cnt=0;
    vector<int>vec;
    cin>>n;
    for(int i=2;i<=n;i++)
    {
        if(sqrt(i)==floor(sqrt(i)))vec.push_back(i*i);
    }
    for(int i=1;i<=n;i++)
    {
        for(int j=0;j<vec.size();j++)
        {
            diff=vec[j]-i;
            if(diff<=n)cnt++;
        }
    }
    cout<<cnt;
  return 0;
}
