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
int l[30010], r[30010];
int id[30010];

bool cmp(int x, int y) {
    if (l[x] == l[y])return r[x] < r[y];
    return l[x] < l[y];
}

int main() {
    ios::sync_with_stdio(false);
    int n, t;
    while (cin >> n >> t) {
        for (int i = 0; i < n; i++) {
            cin >> l[i] >> r[i];
            id[i] = i;
        }
        sort(id, id + n, cmp);
        int rx = 0;
        int rmax;
        //cout<<l[id[0]]<<endl;
        int ans = 0;
        int flag = 0;
        for (int i = 0; i < n && !flag; i++) {
            if (l[id[i]] <= rx + 1) {
                rmax = r[id[i]];
                while (l[id[i]] <= rx + 1 && i < n) {
                    rmax = max(rmax, r[id[i]]);
                    i++;
                }
                i--;
                ans++;
                rx = rmax;
                if (rx == t)break;
            }
            else {
                flag = 1;
            }
        }
        if (rx < t || flag) {
            cout << -1 << endl;
        }
        else cout << ans << endl;
    }
    return 0;
}


