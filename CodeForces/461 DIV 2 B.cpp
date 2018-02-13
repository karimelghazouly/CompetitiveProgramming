#include <bits/stdc++.h>
using namespace std;
struct tri
{
    int x,y,z;
};
int main()
{
   ios::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);
    int n,x,c=0;
    unordered_set<int>st;
    cin>>n;
    for(int i=1;i<=n;i++)
    {
        for(int j=i+1;j<=n;j++)
        {
            x=(i^j);
            if(x<=n&&i+x>j&&i+j>x&&j+x>i)
            {
                //cout<<"i = "<<i<<" j = "<<j<<" x = "<<x<<endl;
                c++;
            }
        }
    }
    cout<<c/3<<endl;
  return 0;
}
