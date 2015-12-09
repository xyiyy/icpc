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

struct point {
    int x, y;

    bool operator<(const point &b) const {
        if (x == b.x)return y < b.y;
        return x < b.x;
    }
};

int main() {
    ios::sync_with_stdio(false);
    int T, cas = 1, n, x, y;
    cin >> T;
    while (T--) {
        if (cas != 1)cout << endl;
        cout << "Case #" << cas++ << ":" << endl;
        multiset<point> ms;
        multiset<point>::iterator it;
        cin >> n;
        for (int i = 0; i < n; i++) {
            cin >> x >> y;
            point p;
            p.x = x;
            p.y = y;
            it = ms.lower_bound(p);
            if (it == ms.begin() || (--it)->y > y) {
                ms.insert(p);
                it = ms.upper_bound(p);
                while (it != ms.end() && it->y >= y)ms.erase(it++);
            }
            cout << ms.size() << endl;
        }
    }
    return 0;
}


