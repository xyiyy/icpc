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
int n, m, t;
int sx, sy, dx, dy;
char a[9][9];
int dirx[4] = {-1, 0, 0, 1};
int diry[4] = {0, 1, -1, 0};
int ret;

void dfs(int x, int y, int step) {
    if (x == dx && y == dy && step == 0)ret = 1;
    if (ret == 1)return;
    if (step <= 0)return;
    if (a[x][y] == 'X')return;
    if (x < 0 || y < 0 || x >= n || y >= m)return;
    if ((abs(x - dx) + abs(y - dy)) > step)return;
//	cout<<x<<" "<<y<<endl;
    a[x][y] = 'X';
    //cout<<t-step<<endl;
    /*for(int i=0;i<n;i++)
    {
        for(int j=0;j<m;j++)
        {
            cout<<a[i][j];
        }
        cout<<endl;
    }*/
//	system("pause");
    for (int i = 0; i < 4; i++) {
        dfs(x + dirx[i], y + diry[i], step - 1);
    }
    a[x][y] = '.';
}


int main() {
    ios::sync_with_stdio(false);
    while (cin >> n >> m >> t && (t || n || m)) {
        ret = 0;
        for (int i = 0; i < n; i++) {
            cin >> a[i];
            for (int j = 0; j < m; j++) {
                if (a[i][j] == 'S') {
                    sx = i;
                    sy = j;
                }
                else if (a[i][j] == 'D') {
                    dx = i;
                    dy = j;
                }
            }
        }
        /*	for(int i=0;i<n;i++)
            {
                for(int j=0;j<m;j++)
                {
                    cout<<a[i][j];
                }
                cout<<endl;
            }*/
        //cout<<dx<<" "<<dy<<" "<<sx<<" "<<sy<<endl;
        //cout<<"ok"<<endl;
        if (abs((abs(sx - dx) + abs(sy - dy)) - t) % 2 != 0) {
            ret = 0;
        }
        else {
            dfs(sx, sy, t);
        }
        if (ret) {
            cout << "YES" << endl;
        }
        else {
            cout << "NO" << endl;
        }
    }


    return 0;
}

