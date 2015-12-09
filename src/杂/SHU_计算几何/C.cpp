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
#define REP2(X, L, R) for(int X=L;X<=R;X++)
#define IT iterator
typedef long long ll;
typedef pair<int, int> PII;
typedef vector<PII> VII;
typedef vector<int> VI;

#define MAXN 25010
#define MAXD 1000000

//int X1[MAXN], Y1[MAXN], X2[MAXN], Y2[MAXN], id[MAXN], over[MAXN];

int X[MAXN * 2], Y1[MAXN * 2], Y2[MAXN * 2], id1[MAXN * 2];

int Y[MAXN * 2], X1[MAXN * 2], X2[MAXN * 2], id2[MAXN * 2];

int overlap[MAXN];

int cmpx(const int a, const int b) {
    if (X[a] != X[b])
        return X[a] < X[b];
    else
        return Y1[a] < Y1[b];
}

int cmpy(const int a, const int b) {
    if (Y[a] != Y[b])
        return Y[a] < Y[b];
    else
        return X1[a] < X1[b];
}

int main() {
    //ios::sync_with_stdio(false);
    int n;
    while (~scanf("%d", &n)) {
        int x_1, y_1, x_2, y_2;
        REP(i, n) {
            scanf("%d %d %d %d", &x_1, &y_1, &x_2, &y_2);
            //cin>>x_1>>y_1>>x_2>>y_2;
            X[2 * i] = x_1;
            X[2 * i + 1] = x_2;
            Y1[2 * i] = Y1[2 * i + 1] = y_1;
            Y2[2 * i] = Y2[2 * i + 1] = y_2;

            Y[2 * i] = y_1;
            Y[2 * i + 1] = y_2;
            X1[2 * i] = X1[2 * i + 1] = x_1;
            X2[2 * i] = X2[2 * i + 1] = x_2;

            overlap[i] = 0;
            id1[2 * i] = id2[2 * i] = 2 * i;
            id1[2 * i + 1] = id2[2 * i + 1] = 2 * i + 1;
        }
        sort(id1, id1 + 2 * n, cmpx);
        sort(id2, id2 + 2 * n, cmpy);
        int l = -1, r = -1;
        REP(k, 2 * n - 1) {
            int i = id1[k], j = id1[k + 1];
            if (X[i] == X[j]) {
                if (i & 1) l = i; else r = i;
                if (j & 1 && r != -1 && Y1[j] <= Y2[r]) overlap[r / 2] = overlap[j / 2] = 1;
                if (!(j & 1) && l != -1 && Y1[j] <= Y2[l]) overlap[l / 2] = overlap[j / 2] = 1;
            } else {
                l = r = -1;
            }
        }
        l = r = -1;
        REP(k, 2 * n - 1) {
            int i = id2[k], j = id2[k + 1];
            if (Y[i] == Y[j]) {
                if (i & 1) l = i; else r = i;
                if (j & 1 && r != -1 && X1[j] <= X2[r]) overlap[r / 2] = overlap[j / 2] = 1;
                if (!(j & 1) && l != -1 && X1[j] <= X2[l]) overlap[l / 2] = overlap[j / 2] = 1;
            } else {
                l = r = -1;
            }
        }
        int ans = 0;
        REP(i, n) if (!overlap[i]) ans++;
        printf("%d\n", ans);
    }
    return 0;
}

