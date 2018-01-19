#include <bits/stdc++.h>
using namespace std;
const int maxn=1e5;
vector<int>arr;
long long tree[1 << 19];
long long lazy[1 << 19];
struct segment
{
    void propagate(int i , int l , int r)
    {
        if(lazy[i]==0)return;

        tree[i]=(tree[i]^lazy[i]);
        if(l != r)
        {
            lazy[i*2]=(lazy[i*2]^lazy[i]);
            lazy[i*2+1]=(lazy[i*2+1]^lazy[i]);
        }
        lazy[i]=0;

    }
    void update( int i , int l , int r,int a ,int b, int v)
    {
        propagate(i,l,r);
        if( a > r || b < l )return ;
        if(l>=a && r<=b)
        {
            lazy[i]=(lazy[i]^v);
            propagate(i,l,r);
            return ;
        }
        int mid=(l+r)/2;
        update( i * 2 , l , mid, a,b, v);
        update( i * 2 + 1 , mid + 1 ,r, a , b , v);
        tree[i]=tree[i*2]+tree[i*2+1];
    }
    int get(int i,int l , int r, int a,int b)
    {
        cout<<" i = "<<i<<" l = "<<l<<" r = "<<r<<" a = "<<a<<" b = "<<b<<endl;
        propagate(i,l,r);
        if( a > r || b < l)return 0;
        if( l >= a && r <=b )return tree[i];
        int mid = (l+r)/2;
        return get(i*2,l,mid,a,b)+get(i*2+1,mid+1,r,a,b);

    }
};
int main()
{
    segment s;
    int n,m,l,r,x,ff,mid;
    scanf("%d",&n);
    for(int i=0;i<n;i++)
    {
        scanf("%d",&x);
        if((i+1)>x)s.update(1,0,n-1,i,i,1),cout<<"updating "<<endl;;
    }
    scanf("%d",&m);
    for(int i=0;i<m;i++)
    {
        scanf("%d %d",&l,&r);
        l--; r--; mid=(l+r)/2;
        if(l!=r&&(r-l+1)%2==0)s.update(1,0,n-1,l,r,1);
        else if(l!=r)s.update(1,0,n-1,l,mid,1),s.update(1,0,n-1,mid+1,r,1);
        ff=s.get(1,0,n-1,0,n-1);
        cout<<"ff = "<<ff<<endl;
        if(ff%2==0)printf("even\n");
        else printf("odd\n");
    }
  return 0;
}
