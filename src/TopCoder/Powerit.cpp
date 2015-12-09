Ä£°å
// BEGIN CUT HERE
PROBLEM STATEMENT
You are given three ints: n, k, and m.

For each i between 1 and n, inclusive, Fox Ciel calculated the number i^(2^k - 1).
("^" denotes exponentiation.)

Return the sum of all numbers Fox Ciel calculated, modulo m.

DEFINITION
Class:Powerit
Method:calc
Parameters:int, int, int
Returns:int
Method signature:int calc(int n, int k, int m)


CONSTRAINTS
-n will be between 1 and 1,000,000, inclusive.
-k will be between 1 and 400, inclusive.
-m will be between 2 and 1,000,000,000, inclusive.


EXAMPLES

0)
4
1
107

Returns: 10



1)
4
2
107

Returns: 100

We have k=2 and therefore (2^k - 1) = (2^2 - 1) = 3.
Fox Ciel calculated the numbers 1^3, 2^3, 3^3, and 4^3.
Their sum is 100, and 100 modulo 107 is 100.

2)
3
3
107

Returns: 69

The actual sum of Ciel's numbers is 2316, and 2316 modulo 107 is 69.

3)
1
400
107

Returns: 1



4)
10
2
10

Returns: 5



// END CUT HERE
#line 76 "Powerit.cpp"
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


class Powerit
{
        public:
        int calc(int n, int k, int m)
        {
                $CARETPOSITION$
        }
        $TESTCODE$
};

// BEGIN CUT HERE
int main()
{
        Powerit ___test;
        ___test.run_test(-1);
        return 0;
}
// END CUT HERE
