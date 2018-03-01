#include <bits/stdc++.h>
using namespace std;
int main()
{
    string s;
    bool br=0;
    cin>>s;
    if(s[s.size()-1]>='5')
    {
        s[s.size()-1]='0';
        int sz=s.size();
        sz-=2;
        for(int i=sz;i>=0;i--)
        {
            if(s[i]=='9')s[i]='0';
            else
            {
                s[i]++;
                br=1;
                break;
            }
        }
        if(!br)s.insert(0,"1");
    }
    else s[s.size()-1]='0';
    cout<<s;
    return 0;
}
