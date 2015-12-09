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
#define mp(X, Y) make_pair(X,Y)
#define pb(X) push_back(X)
#define rep(X, N) for(int X=0;X<N;X++)
#define rep2(X, L, R) for(int X=L;X<=R;X++)
#define dep(X, R, L) for(int X=R;X>=L;X--)
#define clr(A, X) memset(A,X,sizeof(A))
#define IT iterator
typedef long long ll;
typedef pair<int, int> PII;
typedef vector<PII> VII;
typedef vector<int> VI;

int x[200010];
set<int> s;

int main() {
    ios::sync_with_stdio(false);
#ifdef LOCAL
        freopen("in.txt","r",stdin);
    #endif // LOCAL
    int n, k, a;
    while (scanf("%d%d%d", &n, &k, &a) != EOF) {
        int m;
        scanf("%d", &m);
        rep(i, m)scanf("%d", &x[i]);
        //ll tot = (ll) k * (a+1) - 1;
        int tot = (n + 1) / (a + 1);
        //cout << tot << endl;
        s.clear();
        s.insert(0);
        s.insert(n + 1);
        int ans = -1;
        rep(i, m) {
            int rx = *s.lower_bound(x[i]);
            int lx = *(--s.lower_bound(x[i]));
            if (rx == x[i])continue;
            s.insert(x[i]);
            //cout << lx << " " << rx << endl;
            int len = rx - lx;
            //if(rx != n + 1)len++;
            //if(lx!=0)len++;
            int num = (len) / (a + 1);
            tot -= num;
            tot += (x[i] - lx) / (a + 1) + (rx - x[i]) / (a + 1);
            //cout << tot <<endl;
            if (tot < k) {
                ans = i + 1;
                break;
            }

        }
        cout << ans << endl;

    }

    return 0;
}

