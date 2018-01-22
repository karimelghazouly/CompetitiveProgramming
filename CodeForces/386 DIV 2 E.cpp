#include <bits/stdc++.h>
using namespace std;
map<int,int>mapp;
bool valid[1000000];
int n,m,even,odd,num_evens=0,num_odds=0,cnts,exch,cnt,arr[1000000];
int get_value(int n)
{
    for(int i=n;i>0;i-=2)
    {
        if(!mapp[i])return i;
    }
    return -1;
}
int main()
{
   ios::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);
    cin>>n>>m;
    for(int i=0;i<n;i++)
    {
        cin>>arr[i];
        if(!mapp[arr[i]])valid[i]=1;
        if(arr[i]%2)num_odds++;
        else num_evens++;
        mapp[arr[i]]++;
    }
    if(m%2)even=m-1,odd=m;
    else even=m,odd=m-1;
    for(int i=0;i<n;i++)
    {
        if(!valid[i])
        {
            if(num_evens>num_odds)
            {
                if(arr[i]%2)num_odds--;
                else num_evens--;
                exch=get_value(odd);
                if(exch==-1){cout<<"-1";return 0;}
                odd=exch-2; num_odds++; arr[i]=exch; cnt++; mapp[arr[i]]--;
            }
            else if(num_evens<num_odds)
            {
                if(arr[i]%2)num_odds--;
                else num_evens--;
                exch=get_value(even);
                if(exch==-1){cout<<"-1";return 0;}
                even=exch-2; num_evens++; arr[i]=exch; cnt++; mapp[arr[i]]--;
            }
            else
            {
                if(arr[i]%2)
                {
                    exch=get_value(odd);
                    if(exch==-1){cout<<"-1";return 0;}
                    arr[i]=exch,odd=exch-2,cnt++,mapp[arr[i]]--;
                }
                else
                {
                    exch=get_value(even);
                    if(exch==-1){cout<<"-1";return 0;}
                    arr[i]=exch,even=exch-2,cnt++,mapp[arr[i]]--;
                }
            }
        }
    }
    for(int i=0;i<n&&(num_evens!=num_odds);i++)
    {
        if(num_evens>num_odds&&arr[i]%2==0)
        {
            exch=get_value(odd);
            if(exch==-1){cout<<"-1";return 0;}
            arr[i]=exch; odd=exch-2;
            cnt++; num_odds++; num_evens--; mapp[arr[i]]--;
        }
        else if(num_evens<num_odds&&arr[i]%2)
        {
            exch=get_value(even);
            if(exch==-1){cout<<"-1"; return 0;}
            arr[i]=exch; even=exch-2;
            cnt++; num_evens++; num_odds--; mapp[arr[i]]--;
        }
    }
    cout<<cnt<<endl;
    for(int i=0;i<n;i++)cout<<arr[i]<<" ";
  return 0;
}
