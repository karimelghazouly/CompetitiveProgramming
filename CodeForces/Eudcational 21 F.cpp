#include <bits/stdc++.h>
using namespace std;
const int INF = 2000000000;

struct Edge {
    int from, to, cap, flow, index;
    Edge(int from, int to, int cap, int flow, int index) :
        from(from), to(to), cap(cap), flow(flow), index(index) { }
};

struct Dinic {
    int N;
    vector<vector<Edge> > G;
    vector<Edge *> dad;
    vector<int> Q;

    Dinic(int N) : N(N), G(N), dad(N), Q(N) { }

    void AddEdge(int from, int to, int cap) {
        G[from].push_back(Edge(from, to, cap, 0, G[to].size()));
        if(from == to) G[from].back().index++;
        G[to].push_back(Edge(to, from, 0, 0, G[from].size() - 1));
    }

    long long BlockingFlow(int s, int t) {
        fill(dad.begin(), dad.end(), (Edge *)NULL);
        dad[s] = &G[0][0] - 1;

        int head = 0, tail = 0;
        Q[tail++] = s;
        while(head < tail) {
            int x = Q[head++];
            for(int i = 0; i < G[x].size(); i++) {
                Edge &e = G[x][i];
                if(!dad[e.to] && e.cap - e.flow > 0) {
                    dad[e.to] = &G[x][i];
                    Q[tail++] = e.to;
                }
            }
        }
        if(!dad[t]) return 0;

        long long totflow = 0;
        for(int i = 0; i < G[t].size(); i++) {
            Edge *start = &G[G[t][i].to][G[t][i].index];
            int amt = INF;
            for(Edge *e = start; amt && e != dad[s]; e = dad[e->from]) {
                if(!e) {
                    amt = 0;
                    break;
                }
                amt = min(amt, e->cap - e->flow);
            }
            if(amt == 0) continue;
            for(Edge *e = start; amt && e != dad[s]; e = dad[e->from]) {
                e->flow += amt;
                G[e->to][e->index].flow -= amt;
            }
            totflow += amt;
        }
        return totflow;
    }

    long long GetMaxFlow(int s, int t) {
        long long totflow = 0;
        while(long long flow = BlockingFlow(s, t))
            totflow += flow;
        return totflow;
    }
};
struct card
{
    int p,num,level;
};
bool notprime[200050],done;
vector<card>odd,even,vec;
vector<int>primes;
int n,k,x,all=0,b,e,m,cnt,last;
bool check(int mid)
{
    done=0;
    Dinic d(2*n+3);
    all=0;
    even.clear();
    odd.clear();
    last=-1;
    for(int i=0;i<vec.size();i++)
    {
        if(vec[i].level>mid)continue;
        if(vec[i].num%2)
        {
            if(vec[i].num==1)
            {
                if(vec[i].p>vec[last].p)last=i;
            }
            else
            {
                all+=vec[i].p;
                odd.push_back(vec[i]);
                int idx=odd.size()-1;
                d.AddEdge(2*n+1,idx,odd[idx].p);
            }
        }

        else if(vec[i].num%2==0)
        {
            all+=vec[i].p;
            even.push_back(vec[i]);
            int idx=even.size()-1;
            d.AddEdge(n+idx,2*n+2,even[idx].p);
        }
    }
    if(last!=-1)
    {
        all+=vec[last].p;
        odd.push_back(vec[last]);
        int idx=odd.size()-1;
        d.AddEdge(2*n+1,idx,odd[idx].p);
    }
    for(int i=0;i<odd.size();i++)
    {
        for(int j=0;j<even.size();j++)
        {
            if(!notprime[odd[i].num+even[j].num])
            {
              //  cout<<"odd = "<<odd[i].num<<" ev = "<<even[j].num<<" capi ="<<odd[i].p<<" capj = "<<even[j].p<<endl;
                d.AddEdge(i,n+j,1e9);
            }
        }
    }
    int fl = d.GetMaxFlow(2*n+1,2*n+2);
    int diff=all-fl;
    //cout<<"diff = "<<diff<<" k = "<<k<<" all = "<<all<<" mx = "<<fl<<endl;
    return (diff>=k);
}
int main()
{
   ios::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);
    for(int i=2;i<=200009;i++)
    {
        if(!notprime[i])
        {
            x=i+i;
            primes.push_back(i);
            while(x<=200009)
            {
                notprime[x]=1;
                x+=i;
            }
        }
    }
    cin>>n>>k;
    card c;
    for(int i=0;i<n;i++)
    {
        cin>>c.p>>c.num>>c.level;
        vec.push_back(c);
    }
    b=0; e=10003;
    while(b<=e)
    {
        m=(b+e)/2;
        //cout<<"m = "<<m<<" b = "<<b<<" e = "<<e<<endl;
        cnt=0; last=0;
        if(check(m))e=m-1;
        else b=m+1;
    }
    if(e<=10000)cout<<e+1;
    else cout<<"-1";
  return 0;
}
