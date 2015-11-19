#include <bits/stdc++.h>
using namespace std;
#define XINF INT_MAX
#define INF 0x3FFFFFFF
#define mp(X,Y) make_pair(X,Y)
#define pb(X) push_back(X)
#define rep(X,N) for(int X=0;X<N;X++)
#define rep2(X,L,R) for(int X=L;X<=R;X++)
#define dep(X,R,L) for(int X=R;X>=L;X--)
#define clr(A,X) memset(A,X,sizeof(A))
#define IT iterator
typedef long long ll;
typedef pair<int,int> PII;
typedef vector<PII> VII;
typedef vector<int> VI;
const double PI = acos(-1.0);
inline double sqr(double x){
    return x * x;
}
const double EPS = 1e-8;
int sig(double x){
    if(fabs(x) < EPS)return 0;
    if(x > 0)return 1;
    return -1;
}
struct P{
    double x,y;
    P (){}
    P (double a,double b):x(a),y(b){}
    void input(){
        scanf("%lf%lf",&x,&y);
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
    double abs2(){
        return sqr(x) + sqr(y);
    }
};
typedef P point;
struct line{
    point a,b;
    line(){}
    line(point x,point y):a(x),b(y){}
};
line point_make_line(const point a,const point b){
    return line(a,b);
}
double det(const P &a,const P &b){
    return a.x * b.y - a.y * b.x;
}
double dot(const P &a,const P &b){
    return a.x * b.x + a.y * b.y;
}
double dist(const P &a,const P &b){
    return (a-b).abs();
}
P rotate_P(const P & p,double A){
    double tx = p.x,ty = p.y;
    return P(tx * cos(A) - ty * sin(A), tx * sin(A) + ty * cos(A));
}
//判断点是否在线段上
bool on_seg(P p1,P p2,P q){
    return det(p1 - q, p2 - q) == 0 && dot(p1 - q, p2 - q) <= 0;
}
//求两条线段的交点
P intersection(P p1,P p2,P q1,P q2){
    return p1 + (p2 - p1) * (det(q2 - q1, q1 - p1) / det(q2 - q1, p2 - p1));
}
//线段相较判定
bool crsSS(P p1,P p2,P q1,P q2){
    if(max(p1.x, p2.x) + EPS < min(q1.x, q2.x))return false;
    if(max(q1.x, q2.x) + EPS < min(p1.x, p2.x))return false;
    if(max(p1.y, p2.y) + EPS < min(q1.y, q2.y))return false;
    if(max(q1.y, q2.y) + EPS < min(p1.y, p2.y))return false;
    return det(p2 - p1, q1 - p1) * det(p2 - p1, q2 - p1) <= 0
        && det(q2 - q1, p1 - q1) * det(q2 - q1, p2 - q1) <= 0;
}
//直线和线段相较判断
bool crsLS(P l1,P l2,P s1,P s2){
    return det(s1 - l2, l1 - l2) * det(s2 - l2, l1 - l2) <= 0;
}
//直线相交判断
//返回-1表示重合，0表示平行，1表示相交
int crsLL(P p1,P p2,P q1,P q2){
    if(sig(det(p1 - p2, q1 - q2)) != 0)return 1;
    if(sig(det(p1 - q2, q1 - p2)) != 0)return 0;
    return -1;
}
//点到直线的垂足
P proj(P p1,P p2,P q){
    return p1 + ((p2 - p1) * (dot(p2 -p1,q - p1) / (p2 - p1).abs2()));
}
//直线到点的距离
double disLP(P p1,P p2,P q){
    return fabs(det(p2 - p1,q - p1)) / (p2 - p1).abs();
}
//线段到点的距离
double disSP(P p1,P p2,P q){
    if(det(p2 - p1, q - p1) <= 0)return (q - p1).abs();
    if(det(p1 - p2, q - p2) <= 0)return (q - p2).abs();
    return disLP(p1,p2,q);
}

//圆和线段相交的判定
bool crsCS(P c,double r,P p1,P p2){
    return disSP(p1,p2,c)<r + EPS && (r < (c-p1).abs() + EPS || r < (c - p2).abs() + EPS);
}

//圆与圆相交的判定
bool crsCC(P c1,double r1,P c2,double r2){
    double dis = (c1 - c2).abs();
    return dis < r1 + r2 + EPS && fabs(r1 - r2) < dis + EPS;
}
//求两圆的极角 以p为中心
double polarangle(P p,P q){
    return atan2(q.y - p.y, q.x - p.x);
}
bool cmp_x(const P& p, const P& q){
    if(p.x != q.x) return p.x < q.x;
    return p.y < q.y;
}
vector<P> qs;
void convex_hull(P* ps,int n){
    sort(ps,ps+n,cmp_x);
    int k = 0;
    qs.resize(2*n);
    for(int i = 0;i<n;qs[k++] = ps[i++]){
        while(k > 1 && det(qs[k-1] - qs[k-2], ps[i]-qs[k-1]) < EPS)k--;
    }
    for(int i = n - 2,t = k; i >= 0; qs[k++] = ps[i--]){
        while(k>t && det(qs[k-1] - qs[k-2], ps[i] - qs[k-1]) < EPS)k--;
    }
    qs.resize(k-1);
}

//求凸包的直径
double convexDiameter(){
    int qsz= qs.size();
    if(qsz == 1)return 0;
    if(qsz == 2){
        return (qs[0] - qs[1]).abs();
    }
    int i = 0, j = 0;
    rep(k,qsz){
        if(!cmp_x(qs[i],qs[k]))i = k;
        if(cmp_x(qs[j],qs[k])) j = k;
    }
    double res = 0;
    int si = i,sj = j;
    while(i != sj || j != si){
        res = max(res,(qs[i] - qs[j]).abs());
        if(det(qs[(i+1)%qsz] - qs[i], qs[(j+1)%qsz] - qs[j]) < 0) i = (i + 1) % qsz;
        else j = (j + 1) % qsz;
    }
    return res;
}


const long double PI2 = 2 * acos(-1.0);

long double update(double x) {
    while (x < 0.0)x += PI2;
    while (x >= PI2)x -= PI2;
    return x;
}
P ps[110];
double ang[110];
int p[110];
bool cmp(int x,int y){
    return ang[x] < ang[y];
}
int main()
{
    ios::sync_with_stdio(false);
    #ifdef LOCAL
        freopen("in.txt","r",stdin);
    #endif // LOCAL
    int t;
    scanf("%d",&t);
    while(t--){
        int n;
        scanf("%d",&n);
        rep(i,n){
            ps[i].input();
            p[i] = i;
        }
        double x = 0,y = 0;
        rep(i,n){
            x += ps[i].x;
            y += ps[i].y;
        }
        x/=n*1.0;
        y/=n*1.0;
        P pp(x,y);
        rep(i,n){
            ang[i] = polarangle(pp,ps[i]);
            ang[i] = update(ang[i]);
        }
        sort(p,p+n,cmp);
        p[n] = p[0];p[n+1] = p[1];
        int f = 1;
        double len = (ps[p[1]]-ps[p[0]]).abs();
        rep(i,n){
            if(sig((ps[p[i+1]]-ps[p[i]]).abs()-len))f = 0;
        }
        P l1 = (ps[p[1]] - ps[p[0]]);
        P l2 = (ps[p[2]] - ps[p[1]]);
        double gao1 = dot(l1,l2);
        double gao2 = det(l1,l2);
        rep(i,n){
            l1 = (ps[p[i+1]] - ps[p[i]]);
            l2 = (ps[p[i+2]] - ps[p[i+1]]);
            if(sig(dot(l1,l2)-gao1)||sig(det(l1,l2)-gao2))f = 0;
        }
        if(f)puts("YES");
        else puts("NO");

    }
    return 0;
}


