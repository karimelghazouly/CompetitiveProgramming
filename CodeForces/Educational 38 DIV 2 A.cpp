#include <bits/stdc++.h>
using namespace std;
int main()
{
   ios::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);
    int n;
    cin>>n;
    string s;
    cin>>s;
    for(int i=0;i+1<s.size();i++)
    {
        while(i+1<s.size()&&(s[i]=='a'||s[i]=='e'||s[i]=='i'||s[i]=='o'||s[i]=='u'||s[i]=='y')&&(s[i+1]=='a'||s[i+1]=='e'||s[i+1]=='i'||s[i+1]=='o'||s[i+1]=='u'||s[i+1]=='y'))
        {
            s.erase(s.begin()+i+1);
        }
    }
    cout<<s;
  return 0;
}
