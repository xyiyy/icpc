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
queue<int> q[200010];
int ans[200010];

int main() {
    ios::sync_with_stdio(false);
    int n;
    int maxx = 0;
    int num;
    cin >> n;
    for (int i = 0; i < n; i++) {
        cin >> num;
        a[num]++;
        q[num].push(i + 1);
        // maxx=max(maxx,num);
    }
    int tot = 0;
    int now = 0;
    while (1) {
        if (now > n)break;
        if (!a[now])break;
        if (a[now]) {
            ans[tot++] = q[now].front();
            q[now].pop();
            a[now]--;
        }
        if (a[now + 1])now++;
        else now -= 2;
        if (now < 0)break;
        //if(!a[now])break;
    }
    if (tot != n)cout << "Impossible" << endl;
    else {
        cout << "Possible" << endl;
        for (int i = 0; i < tot; i++) {
            cout << ans[i] << " ";

        }
        cout << endl;
    }
    return 0;
}



