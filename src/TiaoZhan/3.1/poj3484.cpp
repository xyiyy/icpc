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
char str[1000];
int tot = 1;
ll x[1000010], y[1000010], z[1000010];

int main() {
    ios::sync_with_stdio(false);
    while (gets(str)) {
        tot = 1;
        x[tot] = 0;
        sscanf(str, "%lld%lld%lld", &x[tot], &y[tot], &z[tot]);
        if (!x[tot])continue;
        CLR(str, 0);
        while (gets(str) && strlen(str) > 1) {
            ++tot;
            sscanf(str, "%lld%lld%lld", &x[tot], &y[tot], &z[tot]);
            CLR(str, 0);
        }
        ll l = 1, r = 1e11;
        while (l < r) {
            ll mid = (l + r) / 2;
            ll sum = 0, num;
            for (int i = 1; i <= tot; i++) {
                if (mid < x[i])continue;
                num = min(mid, y[i]);
                sum += (num - x[i]) / z[i] + 1;
            }
            if (sum & 1) {
                r = mid;
            }
            else {
                l = mid + 1;
            }
        }
        if (l == 1e11) {
            printf("no corruption\n");
        }
        else {
            ll sum1 = 0, sum2 = 0, num;
            for (int i = 1; i <= tot; i++) {
                if (l < x[i])continue;
                num = min(l, y[i]);
                sum1 += (num - x[i]) / z[i] + 1;
            }
            for (int i = 1; i <= tot; i++) {
                if (l - 1 < x[i])continue;
                num = min(l - 1, y[i]);
                sum2 += (num - x[i]) / z[i] + 1;
            }

            printf("%lld %lld\n", l, sum1 - sum2);
        }
    }

    return 0;
}


