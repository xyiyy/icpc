Ä£°å
// BEGIN CUT HERE
PROBLEM STATEMENT
Hero is inviting his friends to the party.
He has n friends, numbered 0 through n-1.
For each of his friends there is at most one other person the friend dislikes.
You are given this information as a vector <int> a with n elements.
For each i, a[i] is either the number of the person disliked by friend i, we have a[i]=i if friend i likes everybody else.

Hero is inviting his friends one at a time.
Whenever he invites friend i, they will accept if and only if the friend a[i] didn't accept an earlier invitation.
(That includes two cases: either Hero didn't invite friend a[i] yet, or he did but the friend rejected the invitation.)

Hero noticed that the order in which he invites his friends matters: different orders may produce different numbers of accepted invitations.

Find an order that will produce the most accepted invitations, and return their number.


DEFINITION
Class:PrivateD2party
Method:getsz
Parameters:vector <int>
Returns:int
Method signature:int getsz(vector <int> a)


CONSTRAINTS
-a will contain exactly n elements.
-n will be between 1 and 50, inclusive.
-Each element of a will be between 0 and n - 1, inclusive.


EXAMPLES

0)
{0,1}

Returns: 2

Each of the friends likes the other. Regardless of the order in which Hero asks them, they will both accept the invitation.

1)
{1,0}

Returns: 1

Friend 0 dislikes friend 1 and vice versa. The first friend Hero asks will accept the invitation but then the other friend will certainly reject it.

2)
{1,0,3,2}

Returns: 2



3)
{5,2,2,4,5,0}

Returns: 5

Here is what would happen if Hero invited the friends in the order (0,1,2,3,4,5):

Friend 5 didn't accept yet, so friend 0 would accept.
Friend 2 didn't accept yet, so friend 1 would accept.
Friend 2 likes everybody and therefore they would accept.
Friend 4 didn't accept yet, so friend 3 would accept.
Friend 5 didn't accept yet, so friend 4 would accept.
Friend 0 did already accept, therefore friend 5 would reject.

It turns out that this solution happens to be optimal: there is no order such that all six friends would accept the invitations.

4)
{3,2,1,0,5,4}

Returns: 3



// END CUT HERE
#line 81 "PrivateD2party.cpp"
#include <cstdlib>
#include <cctype>
#include <cstring>
#include <cstdio>
#include <cmath>
#include <algorithm>
#include <vector>
#include <string>
#include <iostream>
#include <sstream>
#include <map>
#include <set>
#include <queue>
#include <stack>
#include <fstream>
#include <numeric>
#include <iomanip>
#include <bitset>
#include <list>
#include <stdexcept>
#include <functional>
#include <utility>
#include <ctime>
using namespace std;

#define PB push_back
#define MP make_pair

#define REP(i,n) for(i=0;i<(n);++i)
#define FOR(i,l,h) for(i=(l);i<=(h);++i)
#define FORD(i,h,l) for(i=(h);i>=(l);--i)

typedef vector<int> VI;
typedef vector<string> VS;
typedef vector<double> VD;
typedef long long LL;
typedef pair<int,int> PII;


class PrivateD2party
{
        public:
        int getsz(vector <int> a)
        {
                $CARETPOSITION$
        }
        $TESTCODE$
};

// BEGIN CUT HERE
int main()
{
        PrivateD2party ___test;
        ___test.run_test(-1);
        return 0;
}
// END CUT HERE
