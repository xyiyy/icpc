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
int N, tot;
int vis[3][100];

void search(int cur) {
    int i;
    if (cur == N) tot++;
    else
        for (i = 0; i < N; i++) {
            if (!vis[0][i] && !vis[1][cur + i] && !vis[2][cur - i + 10]) {
                vis[0][i] = vis[1][cur + i] = vis[2][10 + cur - i] = 1;
                search(cur + 1);
                vis[0][i] = vis[1][cur + i] = vis[2][10 + cur - i] = 0;
            }
        }
}


int main() {
    int ans[15];
    for (int i = 0; i < 10; i++) {
        tot = 0;
        N = i + 1;
        memset(vis, 0, sizeof(vis));
        search(0);
        ans[i] = tot;
    }
    while (cin >> N && N) {
        //	int cur=0;
        cout << ans[N - 1] << endl;
    }

    return 0;
}
