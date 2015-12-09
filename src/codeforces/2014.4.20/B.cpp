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
int a[20010][11];
int b[20010];
int x[200010], y[200010];
int chat[110];

int main() {
    //ios::sync_with_stdio(false);
    int n, m, k;
    scanf("%d%d%d", &n, &m, &k);
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            scanf("%d", &a[i][j]);
        }
    }
    //	int x,y;
    for (int i = 0; i < k; i++) {
        scanf("%d%d", &x[i], &y[i]);
        b[x[i] - 1]--;
        chat[y[i] - 1]++;

    }
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            if (a[i][j]) {
                b[i] += chat[j];
            }
        }
    }
    for (int i = 0; i < n; i++) {
        printf("%d ", b[i]);
    }
    printf("\n");
    return 0;
}

