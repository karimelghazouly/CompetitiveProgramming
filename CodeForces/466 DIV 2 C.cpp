#include <bits/stdc++.h>
using namespace std;
bool arr[30];
int main()
{
   ios::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);
    int n,k;
    string s,temp;
    char mini='z';
    cin>>n>>k>>s;
    temp=s;
    for(int i=0;i<s.size();i++)
    {
        arr[s[i]-'a']=1;
        mini=min(mini,s[i]);
    }
    if(k>(int)s.size())
    {
        int diff=k-(int)s.size();
        for(int i=0;i<diff;i++)temp+=mini;
        cout<<temp<<endl;
        return 0;
    }
    temp.resize(k);
    for(int i=min((int)s.size(),k-1);i>=0;i--)
    {
        char x=s[i];
        for(int z=1;(x-'a'+z)<26;z++)
        {
            if(arr[x-'a'+z])
            {
                //cout<<"i = "<<i<<" X + z = "<<(char)(x+z)<<endl;
                temp[i]=(char)x+z;
                for(int j=i+1;j<k;j++)
                    temp[j]=mini;
                cout<<temp;
                return 0;
            }

        }
    }
  return 0;
}
