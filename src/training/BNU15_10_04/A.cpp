//#####################
//Author:fraud
//Blog: http://www.cnblogs.com/fraud/
//#####################
//#pragma comment(linker, "/STACK:102400000,102400000")
#include <bits/stdc++.h>

using namespace std;
#define XINF INT_MAX
#define INF 0x3FFFFFFF
#define mp(X, Y) make_pair(X,Y)
#define pb(X) push_back(X)
#define rep(X, N) for(int X=0;X<N;X++)
#define rep2(X, L, R) for(int X=L;X<=R;X++)
#define dep(X, R, L) for(int X=R;X>=L;X--)
#define clr(A, X) memset(A,X,sizeof(A))
#define IT iterator
typedef long long ll;
typedef pair<int, int> PII;
typedef vector<PII> VII;
typedef vector<int> VI;
vector<PII> vec[2010];
int a[10010];
int tra[10010];

int cmp(PII x, PII y) {
    return x > y;
}

int main() {
    ios::sync_with_stdio(false);
#ifdef LOCAL
        freopen("in.txt","r",stdin);
    #endif // LOCAL
    int n, k;
    while (scanf("%d%d", &n, &k) != EOF) {
        int num = (1 << k);
        rep(i, num)vec[i].clear();
        rep(i, n) {
            int y;
            scanf("%d%d", &a[i], &y);
            int f = 0;
            rep(j, y) {
                int tmp;
                scanf("%d", &tmp);
                tmp--;
                f |= (1 << (tmp));
            }
            tra[i] = f;
            rep(j, num) {
                vec[j].pb(mp((f & j), a[i]));
            }
        }
        //cout << "ok"<<endl;
        rep(j, num)sort(vec[j].begin(), vec[j].end(), cmp);
        //cout << "ok"<<endl;
        int m;
        scanf("%d", &m);
        rep(i, m) {
            int x, t, f = 0, tmp;
            scanf("%d%d", &x, &t);
            rep(i, t) {
                scanf("%d", &tmp);
                tmp--;
                f |= (1 << tmp);
            }
            //cout << "ok" << f<<endl;
            x--;
            int ans = lower_bound(vec[f].begin(), vec[f].end(), mp((f & tra[x]), a[x]), cmp) -
                      lower_bound(vec[f].begin(), vec[f].end(), mp((f & tra[x]), INF), cmp);
            printf("%d\n", ans + 1);

        }

    }
    return 0;
}

