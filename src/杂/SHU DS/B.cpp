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
const int maxn = (200000 + 10) * 3;
int n, q;

struct Seg {
    int is[maxn];
    int N;

    void init() {
        N = 1;
        while (N < n) N <<= 1;
        for (int i = 0; i < n; i++) {
            scanf("%d", &is[i + N]);
        }
        for (int i = n; i < N; i++) {
            is[i + N] = -12345678;
        }
        for (int i = N - 1; i > 0; i--) {
            is[i] = max(is[i * 2], is[i * 2 + 1]);
        }
    }

    void update(int k, int a) {
        is[N + k] = a;
        for (int i = (N + k) / 2; i > 0; i >>= 1) {
            is[i] = max(is[i * 2], is[i * 2 + 1]);
        }
    }

    int query(int s, int t) {
        int res = -12345678;
        while (0 < s && s + (s & -s) <= t) {
            int i = (N + s) / (s & -s);
            res = max(res, is[i]);
            s += s & -s;
        }
        while (s < t) {
            int i = (N + t) / (t & -t) - 1;
            res = max(res, is[i]);
            t -= t & -t;
        }
        return res;
    }
} seg;


int main() {
//	ios::sync_with_stdio(false);
    while (scanf("%d%d", &n, &q) != EOF) {
        seg.init();
        char buf;
        int x, y;
        while (q--) {
            scanf("%*[\n]%c %d %d", &buf, &x, &y);
            x--;
            //	cout<<buf<<endl;
            if (buf == 'Q') {
                printf("%d\n", seg.query(x, y));
            }
            else {
                seg.update(x, y);
            }
        }
    }
    return 0;
}

