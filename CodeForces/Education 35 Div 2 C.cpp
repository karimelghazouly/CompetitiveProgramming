#include <bits/stdc++.h>
using namespace std;
#define long long ll
int main()
{
   ios::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);
    int x; vector<int>vec;
    for(int i=0;i<3;i++)
    {
        cin>>x;
        vec.push_back(x);
    }
    sort(vec.begin(),vec.end());
    do
    {
        bool vis[100009]={},br=0;
        for(int i=0;i<3;i++)
        {
            for(int j=i+1;j<=100000;j+=vec[i])vis[j]=1;
        }
        for(int i=3;i<=100000;i++)
        {
            if(!vis[i])
            {
                br=1;
                break;
            }
        }
        if(!br)
        {
            cout<<"YES";
            return 0;
        }
    }while(next_permutation(vec.begin(),vec.end()));
    cout<<"NO";
    return 0;
}
