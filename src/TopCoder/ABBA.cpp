Ä£°å
// BEGIN CUT HERE
        PROBLEM
STATEMENT
        One
day,
Jamie noticed
that many
English words
only use
the letters
A andB
.
Examples of
such words
include "AB" (short for abdominal), "BAA" (
the noise
a sheep
makes), "AA" (
a type
of lava
), and "ABBA" (
a Swedish
pop sensation
).

Inspired by
this observation,
Jamie created
a simple
game.
You are
given two
strings: initial
and target.
The goal
of the
game is
to find
a sequence
of valid
moves that
will change
initial into
target.
There are
two types
of valid
moves:

        Add
the letter
A to
the end
of the
string.
Reverse the
string andthen
add the
letter B
to the
end of
the string
.


Return "Possible" (quotes for clarity) if
there is
a sequence
of valid
moves that
will change
initial into
target.
Otherwise, return "Impossible".

DEFINITION
        Class:
ABBA
        Method:
canObtain
        Parameters:
string,
string
        Returns:
string
        Method
signature: string
canObtain(string
initial,
string target
)


CONSTRAINTS
-
The length
of initial
will be
between 1 and 999, inclusive.
-
The length
of target
will be
between 2 and 1000, inclusive.
-
target will
be longer
than initial
.
-
Each character
in initial
and
each character
in target
will be
either 'A' or 'B'.


EXAMPLES

0)
"B"
"ABBA"

Returns:
"Possible"

Jamie can
perform the
following moves:

Initially,
the string
is "B".
Jamie adds
an 'A'
to the
end of
the string
.
Now the
string is
"BA".
Jamie reverses
the string
and
then adds
a 'B'
to the
end of
the string
.
Now the
string is
"ABB".
Jamie adds
an 'A'
to the
end of
the string
.
Now the
string is
"ABBA".

Since there
is a
sequence of
moves which
starts with
"B" and
creates the
string "ABBA",
the answer
is "Possible".

1)
"AB"
"ABB"

Returns:
"Impossible"

The only
strings of
length 3
Jamie can
create are
"ABA" and "BAB".

2)
"BBAB"
"ABABABABB"

Returns:
"Impossible"



3)
"BBBBABABBBBBBA"
"BBBBABABBABBBBBBABABBBBBBBBABAABBBAA"

Returns:
"Possible"



4)
"A"
"BB"

Returns:
"Impossible"



// END CUT HERE
#line 85 "ABBA.cpp"

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

#define REP(i, n) for(i=0;i<(n);++i)
#define FOR(i, l, h) for(i=(l);i<=(h);++i)
#define FORD(i, h, l) for(i=(h);i>=(l);--i)

typedef vector<int> VI;
typedef vector<string> VS;
typedef vector<double> VD;
typedef long long LL;
typedef pair<int, int> PII;


class ABBA {
public:
    string canObtain(string initial, string target) {
        $CARETPOSITION$
    }

    $TESTCODE$
};

// BEGIN CUT HERE
int main() {
    ABBA ___test;
    ___test.run_test(-1);
    return 0;
}
// END CUT HERE
