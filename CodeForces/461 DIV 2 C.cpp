#include <bits/stdc++.h>
using namespace std;
int main()
{
   ios::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);
    long long n,k,b,e,m,y;
    cin>>n>>k;
    if(n<=k&&n!=1){cout<<"No"<<endl; return 0;}
    if(k<=100000)
    {
        bool arr[100001]={0};
        for(int i=1;i<=k;i++)
        {
            if(arr[n%i])
            {
                cout<<"No";
                return 0;
            }
            arr[(n%i)]=1;
        }
        cout<<"Yes"<<endl;
    }
    else cout<<"No"<<endl;
  return 0;
}
