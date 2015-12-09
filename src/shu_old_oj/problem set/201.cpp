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
int a[30010];

int main() {
    ios::sync_with_stdio(false);
    int key = 1, num = 3;
    for (int i = 0; i < 10010;) {
        for (int j = key, k = 0; k < num; j++) {
            //	if(j!=key)
            i++;
            a[i] = key + k;
            k++;
        }
        num++;
        key++;
    }
    int t, m;
    cin >> t;
    while (t--) {
        cin >> m;
        cout << a[m] << endl;
    }
    return 0;
}


