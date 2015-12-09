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
int sx[19] = {0, 0, 0, 0, 1, 1, 1, 2, 2, 2};
int sy[19] = {0, 0, 1, 2, 0, 1, 2, 0, 1, 2};
int dirx[4] = {0, 0, 1, 1};
int diry[4] = {0, 1, 0, 1};
int G[11][11];
int deg[11];
int a[10][10];

bool toposort() {
    queue<int> q;
    int num = 0;
    for (int i = 1; i <= 9; i++)if (!deg[i])q.push(i);
    while (!q.empty()) {
        int x = q.front();
        q.pop();
        num++;
        for (int i = 1; i <= 9; i++) {
            if (G[x][i]) {
                deg[i]--;
                if (!deg[i])q.push(i);
            }
        }
    }
    if (num != 9)return 0;
    return 1;
}

int main() {
    ios::sync_with_stdio(false);
    string strend = "ENDOFINPUT";
    string str;
    while (cin >> str) {
        if (str == strend)break;
        for (int i = 0; i < 4; i++) {
            for (int j = 0; j < 4; j++) {
                cin >> a[i][j];
            }
        }
        cin >> str;
        CLR(deg, 0);
        CLR(G, 0);
        for (int i = 1; i <= 9; i++) {
            int x = sx[i];
            int y = sy[i];
            for (int j = 0; j < 4; j++) {
                int tx = x + dirx[j];
                int ty = y + diry[j];
                int now = a[tx][ty];
                if (now != i && !G[i][now]) {
                    G[i][now] = 1;
                    deg[now]++;
                }
            }
        }
        if (toposort()) {
            cout << "THESE WINDOWS ARE CLEAN" << endl;
        } else {
            cout << "THESE WINDOWS ARE BROKEN" << endl;
        }
    }
    return 0;
}
