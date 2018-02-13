#include <bits/stdc++.h>
using namespace std;
map<string,string>mapp;
int main()
{
    mapp["void"]="void";
    int de,re,n;
    bool v,d;
    string t,a,b,ori,temp,last;
    cin>>n;
    for(int i=0;i<n;i++)
    {
        cin>>t;
        if(t=="typedef")
        {
            cin>>a>>b;
            de=re=0; d=0; ori=""; temp=""; last="";
            for(int i=0;i<a.size();i++)
            {
                if(a[i]=='&')de++;
                else if(a[i]=='*')re++;
                else ori+=a[i];
            }
            if(ori=="void")v=1;
            if(de-re>0)d=1;
           // cout<<"v = "<<v<<" d = "<<d<<" mapp = "<<mapp[ori]<<endl;
            if(mapp[ori]!="")
            {
                //cout<<"d = "<<d<<" de = "<<de<<" re = "<<re<<endl;
                if(d)
                {
                    for(int i=0;i<abs(de-re);i++)temp+="&";
                    temp+=mapp[ori];
                }
                else
                {
                    temp=mapp[ori];
                    for(int i=0;i<abs(de-re);i++)temp+="*";
                }
            }
            else temp="errtype";
            de=re=0; d=0;
            for(int i=0;i<temp.size();i++)
            {
                if(temp[i]=='&')de++;
                else if(temp[i]=='*')re++;
                else last+=temp[i];
            }
            if(de>re)
            {
                for(int i=0;i<abs(de-re);i++)last.insert(0,"&");
            }
            else
            {
                for(int i=0;i<abs(de-re);i++)last+="*";
            }
            if(last.find("&void")!=string::npos||last.find("errtype")!=string::npos)last="errtype";
            mapp[b]=last;
           //cout<<"last = "<<last<<" temp = "<<temp<<endl;
        }
        else
        {
            cin>>a; ori=""; de=re=0;temp=ori=last="";
            for(int i=0;i<a.size();i++)
            {
                 if(a[i]=='&')de++;
                else if(a[i]=='*')re++;
                else ori+=a[i];
            }
            temp=mapp[ori];
            //cout<<"ori = "<<ori<<" mapp = "<<mapp[ori]<<endl;
            if(temp==""||ori=="errtype"||temp=="errtype")
            {
                cout<<"errtype\n";
                continue;
            }
            for(int i=0;i<temp.size();i++)
            {
                if(temp[i]=='&')de++;
                else if(temp[i]=='*')re++;
                else last+=temp[i];
            }
            if(de>re)
            {
                for(int i=0;i<abs(de-re);i++)last.insert(0,"&");
            }
            else
            {
                for(int i=0;i<abs(de-re);i++)last+="*";
            }
            //cout<<"last = "<<last<<endl;
            bool fail=!(last.find("&void")==string::npos);
            if(fail)
            {
                cout<<"errtype\n";
                continue;
            }
            cout<<last<<"\n";

        }
    }
  return 0;
}
