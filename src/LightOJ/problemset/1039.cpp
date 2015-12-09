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
#define MP(X, Y, Z) make_pair(X,make_pair(Y,Z))
#define PB(X) push_back(X)
#define REP(X, N) for(int X=0;X<N;X++)
#define REP2(X, L, R) for(int X=L;X<=R;X++)
#define DEP(X, R, L) for(int X=R;X>=L;X--)
#define CLR(A, X) memset(A,X,sizeof(A))
#define IT iterator
typedef long long ll;
typedef pair<int, pair<int, int> > PII;
typedef vector<PII> VII;
typedef vector<int> VI;
bool vis[31][31][31];
int dp[31][31][31];
int dirx[6] = {-1, 0, 0, 1, 0, 0};
int diry[6] = {0, -1, 0, 0, 1, 0};
int dirz[6] = {0, 0, -1, 0, 0, 1};

int check(int x) {
    if (x == -1)return 25;
    if (x == 26)return 0;
    return x;

}

int main() {
    ios::sync_with_stdio(false);
    int t;
    int cas = 1;
    cin >> t;
    while (t--) {
        int n;
        string str1, str2;
        string s1, s2, s3;
        cin >> str1 >> str2 >> n;
        CLR(vis, 0);
        CLR(dp, 0);
        for (int i = 0; i < n; i++) {
            cin >> s1 >> s2 >> s3;
            for (int j = 0; j < s1.length(); j++) {
                for (int k = 0; k < s2.length(); k++) {
                    for (int l = 0; l < s3.length(); l++) {
                        vis[s1[j] - 'a'][s2[k] - 'a'][s3[l] - 'a'] = 1;
                    }
                }
            }
        }
        int ok = 0;
        queue<PII> q;
        cout << "Case " << cas++ << ": ";
        int x = str1[0] - 'a', y = str1[1] - 'a', z = str1[2] - 'a';
        int gx = str2[0] - 'a', gy = str2[1] - 'a', gz = str2[2] - 'a';
        if (vis[x][y][z] || vis[gx][gy][gz]) {
            cout << -1 << endl;
            continue;
        } else {
            q.push(MP(x, y, z));
            vis[x][y][z] = 1;
            dp[x][y][z] = 0;
        }
        while (!q.empty()) {
            PII p = q.front();
            x = p.first;
            y = p.second.first;
            z = p.second.second;
            q.pop();
            if (x == gx && y == gy && z == gz) {
                ok = 1;
                break;
            }
            for (int i = 0; i < 6; i++) {
                int tx = check(x + dirx[i]);
                int ty = check(y + diry[i]);
                int tz = check(z + dirz[i]);
                if (!vis[tx][ty][tz]) {
                    dp[tx][ty][tz] += dp[x][y][z] + 1;
                    vis[tx][ty][tz] = 1;
                    q.push(MP(tx, ty, tz));
                }
            }
        }
        if (ok)cout << dp[gx][gy][gz] << endl;
        else cout << -1 << endl;
    }
    return 0;
}
