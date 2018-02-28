#include <bits/stdc++.h>
using namespace std;
int main()
{
    bool f;
    int p,y;
    cin>>p>>y;
    for(int i=y;i>p;i--)
    {
        f=0;
        for(int j=2;j<=min((int)sqrt(i),p);j++)
        {
            if(i%j==0)
            {
                f=1;
                break;
            }
        }
        if(!f)
        {
            cout<<i<<endl;
            return 0;
        }
    }
    cout<<"-1";
  return 0;
}
