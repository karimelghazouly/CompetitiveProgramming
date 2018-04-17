#include <bits/stdc++.h>
using namespace std;
int main()
{
   ios::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);
    int a ,l , h,legs,horns,rest;
    cin>>a>>l>>h;
    //i chickens  j rams rest unicorns
    for(int i=0;i<=a;i++)
    {
        for(int j=0;j<=a;j++)
        {
            rest=a-(i+j);
            legs=i*2+j*4+rest*4;
            horns=j*2+rest;
            if(legs==l&&horns==h)
            {
                cout<<rest<<endl;
                return 0 ;
            }
        }
    }
  return 0;
}
