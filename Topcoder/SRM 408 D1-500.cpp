#include <vector>
#include <list>
#include <map>
#include <set>
#include <queue>
#include <deque>
#include <stack>
#include <bitset>
#include <algorithm>
#include <functional>
#include <numeric>
#include <utility>
#include <sstream>
#include <iostream>
#include <iomanip>
#include <cstdio>
#include <cmath>
#include <cstdlib>
#include <ctime>
using namespace std;

int under[100];
vector<string>listt;
bool visited[100];
long long ans=0,one=1;
long long pw(int b,int p)
{
    long long ret=1;
    for(int i=0;i<p;i++)ret*=b;
    return ret;
}
int dfs(int node)
{
    visited[node]=true;
    int ret=0;
    for(int i=0;i<listt[node].size();i++)
    {
        if(listt[node][i]=='Y'&&!visited[i])ret=max(ret,dfs(i));
    }
    under[node]=ret;
    return ret+1;
}
bool cmp(pair<int,int>a,pair<int,int>b)
{
    return (a.first>b.first);
}
void solve(int node,int cnt)
{
    //cout<<"node = "<<node<<" cnt = "<<cnt<<endl;
    bool call=false;
    cnt=max(cnt,1);
    visited[node]=1;
    vector< pair<int, int > >vec;
    for(int i=0;i<listt[node].size();i++)
    {
        if(!visited[i]&&listt[node][i]=='Y')vec.push_back({under[i],i});
    }
    int nxt,nxtcnt=cnt+1;
    sort(vec.begin(),vec.end(),cmp);
    if(vec.size()>0)solve(vec[0].second,nxtcnt),call=true;
    for(int i=1;i<vec.size();i++)
    {
        nxt=vec[i].second; visited[nxt]=true;
        //cout<<"node = "<<node<<" nxt = "<<nxt<<" nxtcnt = "<<nxtcnt<<endl;
        solve(nxt,1);
        call=true;
    }
    if(!call)
    {
        //cout<<"node  = "<<node<<" cnt = "<<cnt<<" ans = "<<ans<<endl;
        ans+=pw(2,cnt)-1;
    }
    return;
}
class CandyGame
 {
    public:
        int maximumCandy(vector <string> graph, int target)
        {
            ans=0;
            for(int i=0;i<100;i++)visited[i]=0,under[i]=0;
            listt=graph;
            dfs(target);
            for(int i=0;i<graph.size();i++)
            {
                if(!visited[i])return -1;
            }
            for(int i=0;i<100;i++)visited[i]=0;
            visited[target]=true;
            for(int i=0;i<listt[target].size();i++)
            {
                if(listt[target][i]=='Y')
                {
                    if(under[i]==0)visited[i]=true,ans++;
                    else solve(i,1);
                    //cout<<" i = "<<i<<" under[i] = "<<under[i]<<"ans = "<<ans<<endl;
                }
            }
            if(ans>2000000000)return -1;
            return ans;
        }
};








bool KawigiEdit_RunTest(int testNum, vector <string> p0, int p1, bool hasAnswer, int p2) {
	cout << "Test " << testNum << ": [" << "{";
	for (int i = 0; int(p0.size()) > i; ++i) {
		if (i > 0) {
			cout << ",";
		}
		cout << "\"" << p0[i] << "\"";
	}
	cout << "}" << "," << p1;
	cout << "]" << endl;
	CandyGame *obj;
	int answer;
	obj = new CandyGame();
	clock_t startTime = clock();
	answer = obj->maximumCandy(p0, p1);
	clock_t endTime = clock();
	delete obj;
	bool res;
	res = true;
	cout << "Time: " << double(endTime - startTime) / CLOCKS_PER_SEC << " seconds" << endl;
	if (hasAnswer) {
		cout << "Desired answer:" << endl;
		cout << "\t" << p2 << endl;
	}
	cout << "Your answer:" << endl;
	cout << "\t" << answer << endl;
	if (hasAnswer) {
		res = answer == p2;
	}
	if (!res) {
		cout << "DOESN'T MATCH!!!!" << endl;
	} else if (double(endTime - startTime) / CLOCKS_PER_SEC >= 2) {
		cout << "FAIL the timeout" << endl;
		res = false;
	} else if (hasAnswer) {
		cout << "Match :-)" << endl;
	} else {
		cout << "OK, but is it right?" << endl;
	}
	cout << "" << endl;
	return res;
}
int main() {
	bool all_right;
	all_right = true;

	vector <string> p0;
	int p1;
	int p2;

	{
	// ----- test 0 -----
	string t0[] = {"NNNNNNYNYN", "NNYYNNNNNN", "NYNNNYNNNN", "NYNNNNYNNN", "NNNNNNNYYY", "NNYNNNNNNN", "YNNYNNNNNN", "NNNNYNNNNN", "YNNNYNNNNN", "NNNNYNNNNN"};
			p0.assign(t0, t0 + sizeof(t0) / sizeof(t0[0]));
	p1 = 6;
	p2 = 31;
	all_right = KawigiEdit_RunTest(0, p0, p1, true, p2) && all_right;
	// ------------------
	}

	{
	// ----- test 1 -----
	string t0[] = {"NYN","YNY","NYN"};
			p0.assign(t0, t0 + sizeof(t0) / sizeof(t0[0]));
	p1 = 2;
	p2 = 3;
	all_right = KawigiEdit_RunTest(1, p0, p1, true, p2) && all_right;
	// ------------------
	}

	{
	// ----- test 2 -----
	string t0[] = {"NYYY","YNNN","YNNN","YNNN"};
			p0.assign(t0, t0 + sizeof(t0) / sizeof(t0[0]));
	p1 = 0;
	p2 = 3;
	all_right = KawigiEdit_RunTest(2, p0, p1, true, p2) && all_right;
	// ------------------
	}

	{
	// ----- test 3 -----
	string t0[] = {"NYYY","YNNN","YNNN","YNNN"};
			p0.assign(t0, t0 + sizeof(t0) / sizeof(t0[0]));
	p1 = 1;
	p2 = 4;
	all_right = KawigiEdit_RunTest(3, p0, p1, true, p2) && all_right;
	// ------------------
	}

	{
	// ----- test 4 -----
	string t0[] = {"NYNNNYN","YNYNYNN","NYNYNNN","NNYNNNN","NYNNNNN","YNNNNNY","NNNNNYN"};
			p0.assign(t0, t0 + sizeof(t0) / sizeof(t0[0]));
	p1 = 0;
	p2 = 11;
	all_right = KawigiEdit_RunTest(4, p0, p1, true, p2) && all_right;
	// ------------------
	}

	{
	// ----- test 5 -----
	string t0[] = {"NYNNNNNNNNNNNNNNNNNNNNNNNNNNNNNN","YNYNNNNNNNNNNNNNNNNNNNNNNNNNNNNN","NYNYNNNNNNNNNNNNNNNNNNNNNNNNNNNN","NNYNYNNNNNNNNNNNNNNNNNNNNNNNNNNN","NNNYNYNNNNNNNNNNNNNNNNNNNNNNNNNN","NNNNYNYNNNNNNNNNNNNNNNNNNNNNNNNN","NNNNNYNYNNNNNNNNNNNNNNNNNNNNNNNN","NNNNNNYNYNNNNNNNNNNNNNNNNNNNNNNN","NNNNNNNYNYNNNNNNNNNNNNNNNNNNNNNN","NNNNNNNNYNYNNNNNNNNNNNNNNNNNNNNN","NNNNNNNNNYNYNNNNNNNNNNNNNNNNNNNN","NNNNNNNNNNYNYNNNNNNNNNNNNNNNNNNN","NNNNNNNNNNNYNYNNNNNNNNNNNNNNNNNN","NNNNNNNNNNNNYNYNNNNNNNNNNNNNNNNN","NNNNNNNNNNNNNYNYNNNNNNNNNNNNNNNN","NNNNNNNNNNNNNNYNYNNNNNNNNNNNNNNN","NNNNNNNNNNNNNNNYNYNNNNNNNNNNNNNN","NNNNNNNNNNNNNNNNYNYNNNNNNNNNNNNN","NNNNNNNNNNNNNNNNNYNYNNNNNNNNNNNN","NNNNNNNNNNNNNNNNNNYNYNNNNNNNNNNN","NNNNNNNNNNNNNNNNNNNYNYNNNNNNNNNN","NNNNNNNNNNNNNNNNNNNNYNYNNNNNNNNN","NNNNNNNNNNNNNNNNNNNNNYNYNNNNNNNN","NNNNNNNNNNNNNNNNNNNNNNYNYNNNNNNN","NNNNNNNNNNNNNNNNNNNNNNNYNYNNNNNN","NNNNNNNNNNNNNNNNNNNNNNNNYNYNNNNN","NNNNNNNNNNNNNNNNNNNNNNNNNYNYNNNN","NNNNNNNNNNNNNNNNNNNNNNNNNNYNYNNN","NNNNNNNNNNNNNNNNNNNN"
			"NNNNNNNYNYNN","NNNNNNNNNNNNNNNNNNNNNNNNNNNNYNYN","NNNNNNNNNNNNNNNNNNNNNNNNNNNNNYNY","NNNNNNNNNNNNNNNNNNNNNNNNNNNNNNYN"};
			p0.assign(t0, t0 + sizeof(t0) / sizeof(t0[0]));
	p1 = 0;
	p2 = -1;
	all_right = KawigiEdit_RunTest(5, p0, p1, true, p2) && all_right;
	// ------------------
	}

	if (all_right) {
		cout << "You're a stud (at least on the example cases)!" << endl;
	} else {
		cout << "Some of the test cases had errors." << endl;
	}
	return 0;
}
// END KAWIGIEDIT TESTING
