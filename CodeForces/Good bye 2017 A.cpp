#include <bits/stdc++.h>
using namespace std;
#define long long ll
int main()
{
   ios::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);
    string s;
    int cnt=0;
    cin>>s;
    for(int i=0;i<s.size();i++)
    {
        if(s[i]>='0'&&s[i]<='9'&&(s[i]-'0')%2==1)cnt++;
        else if(s[i]=='a'||s[i]=='e'||s[i]=='i'||s[i]=='o'||s[i]=='u')cnt++;
    }
    cout<<cnt;
  return 0;
}
