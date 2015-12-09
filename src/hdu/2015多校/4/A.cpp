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
int gg[100010];
int vis[10];

int main() {
    ios::sync_with_stdio(false);
    for (int i = 1; i < 100010; i++) {
        int tmp = i;
        int x;
        CLR(vis, 0);
        int f = 1;
        while (tmp) {
            x = tmp % 10;
            if (!vis[x])vis[x] = 1;
            else {
                f = 0;
                break;
            }
            tmp /= 10;
        }
        gg[i] = f;
    }
    for (int i = 1; i < 100010; i++)gg[i] += gg[i - 1];
    int a, b;
    int t;
    cin >> t;
    while (t--) {
        cin >> a >> b;
        cout << gg[b] - gg[a - 1] << endl;
    }

    return 0;
}



