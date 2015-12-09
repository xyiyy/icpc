Ä£°å
// BEGIN CUT HERE
PROBLEM STATEMENT
The card game War is usually played with 52 cards.
Alice and Bob enjoy the game so much that they have modified it to use N cards, and they have changed the rules significantly.
The rules of their game are as follows:

The cards are numbered from 0 to N-1.
At the beginning of the game, each of the N cards is assigned to either Alice or Bob with equal probability.
The choices are made independently of each other and there is no guarantee that the players will receive the same number of cards.

The game consists of a series of steps.
In each step, a pair of cards is selected uniformly at random from all possible pairs that consist of two distinct cards.
The owner of the lower-numbered card becomes the owner of both cards in the pair.
(If that player already owned both cards, nothing changes, but it still counts as a step.)

The game ends as soon as all cards are owned by the same player.
Note that the game can end without any steps if all cards are initially assigned to the same player.

Carol watches Alice and Bob play the game.
She likes peas, so she has invented the following rules for herself:
Before the beginning of the game Carol chooses a specific state, i.e., a specific way cards are distributed between Alice and Bob.
At the beginning of the game and also after each step, if the current state is Carol's chosen state, she eats a pea.

You are given Carol's chosen state as a string state.
For each valid i, state[i] is either 'A' or 'B', indicating whether card i is owned by Alice or Bob.

We are interested in the expected number of peas Carol will eat during a game.
This number can always be written as p / q, where p and q are positive coprime integers.
Let X be an integer such that X * q is congruent to p, modulo 1,000,000,007.
Return the value (X mod 1,000,000,007).

DEFINITION
Class:WarAndPeas
Method:expectedPeas
Parameters:string
Returns:int
Method signature:int expectedPeas(string state)


NOTES
-It can be proved that for the given constraints the return value always exists and it is unique.


CONSTRAINTS
-N will be between 2 and 1000, inclusive.
-The length of state will be exactly N.
-Each character of state will be 'A' or 'B'.


EXAMPLES

0)
"AB"

Returns: 250000002

The game will never be in Carol's chosen state after a step.
Therefore, Carol will only eat a single pea if the initial state of the game is her chosen state.
This happens with probability 1 / 4, hence the expected number of peas Carol will eat is also 1 / 4.
The correct return value is 250,000,002 because (4 * 250,000,002) mod 1,000,000,007 = 1.


1)
"BAB"

Returns: 375000003

The expected number of peas eaten by Carol is 3 / 8.
The correct return value is 375,000,003 because (375,000,003 * 8) mod 1,000,000,007 = 3.

2)
"AABBBBB"

Returns: 973437507

Here the expected number of peas eaten by Carol is 119 / 640.

3)
"BBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBB"

Returns: 500000004

In this test case the expected number of peas eaten by Carol is 1 / 2.

4)
"BABABBABAAABABBBBABABBABAABAAABAABAAAABBBBBBABBBBAB"

Returns: 330545639

For this state Carol is expected to eat 3095183339246779 / 13989277223419852125116563456 peas.

// END CUT HERE
#line 95 "WarAndPeas.cpp"
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


class WarAndPeas
{
        public:
        int expectedPeas(string state)
        {
                $CARETPOSITION$
        }
        $TESTCODE$
};

// BEGIN CUT HERE
int main()
{
        WarAndPeas ___test;
        ___test.run_test(-1);
        return 0;
}
// END CUT HERE
