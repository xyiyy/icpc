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
int N;
int a[500];

int main() {
    ios::sync_with_stdio(false);
    int T;
    cin >> T;
    while (T--) {
        int u, v, minn, maxn;
        memset(a, 0, sizeof(a));
        cin >> N;
        for (int i = 0; i < N; i++) {
            cin >> u >> v;
            maxn = (max(u, v) + 1) / 2;
            minn = (min(u, v) + 1) / 2;
            for (int j = minn; j <= maxn; j++) {
                a[j]++;
            }
        }
        maxn = 0;
        for (int i = 0; i < 500; i++) {
            maxn = max(a[i], maxn);
        }
        cout << maxn * 10 << endl;
    }

    return 0;
}

