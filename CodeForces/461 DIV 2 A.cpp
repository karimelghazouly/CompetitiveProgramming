#include <bits/stdc++.h>
using namespace std;
int main()
{
   ios::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);
    //while(1)
    //{
        int x,y;
        cin>>x>>y;
        //x=rand()%10; y=rand()%10;
        //cout<<"x = "<<x<<" y = "<<y<<endl;
        y--;
        int diff=x-y;
        if(diff<0||diff%2!=0||(x>0&&y==0||y<0))cout<<"No"<<endl;
        else cout<<"Yes"<<endl;
    //}
  return 0;
}
