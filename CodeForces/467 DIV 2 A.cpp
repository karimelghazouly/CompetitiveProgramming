#include <bits/stdc++.h>
using namespace std;
int main()
{
   ios::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);
    int n,x;
    cin>>n;
    set<int>st;
    for(int i=0;i<n;i++)
    {
        cin>>x;
        if(x)st.insert(x);
    }
    cout<<st.size()<<endl;
  return 0;
}
