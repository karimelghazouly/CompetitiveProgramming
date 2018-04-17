#include <bits/stdc++.h>
using namespace std;
int di[500],dj[500],memo[509][509],ans,n,m,curi,curj,nxti,nxtj;
bool vis[509][509],h;
int main()
{
   ios::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);
    cin>>n>>m;
    char arr[n][m];
    di['D']=1; di['U']=-1; dj['R']=1; dj['L']=-1;
    for(int i=0;i<n;i++)
    {
        for(int j=0;j<m;j++)
        {
            cin>>arr[i][j];
        }
    }
    for(int i=0;i<n;i++)
    {
        for(int j=0;j<m;j++)
        {
            curi=i; curj=j; h=0;
            vector<int>vec,vec2;
            while(1)
            {
                vis[curi][curj]=1;
                vec.push_back(curi);vec2.push_back(curj);
                nxti=curi+di[arr[curi][curj]];
                nxtj=curj+dj[arr[curi][curj]];
                if(nxti>=n||nxti<0||nxtj>=m||nxtj<0)
                {
                    memo[curi][curj]=1;
                    ans++;
                    h=1;
                    break;
                }
                if(vis[nxti][nxtj])
                {
                    h=memo[curi][curj]=memo[nxti][nxtj];
                    ans+=(memo[nxti][nxtj]==1);
                    break;
                }
                curi=nxti;
                curj=nxtj;
            }
            for(int i=0;i<vec.size();i++)memo[vec[i]][vec2[i]]=h;
        }
    }
    cout<<ans<<endl;
  return 0;
}
