#include <bits/stdc++.h>
using namespace std;
int main()
{
   ios::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);
    int n,o,z,mini,maxi,lastl=-1e9,lastr=1e9; cin>>n;
    int arr[n]; for(int i=0;i<n;i++)cin>>arr[i];
    string s; cin>>s;
    for(int i=4;i<n;i++)
    {
        mini=1e9; maxi=-1e9; z=o=0;
        for(int j=i-1;j>=i-4;j--)
        {
            if(s[j]=='0')z++;
            else o++;
        }
        for(int j=i;j>=i-4;j--)
        {
            mini=min(mini,arr[j]);
            maxi=max(maxi,arr[j]);
        }
        if(s[i]=='0')
        {
           // cout<<"o = "<<o<<endl;
            if(o==4)lastr=min(mini-1,lastr);
        }
        else
        {
           // cout<<"Z = "<<z<<endl;
            if(z==4)lastl=max(maxi+1,lastl);
        }
       // cout<<"lastl = "<<lastl<<" lastr = "<<lastr<<endl;
    }
    cout<<lastl<<" "<<lastr;
  return 0;
}
