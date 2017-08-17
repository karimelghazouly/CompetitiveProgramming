#include <bits/stdc++.h>
using namespace std;
map<int,bool>here,f,s;
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);
    bool f1=false,f2=false;
    int n,l,x,y,needed,needed2,needed3,needed4;
    cin>>n>>l>>x>>y;
    int arr[n];
    for(int i=0;i<n;i++)
    {
        cin>>arr[i];
        here[arr[i]]=true;
    }
    for(int i=0;i<n;i++)
    {
        needed=arr[i]-x; needed3=arr[i]-y;
        needed2=arr[i]+x; needed4=arr[i]+y;
        if(here[needed]||here[needed2])f1=true;
        if(here[needed3]||here[needed4])f2=true;
    }
    if(!f1&&!f2)
    {
        for(int i=0;i<n;i++)
        {
            needed=arr[i]-x; needed3=arr[i]-y;
            needed2=arr[i]+x; needed4=arr[i]+y;
            if(needed>=0&&needed<=l)
            {
                if(s[needed])
                {
                    cout<<"1"<<endl<<needed<<endl;
                    return 0;
                }
                f[needed]=true;
            }
            if(needed2>=0&&needed2<=l)
            {
                if(s[needed2])
                {
                    cout<<"1"<<endl<<needed2<<endl;
                    return 0;
                }
                f[needed2]=true;
            }
            if(needed3>=0&&needed3<=l)
            {
                if(f[needed3])
                {
                    cout<<"1"<<endl<<needed3<<endl;;
                    return 0;
                }
                s[needed3]=true;
            }
            if(needed4>=0&&needed4<=l)
            {
                if(f[needed4])
                {
                    cout<<"1"<<endl<<needed4<<endl;;
                    return 0;
                }
                s[needed4]=true;
            }
        }
        cout<<"2"<<endl<<x<<" "<<y<<endl;
    }
    else if(!f1)cout<<"1"<<endl<<x<<endl;
    else if(!f2)cout<<"1"<<endl<<y<<endl;
    else cout<<"0"<<endl;
    return 0;
}
