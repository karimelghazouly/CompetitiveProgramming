#include <bits/stdc++.h>
using namespace std;
int main()
{
    int q,x,c=0;
    cin>>q;
    for(int i=0;i<q;i++)
    {
        cin>>x; c=0;
        while(1)
        {
            if(x<0){cout<<"-1"<<endl;;break;}
            else if(x==0){cout<<c<<endl;;break;}
            else if(x%4==2)x-=6,c++;
            else if(x%2)x-=9,c++;
            else c+=x/4,x=0;
        }
    }
    return 0;
}
