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
double Map[35][35];
int n, m;
int cas = 1;
double rate;
char s[1100], s1[1100], s2[1100];

int main() {
    //ios::sync_with_stdio(false);
    while (~scanf("%d", &n) && n) {
        for (int i = 1; i <= n; i++) {
            for (int j = 1; j <= n; j++) {
                if (i == j)
                    Map[i][j] = 1;
                else
                    Map[i][j] = 0;
            }
        }
        map<string, int> mp;
        for (int i = 1; i <= n; i++) {
            scanf("%s", s);
            mp[s] = i;
        }
        scanf("%d", &m);
        for (int i = 0; i < m; i++) {
            CLR(s1, 0);
            CLR(s2, 0);
            scanf("%s%lf%s", s1, &rate, s2);
            int u = mp[s1], v = mp[s2];
            Map[u][v] = rate;
        }
        for (int k = 1; k <= n; k++) {
            for (int i = 1; i <= n; i++) {
                for (int j = 1; j <= n; j++) {
                    if (Map[i][j] < Map[i][k] * Map[k][j])
                        Map[i][j] = Map[i][k] * Map[k][j];
                }
            }
        }
        bool flag = false;
        for (int i = 1; i <= n; i++) {
            if (Map[i][i] > 1) {
                flag = true;
                break;
            }
        }
        printf("Case %d: ", cas++);
        printf("%s\n", flag ? "Yes" : "No");
    }
    return 0;
}

