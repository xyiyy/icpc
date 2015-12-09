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

int main() {
    ios::sync_with_stdio(false);
    int c, d;
    int n, m, k;

    while (cin >> c >> d >> n >> m >> k) {
        int a;
        int sum = 0;
        a = m * n - k;
        if (a <= 0)sum = 0;
        else if (a % n == 0)
            sum = c * (a / n);
        else sum = c * (a / n + 1);

        cout << sum << endl;
    }


    return 0;
}

