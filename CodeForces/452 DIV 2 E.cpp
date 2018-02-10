#include <bits/stdc++.h>
using namespace std;
struct seg
{
    int l ,r,sz;
    seg* ls;
    seg* rs;
    seg(int ll, int rr ,int ss)
    {
        l=ll; r=rr; sz=ss;
        ls=rs=0;
    }
};
map<int,set<int> >mapp;
map<pair<int,int>,seg* >maxi;
vector<seg>segments;
int main()
{
   ios::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);
    int n,cnt=1;
    cin>>n;
    if(n==1)
    {
        cout<<"1";
        return 0;
    }
    vector<int>vec(n);
    seg* old=0;
    for(int i=0;i<n;i++)cin>>vec[i];
    for(int i=1;i<n;i++)
    {
        if(vec[i]==vec[i-1])cnt++;
        else
        {
            seg* neww= new seg(i-cnt,i-1,cnt);
            if(old!=0)neww->ls=old,old->rs=neww;
            maxi[{-cnt,i-cnt}]=neww;
            cnt=1;
            old=neww;
            //mapp[cnt].insert(segments.size());
            //segments.push_back(s);
        }
    }
    seg* neww = new seg(n-cnt,n-1,cnt);
    maxi[{-cnt,n-cnt}]=neww;
    if(old!=0)neww->ls=old,old->rs=neww;
    //--------------------------------------------------------

    cnt=0;
    seg * cur;
    seg * cls;
    seg * crs;
    while(maxi.size())
    {
        cur=(*maxi.begin()).second;
        maxi.erase({-(cur->sz),cur->l});
        cls=cur->ls; crs=cur->rs;
        //cout<<"cur sz = "<<cur->sz<<" cur l ="<<cls<<" cur r ="<<crs<<endl;
        if(cls!=0&&crs!=0&&vec[crs->l]==vec[cls->l])
        {
            cur->sz=(cls->sz)+(crs->sz);
            cur->l=min(cls->l,crs->l);
            cur->r=max(cls->r,crs->r);
            cur->ls=cls->ls; cur->rs=crs->rs;
            if(cls->ls!=0)cls->ls->rs=cur;
            if(crs->rs!=0)crs->rs->ls=cur;
            maxi[{-(cur->sz),cur->l}]=cur;
            maxi.erase({-(cls->sz),cls->l});
            maxi.erase({-(crs->sz),crs->l});
        }
        else
        {
            if(cls!=0)cls->rs=crs;
            if(crs!=0)crs->ls=cls;
        }
        cnt++;
    }
    cout<<cnt<<endl;

  return 0;
}
