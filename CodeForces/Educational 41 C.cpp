#include <bits/stdc++.h>
using namespace std;
int arr[200][200],n,ans1=0,ans2=0,ans=1e9;
int main()
{
   ios::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);
    cin>>n;
    char x;
    vector<int>f,s,idx;
    bool color1,color2;
    for(int z=0;z<4;z++)
    {
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<n;j++)
            {
                cin>>x;
                arr[i][j]=x-'0';
            }
        }
        color1=1; color2=0; ans1=ans2=0;
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<n;j++)
            {
                ans1+=(arr[i][j]==color1);
                ans2+=(arr[i][j]==color2);
                color1=1-color1; color2=color2-1;
            }
        }
        f.push_back(ans1); s.push_back(ans2);
    }
    idx.push_back(0); idx.push_back(1); idx.push_back(2); idx.push_back(3);
    do
    {
        ans1=f[idx[0]]+f[idx[1]];
        ans2=s[idx[2]]+s[idx[3]];
        ans=min(ans1+ans2,ans);
    }while(next_permutation(idx.begin(),idx.end()));
    cout<<ans<<endl;
  return 0;
}
