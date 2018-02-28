#include <bits/stdc++.h>
using namespace std;
char arr[500][500];
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);
    int a,b,c,d,n,lastr,lastc=0,inc,moves=0,col=0,idx=0;
    cin>>a>>b>>c>>d>>n;
    for(int i=0;i<500;i++)for(int j=0;j<500;j++)arr[i][j]='.';
    int x[n];
    for(int i=0;i<n;i++)cin>>x[i];
    if(a%2)lastr=b-1,inc=-1;
    else lastr=0,inc=1;
    for(int r=lastr;;r+=inc)
    {
        if(col==a+c)break;
        if(r<0)col++,inc*=-1;
        else if(col<a&&r==b)col++,inc*=-1;
        else if(col>=a&&r==d)col++,inc*=-1;
        else
        {
            arr[r][col]='a'+idx;
            x[idx]--;
            if(x[idx]==0)idx++;
        }
        //cout<<"r = "<<r<<" col = "<<col<<" inc = "<<inc<<endl;
    }
    cout<<"YES"<<endl;
    for(int i=0;i<max(b,d);i++)
    {
        for(int j=0;j<(a+c);j++)cout<<arr[i][j];
        cout<<endl;

    }
  return 0;
}
