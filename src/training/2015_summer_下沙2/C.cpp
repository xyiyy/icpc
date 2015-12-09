//#####################
//Author:fraud
//Blog: http://www.cnblogs.com/fraud/
//#####################
//#pragma comment(linker, "/STACK:102400000,102400000")
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
const int maxn = 100010;
int a[maxn];

int main() {
    ios::sync_with_stdio(false);
    int n, c;
    int t;
    scanf("%d", &t);
    while (t--) {
        scanf("%d%d", &n, &c);
        for (int i = 0; i < n; i++) {
            scanf("%d", &a[i]);
        }
        sort(a, a + n);
        int l = 0, r = 1e9;
        int ans = 0;
        while (l <= r) {
            int last = 0;
            int cnt = 1;
            int mid = (l + r) / 2;
            for (int i = 0; i < n; i++) {
                if (a[last] + mid <= a[i]) {
                    cnt++;
                    last = i;
                }
            }
            if (cnt >= c) {
                ans = max(ans, mid);
                l = mid + 1;
            }
            else {
                r = mid - 1;
            }
        }
        printf("%d\n", ans);
    }


    return 0;
}
