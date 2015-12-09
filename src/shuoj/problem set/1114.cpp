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
ll a[10];

int main() {
    ios::sync_with_stdio(false);
    ll n, m;
    while (cin >> n >> m) {
        a[0] = n;
        for (int i = 1; i < m; i++) {
            a[i] = a[i - 1] * 10 + n;
        }
        ll sum = 0;
        for (int i = 0; i < m; i++) {
            sum += a[i];
        }
        cout << sum << endl;
    }
    return 0;
}

