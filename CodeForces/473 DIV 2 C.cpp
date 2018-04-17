#include <bits/stdc++.h>
using namespace std;
int main()
{
   ios::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);
    int n,l=2,cnt=1,idx=3;
    cin>>n;
    if(n>5)
    {
        cout<<"1 2"<<endl;
        while(cnt<n-1)
        {
            cout<<"2 "<<idx<<endl;
            idx++; cnt++;
            if(cnt==n-1)break;
            cout<<"1 "<<idx<<endl;
            idx++; cnt++;
        }
    }
    else cout<<"-1"<<endl;
    idx=1;
    for(int i=0;i<n-1;i++)
    {
        cout<<"1 "<<l<<endl;
        l++;
    }
  return 0;
}
