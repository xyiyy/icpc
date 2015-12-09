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
int a[50010];
ll num[40];
ll num2[40], num3[40];

int main() {
    ios::sync_with_stdio(false);
#ifdef LOCAL
        freopen("in.txt","r",stdin);
    #endif // LOCAL
    int t;
    scanf("%d", &t);
    int cas = 1;
    while (t--) {
        int n;
        scanf("%d", &n);
        clr(num, 0);
        rep(i, n)scanf("%d", &a[i]);
        printf("Case #%d: ", cas++);
        ll tot = (ll) n * (n + 1) / 2;
        clr(num2, 0);
        clr(num3, 0);
        double ans1 = 0;
        double ans2 = 0, ans3 = 0;
        rep(i, n) {
            ans1 += a[i];
            ans2 += a[i];
            ans3 += a[i];
            if (i) {
                ll tmp = a[i];
                rep(j, 31) {
                    if (!(tmp & 1))num[j] = 0;
                    else {
                        num2[j] = i;
                        num3[j] = i - num3[j];
                    }
                    ans1 += (num[j] * (1LL << j));
                    ans2 += (num2[j] * (1LL << j));
                    ans3 += (num3[j] * (1LL << j));
                    tmp >>= 1;
                }
            }
            ll tmp = a[i];
            int k = 0;
            while (tmp) {
                if (tmp & 1) {
                    num[k]++;
                    num2[k]++;
                    num3[k]++;
                }
                tmp >>= 1;
                k++;
            }
        }
        ans1 /= tot;
        ans2 /= tot;
        ans3 /= tot;
        printf("%.6f %.6f %.6f\n", ans1, ans2, ans3);
    }


    return 0;
}

