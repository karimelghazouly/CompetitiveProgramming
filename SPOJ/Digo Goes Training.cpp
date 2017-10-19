    #include <bits/stdc++.h>
    using namespace std;
    int main()
    {
        ios::sync_with_stdio(false);
        cin.tie(0); cout.tie(0);
        int t; cin>>t;
        while(t--)
        {
            int n,h,q;
            double x1,y1,x2,y2,mn,mx;
            cin>>n;
            vector<pair<double,double> >vec;
            for(int i=0;i<n;i++)
            {
                cin>>x1>>y1>>x2>>y2;
                mn=min(x1,x2); mx=max(x1,x2);
                vec.push_back(make_pair(mn,mx));
            }
            cin>>q;
            while(q--)
            {
                cin>>h>>x1;
                if(h==0)
                {
                    int c=0;
                    for(int i=0;i<vec.size();i++)if(x1>=vec[i].first&&x1<=vec[i].second)c++;
                    cout<<c<<endl;
                }
                else
                {
                    cin>>y1>>x2>>y2;
                    mn=min(x1,x2); mx=max(x1,x2);
                    vec.push_back(make_pair(mn,mx));
                }
            }

        }
        return 0;
    }
