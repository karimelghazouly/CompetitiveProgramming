//solved using Mo Algorithm
#include <bits/stdc++.h>
using namespace std;
int ro;
// cmp function to sort the queries in order of their sqrt root block and then their right value
bool cmp(pair<int,pair<int,int> >a,pair<int,pair<int,int> > b)
{
    if(a.second.first/ro<b.second.first/ro)return true;
    if(b.second.first/ro<a.second.first/ro)return false;
    if(a.second.first/ro==b.second.first/ro&&a.second.second<b.second.second)return true;
    else return false;

}
int ans[100009],n;
int cnt[1000000];
int result;
// remove funtion an element from the current query
void rem(int a)
{
    // we can't have a number > 10^5
    if(a>n)return ;
    /* here we have two cases if integer x was repeated x times we are going to
        to x-1 so we decrease ans by 1
        and if we have x repeated x+1 times so it's not counted but when we decrease
        it it become x times*/
    if(cnt[a]==a)result--;
    cnt[a]--;
    if(cnt[a]==a)result++;
}
void add(int a)
{
    if(a>n)return ;
    if(cnt[a]==a)result--;
    cnt[a]++;
    if(cnt[a]==a)result++;
}
int main()
{
    int q,l,r,currentl,currentr;
    scanf("%d%d", &n, &q );
    // size of one block
    ro=sqrt(n);
    int arr[n];
    //   block id , l  , r
    pair<int,pair<int,int> >pa[q];
    for(int i=0;i<n;i++)scanf("%d", &arr[i]);
    for(int i=0;i<q;i++)
    {
        scanf("%d%d", &l, &r );
        l--; r--;
        pa[i].first=i;
        pa[i].second.first=l;
        pa[i].second.second=r;
    }
    sort(pa,pa+q,cmp);
    // answering the first query to put initial values to l and r
    l=pa[0].second.first; r=pa[0].second.second;
    for(int i=l;i<=r;i++)add(arr[i]);
    ans[pa[0].first]=result;
    for(int i=1;i<q;i++)
    {
        currentl=pa[i].second.first;
        currentr=pa[i].second.second;
        /*
            myself = current index l is standing at

            if l is smaller than the query l i need to
            remove my self and all elements between l and query l
            ------------------------------------------------------
            if my l is bigger than query l i need to add elements between
            l and query l and i will not add myself because i'm already added
        */
        while(l<currentl){rem(arr[l++]);}
        while(l>currentl){add(arr[--l]);}
        while(r<currentr){add(arr[++r]);}
        while(r>currentr){rem(arr[r--]);}
        ans[pa[i].first]=result;
    }
    for(int i=0;i<q;i++)printf("%d\n",ans[i]);
    return 0;
}
