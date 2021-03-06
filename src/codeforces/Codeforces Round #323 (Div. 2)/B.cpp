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
int a[1010];

int main() {
    ios::sync_with_stdio(false);
#ifdef LOCAL
        freopen("in.txt","r",stdin);
    #endif // LOCAL
    int n;
    cin >> n;
    rep(i, n)cin >> a[i];
    int num = 0;
    int ans = 0;
    while (ans < n) {
        if (num & 1) {
            dep(i, n - 1, 0) {
                if (a[i] <= ans) {
                    a[i] = INF;
                    ans++;
                }
            }
        } else {
            rep(i, n) {
                if (a[i] <= ans) {
                    a[i] = INF;
                    ans++;
                }
            }
        }
        if (ans == n)break;
        num++;
    }
    cout << num << endl;
    return 0;
}

