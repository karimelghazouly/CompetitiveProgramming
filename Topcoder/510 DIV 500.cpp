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


class TheLuckyGameDivTwo {
public:
    bool islucky(int n)
    {
        while(n>0)
        {
            if(n%10!=7&&n%10!=4)return 0;
            n/=10;
        }
        return 1;
    }
	int find(int a, int b, int jLen, int bLen)
	{

	    bool lucky[100009];
	    int part[100009];
	    int cnt=0,l=0,ans=0,idx1,idx2,mini,del;
	    for(int i=0;i<100009;i++)lucky[i]=0,part[i]=-1;
        for(int i=1;i<=b;i++)
        {
            if(islucky(i))lucky[i]=1;
        }
        for(int i=a;i<=b;i++)
        {
            if(lucky[i])l++;
            cnt++;
            if(cnt==bLen)
            {
                part[i]=l;
                if(lucky[i-cnt+1])l--;
                cnt--;
            }
        }
        for(int i=a;i<=b;i++)cout<<part[i]<<" ";
        cout<<endl;
        cnt=0;
        multiset<int>st;
        queue<int>q;
        for(int i=a;i<=b;i++)
        {
            cnt++;
            if(part[i]!=-1)st.insert(part[i]),q.push(part[i]);
            if(cnt==jLen)
            {
                mini=(*st.begin());
                cout<<"i = "<<i<<" mini = "<<mini<<" st.size = "<<st.size()<<" front = "<<q.front()<<endl;
                ans=max(mini,ans);
                del=q.front(); q.pop();
                if(st.count(del)==1)
                {
                    if(st.size()==1)st.clear();
                    else st.erase(del);
                }
                else
                {
                    int cntttt=st.count(del);
                    if(st.size()==1)st.clear();
                    else st.erase(del);
                    for(int i=0;i<cntttt-1;i++)st.insert(del);
                }
                cnt--;
            }
        }
        return ans;

	}
};

// BEGIN KAWIGIEDIT TESTING
// Generated by KawigiEdit 2.1.4 (beta) modified by pivanof
bool KawigiEdit_RunTest(int testNum, int p0, int p1, int p2, int p3, bool hasAnswer, int p4) {
	cout << "Test " << testNum << ": [" << p0 << "," << p1 << "," << p2 << "," << p3;
	cout << "]" << endl;
	TheLuckyGameDivTwo *obj;
	int answer;
	obj = new TheLuckyGameDivTwo();
	clock_t startTime = clock();
	answer = obj->find(p0, p1, p2, p3);
	clock_t endTime = clock();
	delete obj;
	bool res;
	res = true;
	cout << "Time: " << double(endTime - startTime) / CLOCKS_PER_SEC << " seconds" << endl;
	if (hasAnswer) {
		cout << "Desired answer:" << endl;
		cout << "\t" << p4 << endl;
	}
	cout << "Your answer:" << endl;
	cout << "\t" << answer << endl;
	if (hasAnswer) {
		res = answer == p4;
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

	int p0;
	int p1;
	int p2;
	int p3;
	int p4;

	{
	// ----- test 0 -----
	p0 = 1;
	p1 = 10;
	p2 = 2;
	p3 = 1;
	p4 = 0;
	all_right = KawigiEdit_RunTest(0, p0, p1, p2, p3, true, p4) && all_right;
	// ------------------
	}

	{
	// ----- test 1 -----
	p0 = 1;
	p1 = 100;
	p2 = 100;
	p3 = 100;
	p4 = 6;
	all_right = KawigiEdit_RunTest(1, p0, p1, p2, p3, true, p4) && all_right;
	// ------------------
	}

	{
	// ----- test 2 -----
	p0 = 4;
	p1 = 8;
	p2 = 3;
	p3 = 2;
	p4 = 1;
	all_right = KawigiEdit_RunTest(2, p0, p1, p2, p3, true, p4) && all_right;
	// ------------------
	}

	{
	// ----- test 3 -----
	p0 = 1;
	p1 = 100;
	p2 = 75;
	p3 = 50;
	p4 = 2;
	all_right = KawigiEdit_RunTest(3, p0, p1, p2, p3, true, p4) && all_right;
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
