#include <bits/stdc++.h>
using namespace std;
int main()
{
   ios::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);
    long long n ,k,c=0,last,cur=1;
    cin>>n>>k;
    if(k==1)cout<<n;
    else
    {
        while(n>1)
        {
            n/=2;
            c++;
        }
        last=(1<<c);
        for(int i=1;i<=c;i++)cur*=2;
        last=cur;
        //cout<<"last = "<<last<<"C = "<<c<<endl;
        cout<<(last^(last-1));
    }

  return 0;
}
