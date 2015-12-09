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
int vis[8];
char a[8][110] = {"vaporeon", "jolteon", "flareon", "espeon", "umbreon", "leafeon", "glaceon", "sylveon"};

int main() {
    ios::sync_with_stdio(false);
    int n;
    char b[110];
    while (cin >> n) {
        CLR(b, 0);
        CLR(vis, 0);
        cin >> b;
        for (int i = 0; i < 8; i++) {
            if (strlen(a[i]) != n)vis[i] = 1;
        }
        for (int i = 0; i < n; i++) {
            if (b[i] == '.')
                continue;
            for (int j = 0; j < 8; j++) {
                if (a[j][i] == b[i] && !vis[j]) {
                    break;
                }
                else vis[j] = 1;
            }

        }
        for (int i = 0; i < 8; i++) {
            if (!vis[i]) {
                cout << a[i] << endl;
                break;
            }
        }
    }


    return 0;
}


