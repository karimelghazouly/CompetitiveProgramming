#include <bits/stdc++.h>
using namespace std;
int main()
{
    int n,last=0,cnt=0,x;
    cin>>n; last=n;
    bool arr[n+2]={0};
    vector<int>vec;
    vec.push_back(1);
    for(int i=0;i<n;i++)
    {
        cin>>x;
        if(!arr[x])arr[x]=1,cnt++;
        while(arr[last]){last--;cnt--;}
        vec.push_back(cnt+1);
    }
    for(int i=0;i<vec.size();i++)cout<<vec[i]<<" ";
    return 0;
}
