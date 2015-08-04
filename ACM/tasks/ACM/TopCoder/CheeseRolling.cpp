Ä£°å
// BEGIN CUT HERE
PROBLEM STATEMENT
N people (where N is a power of 2) are taking part in a single-elimination tournament in cheese rolling.
The diagram below illustrates the structure of the tournament bracket.





The people entering the tournament are numbered from 0 to N-1.
For each potential cheese rolling match you know who would win the match.
You are given this information encoded as a vector <string> wins with N elements, each containing N characters.
For each valid i and j, wins[i][j] is 'Y' if person i beats person j.
Otherwise, wins[i][j] is 'N'.
The relation is not necessarily transitive: it may be the case that person i beats person j, person j beats person k, and person k beats person i.


There are N! (N factorial) ways to assign the people to positions in the bracket.
Different assignments may produce a different winner of the tournament.
Return a vector<long long> with N elements.
For each valid i, element i of the return value should be the exact number of assignments for which person i wins the tournament.

DEFINITION
Class:CheeseRolling
Method:waysToWin
Parameters:vector <string>
Returns:vector<long long>
Method signature:vector<long long> waysToWin(vector <string> wins)


CONSTRAINTS
-N will be between 2 and 16, inclusive.
-N will be a power of 2.
-wins will contain exactly N elements.
-Each element of wins will have a length of exactly N.
-Each element of wins will be composed of the characters 'Y' and 'N'.
-For each i from 0 to N-1, wins[i][i] = 'N'.
-For all distinct integers i and j from 0 to N-1, exactly one of wins[i][j] and wins[j][i] will be 'Y'.


EXAMPLES

0)
{"NN",
 "YN"}

Returns: {0, 2 }

There are 2 ways to assign the players:

Player 0 goes to position 0 and player 1 goes to position 1.
Player 1 goes to position 0 and player 0 goes to position 1.

In both assignments, player 1 will win the match against player 0 because wins[1][0] = 'Y'.

1)
{"NYNY",
 "NNYN",
 "YNNY",
 "NYNN"}

Returns: {8, 0, 16, 0 }



2)
{"NYNYNYNY",
 "NNYNYNYY",
 "YNNNNNNN",
 "NYYNNYNY",
 "YNYYNYYY",
 "NYYNNNNN",
 "YNYYNYNN",
 "NNYNNYYN"}

Returns: {4096, 8960, 0, 2048, 23808, 0, 1408, 0 }



3)
{"NYNNNNYYNYYNNYNN",
 "NNNNNNNNNYYNYYNY",
 "YYNYYNNNNYYYYYYN",
 "YYNNYYYNYNNYYYNY",
 "YYNNNYYNYYNNNNYY",
 "YYYNNNNYYNNYYNYN",
 "NYYNNYNYNYNYYYYN",
 "NYYYYNNNYYNYNYYY",
 "YYYNNNYNNYYYYNNN",
 "NNNYNYNNNNNNYYNY",
 "NNNYYYYYNYNYYYNN",
 "YYNNYNNNNYNNYNNY",
 "YNNNYNNYNNNNNYNN",
 "NNNNYYNNYNNYNNYY",
 "YYNYNNNNYYYYYNNN",
 "YNYNNYYNYNYNYNYN"}

Returns: {331616878592, 37267079168, 2426798866432, 2606831599616, 994941665280, 1162501849088, 1888166674432, 4632734203904, 832881524736, 84707409920, 3007127748608, 55490052096, 17818550272, 254672666624, 629921447936, 1959311671296 }



4)
{"NYYYYYYYYYYYYYYY",
 "NNYYYYYYYYYYYYYY",
 "NNNYYYYYYYYYYYYY",
 "NNNNYYYYYYYYYYYY",
 "NNNNNYYYYYYYYYYY",
 "NNNNNNYYYYYYYYYY",
 "NNNNNNNYYYYYYYYY",
 "NNNNNNNNYYYYYYYY",
 "NNNNNNNNNYYYYYYY",
 "NNNNNNNNNNYYYYYY",
 "NNNNNNNNNNNYYYYY",
 "NNNNNNNNNNNNYYYY",
 "NNNNNNNNNNNNNYYY",
 "NNNNNNNNNNNNNNYY",
 "NNNNNNNNNNNNNNNY",
 "NNNNNNNNNNNNNNNN"}

Returns: {20922789888000, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0 }

Player 0 wins no matter how the positions are assigned, so the answer is 16! = 20922789888000.

// END CUT HERE
#line 127 "CheeseRolling.cpp"
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


class CheeseRolling
{
        public:
        vector<long long> waysToWin(vector <string> wins)
        {
                $CARETPOSITION$
        }
        $TESTCODE$
};

// BEGIN CUT HERE
int main()
{
        CheeseRolling ___test;
        ___test.run_test(-1);
        return 0;
}
// END CUT HERE
