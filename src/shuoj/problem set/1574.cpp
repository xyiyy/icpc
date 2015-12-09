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
#include <cctype>

using namespace std;
#define XINF INT_MAX
#define INF 0x3FFFFFFF
#define MP(X, Y) make_pair(X,Y)
#define PB(X) push_back(X)
#define REP(X, N) for(int X=0;X<N;X++)
#define REP2(X, L, R) for(int X=L;X<=R;X++)
#define DEP(X, R, L) for(int X=R;X>=L;X--)
#define CLR(A, X) memset(A,X,sizeof(A))
#define IT iterator
typedef long long ll;
typedef pair<int, int> PII;
typedef vector<PII> VII;
typedef vector<int> VI;
int n, m;
PII a[100010];
int l[100010], r[100010], z[100010];
#define f first
#define s second

int main() {
//	ios::sync_with_stdio(false);
    while (scanf("%d%d", &n, &m) != EOF) {

        CLR(a, 0);
        for (int i = 0; i < m; i++) {
            scanf("%d%d%d", &l[i], &r[i], &z[i]);
            z[i] -= 2;
        }
        for (int i = m - 1; i >= 0; i--) {
            for (int j = l[i]; j <= r[i];) {
                if (!a[j].f) {
                    a[j].f = r[i];
                    a[j].s = z[i];
                    j++;
                }
                else {
                    j = a[j].f + 1;
                }
            }
        }
        int sum = 0;
        for (int i = 0; i < 100010; i++) {
            sum += a[i].s;
        }
        printf("%d\n", sum);
    }

    return 0;
}


