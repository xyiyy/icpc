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
char a[110][110];
char b[110][110];
int n;
bool us[110][110];
bool vis[10010];
vector<int> px;
vector<int> py;
map<int, int> ms;
vector<int> gao;
vector<int> ansx;
vector<int> ansy;

bool in(int x, int y) {
    if (x >= 0 && x < n && y < n && y >= 0 && us[x][y] == 0)return 1;
    return 0;
}

int main() {
    ios::sync_with_stdio(false);
    cin >> n;
    int cao = 0;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            cin >> a[i][j];
            if (a[i][j] == 'o') {
                px.PB(i);
                py.PB(j);
                //gao.PB(i*n+j);
                us[i][j] = 1;

            }
            else if (a[i][j] == 'x') {
                gao.PB(i * n + j);
                cao++;
                us[i][j] = 1;
            }
        }
    }
    //cout<<"fas"<<endl;
    int num = 0;
    int sz = px.size();
    bool ok = 0;
    int tx = px[0], ty = py[0];
    //cout<<tx<<" "<<ty<<endl;
    for (int i = 0; i < cao; i++) {
        int dx = gao[i] / n - tx;
        int dy = gao[i] % n - ty;
        // cout<<dx<<" "<<dy<<endl;
        for (int j = 1; j < sz; j++) {
            if (in(px[j] + dx, py[j] + dy)) {
                vis[i] = 1;
            }
        }
        //  cout<<i<<" "<<vis[i]<<endl;
        if (!vis[i]) {
            ansx.PB(dx);
            ansy.PB(dy);
        }
    }
    // cout<<"afas"<<endl;
    for (int i = 0; i < cao; i++) {
        if (vis[i]) {
            bool fuc = 0;
            for (int j = 1; j < sz; j++) {
                fuc = 1;
                int dx = gao[i] / n - px[j];
                int dy = gao[i] % n - py[j];
                for (int k = 0; k < sz; k++) {
                    if (in(px[k] + dx, py[k] + dy)) {
                        fuc = 0;
                        break;
                    }
                }
                if (fuc) {
                    vis[i] = 0;
                    ansx.PB(dx);
                    ansy.PB(dy);
                    break;
                }
            }
        }

    }
    if (ansx.size() < cao) {
        cout << "NO" << endl;
        return 0;
    }
    for (int i = 0; i < 2 * n - 1; i++) {
        for (int j = 0; j < 2 * n - 1; j++) {
            b[i][j] = '.';
        }
    }
    for (int i = 0; i < cao; i++) {
        int dx = ansx[i];
        int dy = ansy[i];
        b[n - 1 + dx][n - 1 + dy] = 'x';
    }
    b[n - 1][n - 1] = 'o';
    cout << "YES" << endl;
    for (int i = 0; i < 2 * n - 1; i++) {
        for (int j = 0; j < 2 * n - 1; j++) {
            cout << b[i][j];
        }
        cout << endl;
    }


    return 0;
}



