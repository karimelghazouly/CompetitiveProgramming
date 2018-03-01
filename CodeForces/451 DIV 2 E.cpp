#include <bits/stdc++.h>
using namespace std;
long long arr[300009];
map<long long,bool>mapp;
int main()
{
   ios::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);
    long long n,l,r,ins=0,rem=0,z=0;
    cin>>n;
    vector<long long>vec;
    for(long long i=0;i<=100000;i++)
    {
        vec.push_back(i*i);
        mapp[i*i]=1;
    }
    for(long long i=0;i<n;i++)cin>>arr[i];
    vector<pair<long long,pair<long long, long long > > >v;
    for(long long i=0;i<n;i++)
    {
        auto it=(lower_bound(vec.begin(),vec.end(),arr[i])-vec.begin());
        r=(long long)it; l=r-1; l = max(z,l);
        //cout<<"r = "<<r<<" l = "<<l<<endl;
        //cout<<arr[i]-vec[l]<<" "<<vec[r]-arr[i]<<" vecl = "<<vec[l]<<" vec[r] = "<<vec[r]<<endl;
        if(arr[i]-vec[l]<=vec[r]-arr[i])v.push_back({arr[i]-vec[l],{l,arr[i]}});
        else v.push_back({vec[r]-arr[i],{r,arr[i]}});
    }

    sort(v.begin(),v.end());
    for(long long i=0;i<n/2;i++)
    {
        long long idx=v[i].second.first;
        long long a=v[i].second.second;
        long long diff=v[i].first;
        if(vec[idx]>a)ins+=diff;
        else rem+=diff;
    }
    for(long long i=n/2;i<n;i++)
    {
        long long a=v[i].second.second;

        while(mapp[a]){ins++;a++;}
    }
    cout<<rem+ins<<endl;
  return 0;
}

