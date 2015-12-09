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
char s[100][100];

int main() {
    ios::sync_with_stdio(false);
    int t, n;
    cin >> t;
    while (t--) {
        cin >> n;
        CLR(s, 0);
        REP(i, n) {
            cin >> s[i];
        }
        int ans = 0;
        REP(i, n * 2 - 1) {
            int c = 0;
            int l = 0;
            //cout<<i<<endl;
            REP(j, n) {
                int x = i - j, y = j;
                if (x < 0 || x >= n) continue;
                //cout<<x<<" "<<y<<endl;
                if (s[x][y] == 'B' || s[x][y] == 'G') {
                    if (l == 0) c++;
                    l = 1;
                } else l = 0;
            }
            ans += c;
        }
        REP(i, n) reverse(s[i], s[i] + n);
        REP(i, n * 2 - 1) {
            int c = 0;
            int l = 0;
            REP(j, n) {
                int x = i - j, y = j;
                if (x < 0 || x >= n) continue;
                if (s[x][y] == 'R' || s[x][y] == 'G') {
                    if (l == 0) c++;
                    l = 1;
                } else l = 0;
            }
            ans += c;
        }

        cout << ans << endl;
    }
    return 0;
}

