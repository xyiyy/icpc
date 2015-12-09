#include <iostream>
#include <sstream>
#include <ios>
#include <iomanip>
#include <functional>
#include <algorithm>
#include <vector>
#include <string>
#include <list>
#include <queue>
#include <deque>
#include <stack>
#include <set>
#include <map>
#include <cstdio>
#include <cstdlib>
#include <cmath>
#include <cstring>
#include <climits>

using namespace std;
#define XINF INT_MAX
#define INF 0x3FFFFFFF
#define MP(X, Y) make_pair(X,Y)
#define PB(X) push_back(X)
#define REP(X, N) for(int X=0;X<N;X++)
typedef pair<int, int> PII;
typedef vector<int> VI;
typedef long long ll;

int a[5001000];

int Scan() {
    int res = 0, ch;
    if (ch >= '0' && ch <= '9')
        res = ch - '0';
    while ((ch = getchar()) >= '0' && ch <= '9')
        res = res * 10 + ch - '0';

    return res;
}

bool cmp(int x, int y) {
    return x > y;
}

int main() {
//	ios::sync_with_stdio(false);
    int n, k;
    n = Scan();
    k = Scan();
    for (int i = 0; i < n; i++) {
        a[i] = Scan();
    }
    nth_element(a, a + n - k, a + n);
    printf("%d\n", a[n - k]);

    return 0;
}

