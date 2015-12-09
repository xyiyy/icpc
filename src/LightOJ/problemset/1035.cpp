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
vector<PII> G[110];
int a[110];
vector<PII> ans;

int main() {
    ios::sync_with_stdio(false);
    int t;
    cin >> t;
    int cas = 1;
    for (int i = 2; i < 110; i++) {
        int tmp = i;
        for (int j = 2; j * j <= tmp; j++) {
            if (tmp % j == 0) {
                int num = 0;
                while (tmp % j == 0) {
                    tmp /= j;
                    num++;
                }
                G[i].PB(MP(j, num));
            }
        }
        if (tmp != 1)G[i].PB(MP(tmp, 1));
    }
    while (t--) {
        int n;
        cin >> n;
        CLR(a, 0);
        for (int i = 2; i <= n; i++) {
            for (int j = 0; j < G[i].size(); j++) {
                a[G[i][j].first] += G[i][j].second;
            }
        }

        cout << "Case " << cas++ << ": " << n << " =";
        ans.clear();
        for (int i = 0; i <= n; i++) {
            if (a[i])ans.PB(MP(i, a[i]));
        }
        for (int i = 0; i < ans.size(); i++) {
            if (i)cout << " *";
            cout << " " << ans[i].first << " (" << ans[i].second << ")";
        }
        cout << endl;
    }


    return 0;
}
