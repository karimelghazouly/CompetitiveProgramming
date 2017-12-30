#include <bits/stdc++.h>
using namespace std;
int r,c;
char arr[100][100];
string s,dir;
int main()
{
   ios::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);
    int cnt=0,cr,cc,sr,sc;
    cin>>r>>c;
    for(int i=0;i<r;i++)
    {
        for(int j=0;j<c;j++)
        {
            cin>>arr[i][j];
            if(arr[i][j]=='S')sr=i,sc=j;
        }
    }
    cin>>s;
    dir+="UDLR";
    sort(dir.begin(),dir.end());
    do
    {
        cr=sr; cc=sc;
        bool b=0;
        for(int i=0;i<s.size();i++)
        {
            int d=s[i]-'0';
            if(arr[cr][cc]=='E'){cnt++;b=1;break;}
            if(cr>=r||cc>=c||cr<0||cc<0||arr[cr][cc]=='#'){break;}
            if(dir[d]=='U')cr--;
            else if(dir[d]=='D')cr++;
            else if(dir[d]=='L')cc--;
            else if(dir[d]=='R')cc++;
        }
        //cout<<"s = "<<s<<" dir = "<<dir<<"cr = "<<cr<<" cc = "<<cc<<endl;
        if(cr>=0&&cr<r&&cc>=0&&cc<c&&arr[cr][cc]=='E'&&!b){cnt++;}
    }while(next_permutation(dir.begin(),dir.end()));

    cout<<cnt<<endl;
  return 0;
}
