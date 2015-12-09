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
struct node {
    char name[30];
    int num;
} team[105];

int main() {
    ios::sync_with_stdio(false);
    int t, n, s, x, y, mod, i, j, cnt;
    scanf("%d", &t);
    while (t--) {
        scanf("%d%d%d%d%d", &n, &s, &x, &y, &mod);
        for (i = 1; i <= n; i++)scanf("%s request %d pages", team[i].name, &team[i].num);
        cnt = s;
        for (i = 1; i <= n; i++) {
            while (1) {
                if (team[i].num <= cnt) {
                    printf("%d pages for %s\n", team[i].num, team[i].name);
                    cnt -= team[i].num;
                    break;
                } else {
                    printf("%d pages for %s\n", cnt, team[i].name);
                    s = (s * x + y) % mod;
                    if (s == 0)
                        s = (s * x + y) % mod;
                    cnt = s;
                }
            }
        }
        printf("\n");
    }

    return 0;
}


