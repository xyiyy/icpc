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
const double PI = acos(-1.0);

/*inline int sqr(int x){
    return x * x;
}
const double EPS = 1e-8;
int sig(double x){
    if(fabs(x) < EPS)return 0;
    if(x > 0)return 1;
    return -1;
}
struct P{
    int x,y;
    P (){}
    P (int a,int b):x(a),y(b){}
    void input(){
        scanf("%d%d",&x,&y);
    }
    friend P operator + (const P &a, const P & b){
        return P(a.x + b.x, a.y + b.y);
    }
    friend P operator - (const P &a, const P & b){
        return P(a.x - b.x, a.y - b.y);
    }
    friend bool operator == (const P &a, const P & b){
        return sig(a.x - b.x) == 0 && sig(a.y - b.y) == 0;
    }
    friend P operator * (const P &a, const double & b){
        return P(a.x * b, a.y * b);
    }
    friend P operator * (const double &a, const P & b){
        return P(a * b.x, a * b.y);
    }
    friend P operator / (const P &a, const double & b){
        return P(a.x / b, a.y / b);
    }
    double abs(){
        return sqrt(abs2());
    }
    int abs2(){
        return sqr(x) + sqr(y);
    }
};
typedef P point;*/
ll sqr(ll x) {
    return x * x;
}

const double EPS = 1e-8;

int sig(double x) {
    if (fabs(x) < EPS)return 0;
    if (x > 0)return 1;
    return -1;
}

const int MAXN = 10010;
//P ps[MAXN];
ll d[MAXN];
ll tmp[MAXN];
ll px[MAXN], py[MAXN];
double r[MAXN];

int main() {
    ios::sync_with_stdio(false);
#ifdef LOCAL
        freopen("in.txt","r",stdin);
    #endif // LOCAL
    int t;
    scanf("%d", &t);
    while (t--) {
        int n;
        scanf("%d", &n);
        rep(i, n) {
            scanf("%lld%lld", &px[i], &py[i]);
            //ps[i].input();
        }
        rep(i, n) {
            int j = (i + 1) % n;
            d[i] = ll(sqrt(sqr(px[i] - px[j]) + sqr(py[i] - py[j])) + 0.5);
        }
        //ps[n] = ps[0];
        //rep(i,n)d[i] = (ps[i+1] - ps[i]).abs2();
        //rep(i,n)d[i] = int(sqrt(1.0*d[i]) + 0.5);
        if (n & 1) {
            tmp[0] = 0;
            rep(i, n) {
                tmp[i + 1] = d[i] - tmp[i];
            }
            r[0] = tmp[n] / 2.0;
            bool ok = 1;
            rep(i, n) {
                r[i + 1] = d[i] - r[i];
                if (sig(r[i + 1]) == -1)ok = 0;
            }
            if (ok) {
                double ans = 0;
                rep(i, n) {
                    ans += r[i] * r[i];
                }
                ans *= PI;
                printf("%.2lf\n", ans);
                rep(i, n) {
                    printf("%.2lf\n", r[i]);
                }
            } else {
                puts("IMPOSSIBLE");
            }
        } else {
            ll a = n;
            tmp[0] = 0;
            rep(i, n)tmp[i + 1] = d[i] - tmp[i];
            if (tmp[n]) {
                puts("IMPOSSIBLE");
                continue;
            }
            ll b = 0, c = 0;
            ll lx = 0;
            ll rx = INF;
            rep(i, n) {
                if (i & 1)b -= 2LL * tmp[i];
                else b += 2LL * tmp[i];
                c += tmp[i] * tmp[i];
                if (i & 1)rx = min(rx, tmp[i]);
                else lx = max(lx, -tmp[i]);
            }
            //cout << "ok" << endl;
            if (rx < lx) {
                puts("IMPOSSIBLE");
                continue;
            }
            double x = -1.0 * b / (2.0 * a);
            double ans = 0;
            bool ok = 1;
            if (x >= lx && rx >= x) { ;//ans = a * x * x + b * x  + c;
            } else if (x < lx) {
                x = lx;
            } else x = rx;
            ans = a * x * x + b * x + c;
            ans *= PI;
            r[0] = x;
            rep(i, n) {
                r[i + 1] = d[i] - r[i];
                if (sig(r[i + 1]) == -1)ok = 0;
            }
            if (ok) {
                printf("%.2lf\n", ans);
                rep(i, n) {
                    printf("%.2lf\n", r[i]);
                }
            } else {
                puts("IMPOSSIBLE");
            }
        }
    }
    return 0;
}
