#include <bits/stdc++.h>
using namespace std;
int main()
{
    int n,k;
    cin>>n>>k;
    string last[n+1],s;
    char x;
    for(int i=0;i<n;i++)
    {
        x='A'+(i%26);
        last[i]+=x;
        if(i>=26)
        {
            x='a'+(i%26);
            last[i]+=x;
        }
    }
    for(int i=0;i<=(n-k);i++)
    {
        cin>>s;
        if(s=="NO")last[i+k-1]=last[i];
    }
    for(int i=0;i<n;i++)cout<<last[i]<<" ";
    return 0;
}
