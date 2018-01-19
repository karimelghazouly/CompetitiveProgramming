#include <bits/stdc++.h>
using namespace std;
#define long long ll
int main()
{
   ios::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);
    int n,idx;
    double r,x,diff,dist,mx,y;
    cin>>n>>r;
    double arr[n];
    vector<double>vec;
    for(int i=0;i<n;i++)
    {
        cin>>arr[i]; mx=INT_MIN;
        for(int j=0;j<i;j++)
        {
            if(abs(arr[i]-arr[j])<=2*r&&vec[j]>mx)
            {
                mx=vec[j];
                idx=j;
            }
        }
        if(mx!=INT_MIN)
        {
            diff=arr[i]-arr[idx];
            diff*=diff;
            dist=2*r;
            dist*=dist;
            y=sqrt(dist-diff);
            //cout<<"idx = "<<idx<<" i = "<<i<<" diff = "<<diff<<"dist = "<<dist<<" sqrt(dist-diff) = "<<y<<" y[idx] = "<<vec[idx]<<endl;
            y+=vec[idx];
            vec.push_back(y);
        }
        else vec.push_back(r);
    }
    for(int i=0;i<vec.size();i++)cout<<setprecision(6)<<fixed<<vec[i]<<" ";
  return 0;
}
