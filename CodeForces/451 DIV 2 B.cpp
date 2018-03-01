#include <bits/stdc++.h>
using namespace std;
int main()
{

    long long ans,fo2,n,a,b;
    cin>>n>>a>>b;
    for(long long i=0;i<=n/a;i++)
    {
        fo2=n-(i*a);
        if(fo2%b==0)
        {
            cout<<"YES\n"<<i<<" "<<fo2/b<<endl;
            return 0;
        }
    }
    printf("NO");
    return 0;
}
