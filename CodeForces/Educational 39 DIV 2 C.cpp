#include <bits/stdc++.h>
using namespace std;
int main()
{
   ios::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);
    string s;
    cin>>s;
    char srch='a';
    for(int i=0;i<s.size();i++)
    {
        if(s[i]<=srch&&srch<='z')s[i]=srch,srch++;
    }
    if(srch<='z')cout<<"-1"<<endl;
    else cout<<s<<endl;

  return 0;
}
