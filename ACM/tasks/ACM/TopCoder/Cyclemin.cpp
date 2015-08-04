Ä£°å
// BEGIN CUT HERE
PROBLEM STATEMENT
A rotation of a string S is the operation of moving its first character to the end.
For example, if we rotate the string "abcde" we get the string "bcdea".

A cyclic shift of a string S is any string that can be obtained from S by a sequence of zero or more rotations.
For example, the strings "abcde", "cdeab", and "eabcd" are some of the cyclic shifts of the string "abcde".

Given two equally long strings, the smaller one is the one with a smaller character at the first index where they differ.
For example, "cable" < "cards" because 'b' < 'r'.

You are given a string s of lowercase letters and an int k.
You are allowed to change at most k letters of s into some other lowercase letters.
Your goal is to create a string that will have the smallest possible cyclic shift.
Compute and return that cyclic shift.

DEFINITION
Class:Cyclemin
Method:bestmod
Parameters:string, int
Returns:string
Method signature:string bestmod(string s, int k)


CONSTRAINTS
-s will contain between 1 and 50 characters, inclusive.
-Each character in s will be between 'a' and 'z', inclusive.
-k will be between 0 and the length of s, inclusive.


EXAMPLES

0)
"aba"
1

Returns: "aaa"

We are allowed to change at most 1 character. Clearly, the optimal change is to change the 'b' into an 'a'.

1)
"aba"
0

Returns: "aab"

We are not allowed to change anything. In this case, the answer is the smallest cyclic shift of the given string s.

2)
"bbb"
2

Returns: "aab"



3)
"sgsgaw"
1

Returns: "aasgsg"

The optimal solution is to change the 'w' into an 'a', and then to take the cyclic shift that starts with the last two letters of s.

4)
"abacaba"
1

Returns: "aaaabac"



5)
"isgbiao"
2

Returns: "aaaisgb"



// END CUT HERE
#line 84 "Cyclemin.cpp"
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


class Cyclemin
{
        public:
        string bestmod(string s, int k)
        {
                $CARETPOSITION$
        }
        $TESTCODE$
};

// BEGIN CUT HERE
int main()
{
        Cyclemin ___test;
        ___test.run_test(-1);
        return 0;
}
// END CUT HERE
