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
const int maxn = 1010;
char a[maxn];
char b[110] = "marshtomp";
int c[maxn];
char d[maxn];

int main() {
    ios::sync_with_stdio(false);
    while (cin.getline(a, maxn, '\n')) {
        memset(c, 0, sizeof(c));
        int len = strlen(a);
        for (int i = 0; i < len; i++) {
            d[i] = a[i];
        }
        for (int i = 0; i < len; i++) {
            if (a[i] >= 'A' && a[i] <= 'Z') {
                a[i] += 'a' - 'A';
            }
        }
        int l = strlen(b);
        int flag = 1;
        for (int i = 0; i <= len - l; i++) {
            c[i] = 1;
            for (int j = 0; j < l; j++) {
                if (j + i >= len)break;
                if (a[i + j] != b[j])
                    c[i] = 0;
            }
        }
        for (int i = 0; i < len; i++) {
            if (c[i] == 1) {
                cout << "fjxmlhx";
                i += l - 1;
            }
            else cout << d[i];
        }
        cout << endl;
        memset(a, 0, sizeof(a));
        memset(d, 0, sizeof(d));
    }
    return 0;
}




