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


class MysteriousRestaurant {
public:
	int maxDays(vector <string> prices, int budget)
	{
	    cout<<"D =  "<<'D'-'A'+10<<" n = "<<'n'-'a'+36<<" p = "<<'P'-'A'+10<<" r = "<<'r'-'a'+36<<endl;
	    int allcost=0,days[7],idx,mini,cc,cost,ret=0;
	    for(int i=0;i<prices.size();i++)
        {
            mini=1e9;
            if((i-7)>=0)
            {
                for(int j=0;j<prices[i].size();j++)
                {
                    cc=0;
                    for(int z=i%7;z<=i;z+=7)
                    {
                        int ccc=0;
                        if(prices[z][j]>='a'&&prices[z][j]<='z')ccc=(prices[z][j]-'a')+36;
                        else if(prices[z][j]>='A'&&prices[z][j]<='Z')ccc=(prices[z][j]-'A')+10;
                        else ccc=prices[z][j]-'0';
                        cc+=ccc;
                    }
                    //cout<<"i = "<<i<<" cc = "<<cc<<" j = "<<j<<endl;
                    if(cc<mini)
                    {
                        mini=cc;
                        idx=j;
                    }
                }
                days[i%7]=idx;
            }
            else
            {
                for(int j=0;j<prices[i].size();j++)
                {
                    if(prices[i][j]>='a'&&prices[i][j]<='z')cost=(prices[i][j]-'a')+36;
                    else if(prices[i][j]>='A'&&prices[i][j]<='Z')cost=(prices[i][j]-'A')+10;
                    else cost=prices[i][j]-'0';
                    if(cost<mini)
                    {
                        mini=cost;
                        idx=j;
                    }
                }
                days[i%7]=idx;
            }
            allcost=0;
            for(int h=0;h<=i;h++)
            {
                int id=days[h%7];
                if(prices[h][id]>='a'&&prices[h][id]<='z')cost=(prices[h][id]-'a')+36;
                else if(prices[h][id]>='A'&&prices[h][id]<='Z')cost=(prices[h][id]-'A')+10;
                else cost=prices[h][id]-'0';
                //cout<<"i = "<<i<<" h = "<<h<<" id = "<<id<<" cost = "<<cost<<" prices[h][id] = "<<(prices[h][id]-'a')+36<<endl;
                allcost+=cost;
            }
            //cout<<"allcost = "<<allcost<<endl;
            if(allcost<=budget)ret=max(ret,i+1);
        }
        return ret;
	}
};

// BEGIN KAWIGIEDIT TESTING
// Generated by KawigiEdit 2.1.4 (beta) modified by pivanof
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
	MysteriousRestaurant *obj;
	int answer;
	obj = new MysteriousRestaurant();
	clock_t startTime = clock();
	answer = obj->maxDays(p0, p1);
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
	string t0[] = {"26","14","72","39","32","85","06"};
			p0.assign(t0, t0 + sizeof(t0) / sizeof(t0[0]));
	p1 = 13;
	p2 = 5;
	all_right = KawigiEdit_RunTest(0, p0, p1, true, p2) && all_right;
	// ------------------
	}

	{
	// ----- test 1 -----
	string t0[] = {"26","14","72","39","32","85","06","91"};
			p0.assign(t0, t0 + sizeof(t0) / sizeof(t0[0]));
	p1 = 20;
	p2 = 8;
	all_right = KawigiEdit_RunTest(1, p0, p1, true, p2) && all_right;
	// ------------------
	}

	{
	// ----- test 2 -----
	string t0[] = {"SRM","512"};
			p0.assign(t0, t0 + sizeof(t0) / sizeof(t0[0]));
	p1 = 4;
	p2 = 0;
	all_right = KawigiEdit_RunTest(2, p0, p1, true, p2) && all_right;
	// ------------------
	}

	{
	// ----- test 3 -----
	string t0[] = {"Dear","Code","rsHa","veFu","nInT","heCh","alle","ngeP","hase","andb","ecar","eful"};
			p0.assign(t0, t0 + sizeof(t0) / sizeof(t0[0]));
	p1 = 256;
	p2 = 10;
	all_right = KawigiEdit_RunTest(3, p0, p1, true, p2) && all_right;
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