#include <bits/stdc++.h>
using namespace std;
struct seg{
    int x1,y1,x2,y2,dist;
};
bool check(seg a, seg b)
{
    bool x=0,y=0;
    //cout<<"a.x1 = "<<a.x1<<" a.x2 = "<<a.x2<<" b.x1 = "<<b.x1<<" b.x2= "<<b.x2<<endl;
    if((a.x1==b.x1&&a.x2==b.x2)||(a.x2==b.x1&&a.x1==b.x2))x=1;
    if((a.y1==b.y1&&a.y2==b.y2)||(a.y2==b.y1&&a.y1==b.y2))y=1;
    //cout<<"x = "<<x<<" y= "<<y<<endl;
    return (x&y);
}
bool checkP(seg a, seg b)
{
    double diff1x=a.x2-a.x1,diff1y=a.y2-a.y1,s1,diff2x=b.x2-b.x1,diff2y=b.y2-b.y1,s2;
    //cout<<" diff1x = "<<diff1x<<" diff1y = "<<diff1y<<" diff2x = "<<diff2x<<" diff2y = "<<diff2y<<endl;
    if((diff1x!=0&&abs(diff1y/diff1x)!=0)||(diff2x!=0&&abs(diff2y/diff2x)!=0))
    {
        cout<<"NO";
        exit(0);
    }
    s1=diff1y*diff2x;
    s2=diff2y*diff1x;
    //cout<<"s1 = "<<s1<<" s2 = "<<s2<<endl;
    return(s1==s2);
}
bool checkt(seg a , seg b)
{
    return((a.x1==b.x1&&a.y1==b.y1)||(a.x1==b.x2&&a.y1==b.y2)||(a.x2==b.x1&&a.y2==b.y1)
        ||(a.x2==b.x2&&a.y2==b.y2));
}
int main()
{
   ios::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);
    vector<seg>vec,g[10];
    int x1,y1,x2,y2,last=0;
    seg s;
    for(int i=0;i<4;i++)
    {
        cin>>s.x1>>s.y1>>s.x2>>s.y2;
        for(int j=0;j<vec.size();j++)
        {
            if(check(s,vec[j]))
            {
                cout<<"NO";
                return 0;
            }
        }
        s.dist=sqrt(((s.x1-s.x2)*(s.x1-s.x2))+((s.y1-s.y2)*(s.y1-s.y2)));
        vec.push_back(s);
    }
    for(int i=0;i<4;i++)
    {
        for(int j=i+1;j<4;j++)
        {
            //cout<<"i = "<<i<<" j = "<<j<<endl;
            if(checkP(vec[i],vec[j]))
            {
                if(vec[i].dist==vec[j].dist)
                {
                    g[last].push_back(vec[i]);
                    g[last].push_back(vec[j]);
                    last++;
                }
                else
                {
                    cout<<"NO";
                    return 0;
                }
            }
        }
    }
    if(g[0].size()!=2||g[1].size()!=2||last>3)
    {
        cout<<"NO";
        return 0;
    }
    for(int i=0;i<2;i++)
    {

        if(!(checkt(g[0][i],g[1][0])&&checkt(g[0][i],g[1][1])))
        {
            cout<<"NO";
            return 0;
        }
    }
    cout<<"YES"<<endl;
  return 0;
}

