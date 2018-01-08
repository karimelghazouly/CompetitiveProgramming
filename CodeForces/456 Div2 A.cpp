#include <bits/stdc++.h>
using namespace std;
int main()
{
   ios::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);
    long long yel,blue,neededy=0,neededb=0,x,y,z,zer=0;
    cin>>yel>>blue>>x>>y>>z;
    neededy+=(x*2)+y; neededy=max(zer,neededy-yel);
    neededb+=y+(z*3); neededb=max(zer,neededb-blue);
    //cout<<"neededb = "<<neededb<<" neededy = "<<neededy<<endl;
    cout<<neededb+neededy<<endl;

  return 0;
}
