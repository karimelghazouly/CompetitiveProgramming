#include <bits/stdc++.h>
using namespace std;
vector<string>grid;
int di[4]={0,0,1,-1};
int dj[4]={1,-1,0,0};
int id[209][10009],idx,cnt,shapes[100009],w,h;
bool vis[1009][10009];
void dfs(int i , int j)
{
    vis[i][j]=1;
    for(int z=0;z<4;z++)
    {
        int nxti=i+di[z];
        int nxtj=j+dj[z];
        //if(nxti==85&&nxtj==17)cout<<"i = "<<i<<"j = "<<j<<" vis[nxt] = "<<vis[nxti][nxtj]<<endl;
        if(nxti<h+2&&nxti>=0&&nxtj<w*4+2&&nxtj>=0&&grid[nxti][nxtj]=='1'&&id[nxti][nxtj]!=idx)cnt++,idx=id[nxti][nxtj];
        if(nxti<h+2&&nxti>=0&&nxtj<w*4+2&&nxtj>=0&&!vis[nxti][nxtj]&&grid[nxti][nxtj]=='0')dfs(nxti,nxtj);
    }
}
void dfs2(int i , int j)
{
    id[i][j]=idx;
    for(int z=0;z<4;z++)
    {
        int nxti=i+di[z];
        int nxtj=j+dj[z];
        //cout<<"nxti = "<<nxti<<" nxtj = "<<nxtj<<endl;
        if(nxti<=h+1&&nxti>=0&&nxtj>=0&&nxtj<=w*4+1&&!id[nxti][nxtj]&&grid[nxti][nxtj]=='1')dfs2(nxti,nxtj);
    }
}
string conv(char a){
    if (a=='0')
        return "0000";
    if (a=='1')
        return "0001";
    if (a=='2')
        return "0010";
    if (a=='3')
        return "0011";
    if (a=='4')
        return "0100";
    if (a=='5')
        return "0101";
    if (a=='6')
        return "0110";
    if (a=='7')
        return "0111";
    if (a=='8')
        return "1000";
    if (a=='9')
        return "1001";
    if (a=='a')
        return "1010";
    if (a=='b')
        return "1011";
    if (a=='c')
        return "1100";
    if (a=='d')
        return "1101";
    if (a=='e')
        return "1110";
    if (a=='f')
        return "1111";
}
string expand(string x){
    string ret="";
    for (int i=0; i<x.size(); i++)
        ret+=conv(x[i]);
    return ret;
}
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);cout.tie(0);
    int tt=1;
    while(cin>>h>>w){
        int all=0;
        grid.clear();
        for(int i=0;i<1009;i++)for(int j=0;j<10009;j++)vis[i][j]=0;
        for(int i=0;i<209;i++)for(int j=0;j<10009;j++)id[i][j]=0;
        for(int i=0;i<100009;i++)shapes[i]=0;
        if (!h && !w)
            break;
        string zer="";
        for(int i=0;i<(w*4+2);i++)zer+="0";
        grid.push_back(zer);
        for (int i=0; i<h; i++){
            string x; cin>>x;
            grid.push_back(expand(x));
        }
        for(int i=1;i<=h;i++)
        {
            grid[i].insert(0,"0");
            grid[i].insert(grid[i].size(),"0");
        }
        grid.push_back(zer);
        dfs(0,0);
        idx=0;
        for(int i=0;i<=h+1;i++)
        {
            for(int j=0;j<=w*4+1;j++)
            {
                if(grid[i][j]=='1'&&!id[i][j])
                {
                    idx++;
                    all++;
                    dfs2(i,j);
                }
            }
        }
        for(int i=0;i<=h+1;i++)
        {
            for(int j=0;j<=w*4+1;j++)
            {
                if(grid[i][j]=='0'&&!vis[i][j])
                {
                    grid[i][j]='3';
                    cnt=0;
                    idx=-1;
                    dfs(i,j);
                    if(cnt==1)shapes[idx]++;
                }
            }
        }
        string ans="",txt="WAKJSD";
        for(int i=1;i<=all;i++)
            ans+=txt[shapes[i]];

        sort(ans.begin(),ans.end());
        cout<<"Case "<<tt<<": "<<ans<<endl;
        tt++;
    }
    return 0;
}
