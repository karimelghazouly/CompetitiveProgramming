#include <bits/stdc++.h>
using namespace std;
int arr[6];
int sum1,sum2,cnt1,cnt2;
void solve(int idx)
{
    if(idx==6)
    {
        if(sum1==sum2&&cnt1==cnt2)
        {
            cout<<"YES";
            exit(0);
        }
        return ;
    }
    sum1+=arr[idx]; cnt1++;
    solve(idx+1);
    sum1-=arr[idx]; cnt1--;

    sum2+=arr[idx]; cnt2++;
    solve(idx+1);
    sum2-=arr[idx];cnt2--;
}
int main()
{
    for(int i=0;i<6;i++)cin>>arr[i];
    solve(0);
    cout<<"NO";
    return 0;
}
