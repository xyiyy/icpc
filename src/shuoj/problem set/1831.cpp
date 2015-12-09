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

int main() {
    ios::sync_with_stdio(false);
    queue<PII> q;
    int n, m, k;
    int num;
    while (cin >> n >> m) {

        for (int i = 1; i <= n; i++) {
            cin >> k;
            q.push(MP(k, i));
        }
        num = 0;
        while (q.size() > 1) {
            num++;
            num %= m;
            if (num == 0) {
                m = q.front().first;
                q.pop();
            }
            else {
                q.push(q.front());
                q.pop();
            }
        }
        cout << q.front().second << endl;
        q.pop();
    }


    return 0;
}
