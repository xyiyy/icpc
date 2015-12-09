//#####################
//Author:fraud
//Blog: http://www.cnblogs.com/fraud/
//#####################
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
#define MAXN 10010
int vis[MAXN];
int num[MAXN / 2];

int main() {
    num[0] = 2;
    int ct = 1;
    int cnt = MAXN;
    int m = 0, t = 2;
    memset(vis, 0, sizeof(vis));
    while (cnt >= t) {
        for (int i = 1; i <= MAXN; i++) {
            if (!vis[i]) {
                m++;
                if (m == t) {
                    vis[i] = 1;
                    m = 0;
                }
            }
        }
        cnt = 0;
        m = 0;
        for (int i = 1; i <= MAXN; i++)
            if (!vis[i])
                cnt++;
        for (int i = t + 1; i <= MAXN; i++)
            if (!vis[i]) {
                t = i;
                num[ct++] = t;
                break;
            }
    }
    int n;
    while (scanf("%d", &n) != EOF) {
        int i = 0;
        while (n >= num[i]) {
            n = n - n / num[i];
            i++;
        }
        printf("%d\n", n);
    }
    return 0;
}



