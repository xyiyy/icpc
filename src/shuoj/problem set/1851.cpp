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
const int maxn = 50010;
int a[maxn], b[maxn], id1[maxn];
int bit[maxn];
int l[maxn], r[maxn];
int num[maxn];
int id[maxn];
int n, m;
int B;
int cas = 0;
vector<int> vc[maxn];

bool cmp1(int x, int y) {
    return l[x] < l[y] && (l[x] == l[y] && r[x] < r[y]);
}

bool cmp(int x, int y) {
    return num[x] < num[y];
}

int sum(int i) {
    int s = 0;
    while (i > 0) {
        s += bit[i];
        i -= i & -i;
    }
    return s;
}

void add(int i, int x) {
    while (i <= n) {
        bit[i] += x;
        i += i & -i;
    }
}

void solve() {
    int j = 1;
    for (int i = 0; i < (n + B - 1) / B; i++) {
        int temp = (i + 1) * B;
        for (; j <= m; j++) {
            if (l[id[j]] <= temp) {
                vc[i].PB(id[j]);
            }
            else break;
        }
    }
    for (int i = 0; i < (n + B - 1) / B; i++) {
        int temp = 0;
        for (int j = 0, x = 1, y = 0; j < vc[i].size(); j++) {
            int t = vc[i][j];
            for (; y < r[t]; y++)
                update(y + 1, 1, temp);
            for (; y > r[t]; y--)
                update(y, -1, temp);
            for (; x < l[t]; x++)
                update(x, 1);
            for (; x > l[t]; x--)
                update(x - 1, -1);
            if (l[t] == r[t])continue;

        }


        int main() {
            ios::sync_with_stdio(false);
            scanf("%d", &n);
            num[0] = -INF;
            B = (int) sqrt(n + 0.5);
            for (int i = 1; i <= n; i++) {
                scanf("%d", &num[i]);
                id1[i] = i;
            }
            sort(id1 + 1, id1 + n + 1, cmp);
            cas = 0;
            for (int i = 1; i <= n; i++) {
                //cout<<id1[i]<<" ";
                if (num[id1[i]] != num[id1[i - 1]]) {
                    cas++;
                }
                a[id1[i]] = cas;
            }
            scanf("%d", &m);
            for (int i = 1; i <= m; i++) {
                scanf("%d%d", &l[i], &r[i]);
                /*CLR(bit,0);
                int ans=0;
                for(int j=1;j<l[i];j++)
                {
                    ans-=j-1-sum(a[j]);
                    add(a[j],1);
                }
                for(int j=l[i];j<=r[i];j++)
                {
                    ans+=j-1-sum(a[j]);
                    add(a[j],1);
                }
                cout<<ans<<endl;*/
                id[i] = i;
            }
            sort(id + 1, id + m + 1, cmp1);
            solve();
            return 0;
        }



