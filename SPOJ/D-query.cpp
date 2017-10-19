    #include <bits/stdc++.h>
    using namespace std;
    int n,q,l,r,currentl,currentr,ro;
    bool cmp(pair<int,pair<int,int> >a,pair<int,pair<int,int> > b)
    {
        if(a.second.first/ro<b.second.first/ro)return true;
        if(b.second.first/ro<a.second.first/ro)return false;
        if(a.second.first/ro==b.second.first/ro&&a.second.second<b.second.second)return true;
        else return false;
     
    }
    int result;
    int cnt[1000009];
    int ans[1000009];
    void add(int a)
    {
        cnt[a]++;
        if(cnt[a]==1)result++;
    }
    void rem(int a)
    {
        cnt[a]--;
        if(cnt[a]==0)result--;
    }
    int main()
    {
        scanf("%d",&n);
        ro=sqrt(n);
        int arr[n];
        for(int i=0;i<n;i++)scanf("%d",&arr[i]);
        scanf("%d",&q);
        pair<int,pair<int,int> >pa[q];
        for(int i=0;i<q;i++)
        {
            scanf("%d%d",&l,&r);
            l--; r--;
            pa[i].first=i;
            pa[i].second.first=l;
            pa[i].second.second=r;
        }
        sort(pa,pa+q,cmp);
        l=pa[0].second.first; r=pa[0].second.second;
        for(int i=l;i<=r;i++)add(arr[i]);
        ans[pa[0].first]=result;
        for(int i=1;i<q;i++)
        {
            currentl=pa[i].second.first;
            currentr=pa[i].second.second;
            //cout<<"currentl = "<<currentl<<" currentr = "<<currentr<<endl;
            while(l<currentl)rem(arr[l++]);
            while(l>currentl)add(arr[--l]);
            while(r<currentr)add(arr[++r]);
            while(r>currentr)rem(arr[r--]);
            ans[pa[i].first]=result;
        }
        for(int i=0;i<q;i++)printf("%d\n",ans[i]);
        return 0;
    }
     