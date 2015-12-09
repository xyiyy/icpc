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
vector<int> vs;

//set<int>s;
int main() {
    ios::sync_with_stdio(false);
#ifdef LOCAL
        freopen("in.txt","r",stdin);
    #endif // LOCAL
    int n;
    while (cin >> n) {
        vs.clear();
        if (!n) {
            cout << 1 << endl;
            cout << 0 << endl;
            continue;
        }
        int m = int(sqrt(n) + 1.0);
        for (int i = 2; i < m; i++) {
            if (n % i == 0) {
                vs.pb(i);
                if (1LL * i * i != n)vs.pb(n / i);
            }
        }
        vs.pb(n);
        // s.clear();
        sort(vs.begin(), vs.end());
        int sz = vs.size();
        // rep(i,sz)s.insert(vs[i]);
        int ans = 0;
        int st = 0;
        rep(i, sz) {
            int m = vs[i];
            int tmp = n;
            int f = 0;
            while (tmp % m == 0) {
                tmp /= m;
                m++;
                f++;
                //if(tmp%m!=0 (s.count(m)==0))
            }
            if (f > ans) {
                ans = f;
                st = vs[i];
            }
        }
        cout << ans << endl;
        rep(i, ans) {
            if (i)cout << "*";
            cout << st + i;
        }
        cout << endl;
    }
    return 0;
}

