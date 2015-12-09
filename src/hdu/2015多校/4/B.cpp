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
ll a[1000100];

int Scan() {
    int res = 0, ch;
    while (ch = getchar(), ch < '0' || ch > '9');
    res = ch - '0';
    while ((ch = getchar()) >= '0' && ch <= '9')
        res = res * 10 + ch - '0';
    return res;
}

void Out(int a) {
    if (a > 9)
        Out(a / 10);
    putchar(a % 10 + '0');
}

int main() {
    ios::sync_with_stdio(false);
    int t;
    t = Scan();
    while (t--) {
        int n = Scan();
        for (int i = 0; i < n; i++)a[i] = Scan();
        if (n == 1 || n == 2) {
            Out(n);
            puts("");
            continue;
        }
        int ans = 2;
        for (int i = 1; i < n;) {
            int tmp = a[i] - a[i - 1];
            int len = 2;
            i++;
            while (i < n) {
                if (a[i] - a[i - 1] == tmp)len++, i++;
                else break;
            }
            ans = max(ans, len);
        }
        for (int i = 1; i < n;) {
            int len = 2;
            i++;
            while (i < n) {
                if (a[i - 1] * a[i - 1] == a[i] * a[i - 2])len++, i++;
                else break;
            }
            ans = max(ans, len);
        }
        Out(ans);
        puts("");
    }

    return 0;
}



