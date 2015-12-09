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
int a[200010];
int b[100010];

int main() {
    ios::sync_with_stdio(false);
    int n;
    int flag = 1;
    int id;
    while (cin >> n) {
        id = 0;
        flag = 1;
        for (int i = 0; i < n; i++) {
            cin >> a[i];
        }
        for (int i = 0; i < n - 1; i++) {
            if (a[i] > a[i + 1]) {
                id = i + 1;
            }
        }
        int j = 0;
        for (int i = id; i < n; i++) {
            b[j] = a[i];
            j++;
        }
        for (int i = 0; i < id; i++) {
            b[j] = a[i];
            j++;
        }
        for (int i = 1; i < n; i++) {
            if (b[i] < b[i - 1]) {
                flag = 0;
                break;
            }
        }
        if (!flag)cout << -1 << endl;
        else if (id)cout << n - id << endl;
        else cout << 0 << endl;


    }

    return 0;
}

