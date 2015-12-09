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
int p[10100];
int v[101000];

int main() {
    ios::sync_with_stdio(false);
    int m, n, n1, cas;
    int b, s;
    int num;
    int ids, idnos;
    while (cin >> m >> n && (m || n)) {
        cout << "Case " << cas++ << ":" << endl;
        CLR(p, 0);
        CLR(v, 0);
        n1 = m - n;
        idnos = ids = num = 0;
        while (cin >> b >> s) {
            if (b == -1)break;
            if (b == 1 && ids < n) {
                ids++;
                p[num] = ids;
                v[num++] = 1;
            }
            else if (b == 0 && idnos < n1) {
                idnos++;
                p[num] = idnos;
                v[num++] = 0;
            }
            else if (b == 1 && s == 0 && ids == n && idnos < n1) {
                idnos++;
                p[num] = idnos;
                v[num++] = 0;
            }
            else if (b == 0 && s == 0 && idnos == n1 && ids < n) {
                ids++;
                p[num] = ids;
                v[num++] = 1;
            }
            else {
                p[num++] = 0;
            }
        }
        for (int i = 0; i < num; i++) {
            if (!p[i])cout << "Next flight leaves 6 hours" << endl;
            else if (v[i] == 1)cout << "Smoking: " << p[i] << endl;
            else if (v[i] == 0)cout << "No Smoking: " << p[i] << endl;
        }
        cout << endl;
    }

    return 0;
}


