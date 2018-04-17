#include <bits/stdc++.h>
using namespace std;
map<char,set<int> >mapp;
int main()
{
   ios::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);
    int idx=0,cnt=1;
    string s1,s2;
    cin>>s1>>s2;
    for(int i=0;i<s1.size();i++)mapp[s1[i]].insert(i);
    for(int i=0;i<s2.size();i++)
    {
        if(mapp[s2[i]].size()==0)
        {
            cout<<"-1";
            return 0;
        }
        auto it = mapp[s2[i]].lower_bound(idx);
        if(it==mapp[s2[i]].end())
        {
            cnt++,idx=-1;
            it = mapp[s2[i]].lower_bound(idx);
        }
        idx=(*it);
        idx++;
    }
    cout<<cnt;
  return 0;
}
