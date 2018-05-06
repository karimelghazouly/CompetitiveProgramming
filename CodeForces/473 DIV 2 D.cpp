#include <bits/stdc++.h>
using namespace std;
bool vis[2000009];
int main()
{
   ios::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);
    vector<int>primes;
    for(int i=2;i<=1000000;i++)
    {
        if(!notprime[i])
        {
            x=i+i; primes.push_back(i);
            while(x<=100000)
            { notprime[x]=1; x+=i; }
        }
    }
    int n,cop;
    cin>>n;
    for(int i=0;i<n;i++)
    {
        cin>>arr[i]; cop=arr[i];
        for(int j=0;j<primes.size();j++)
        {
            while(cop%primes[j]==0)
            {
                vis[primes[j]]=1;
                cop/=primes[j];
            }
        }
    }
    for(int i=2;i<=1000000;i++)
    {
        if(vis[i])continue;
        bool efks=0;
        cop=i;
        vector<int>vec;
        for(int j=0;j<primes.size();j++)
        {
            while(cop%primes[j]==0)
            {
                if(vis[primes[j]]){efks=1; break;}
                vec.push_back(primes[j]);
                cop/=primes[j];
            }
        }
        if(!efks)for(int i=0;i<vec.size();i++)vis[vec[i]]=1;
    }
  return 0;
}
