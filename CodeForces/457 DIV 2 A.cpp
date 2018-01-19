#include <bits/stdc++.h>
using namespace std;
int main()
{
   ios::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);
    int x,cnt=0,h,m,hh,mm;
    cin>>x>>h>>m;
    while(1)
    {
        if(h==0&&m<0)h=23,m+=60;
        if(m<0)h--,m+=60;
        hh=h;
        while(hh>0)
        {
            if(hh%10==7)
            {
                cout<<cnt;
                return 0;
            }
            hh/=10;
        }
        mm=m;
        while(mm>0)
        {
            if(mm%10==7)
            {
                cout<<cnt;
                return 0;
            }
            mm/=10;
        }
        m-=x;
        cnt++;
    }
  return 0;
}
