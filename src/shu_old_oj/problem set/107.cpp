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
int a[10];

int main() {
    ios::sync_with_stdio(false);
    int n, k = 1;
    a[0] = 10;
    for (int i = 1; i < 9; i++) {
        a[i] = a[i - 1] * 10;
    }
    int i;
    while (cin >> n) {
        cout << "Case " << k++ << ": " << n << ", ";
        for (i = 0; i < 9; i++) {
            if (a[i] > n)break;
        }
        if (n * n % a[i] == n)cout << "Yes" << endl;
        else cout << "No" << endl;
    }
    return 0;
}

