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


double mysqrt(double n){
    return sqrt(max(0.0,n));
}

void circle_cross_line(point a,point b,point o,double r,point ret[],int &num){
    double xx0 = o.x,yy0 = o.y;
    double xx1 = a.x,yy1 = a.y;
    double xx2 = b.x,yy2 = b.y;
    double dx = xx2 - xx1, dy = yy2 - yy1;
    double A = dx * dx + dy * dy;
    double B = 2 * dx * (xx1 - xx0) + 2 * dy * (yy1 - yy0);
    double C = sqr(xx1 - xx0) + sqr(yy1 - yy0) - sqr(r);
    double delta  = B * B - 4 * A * C;
    num = 0;
    if(sig(delta) >=0){
        double t1 = (-B - mysqrt(delta)) / (2 * A);
        double t2 = (-B - mysqrt(delta)) / (2 * A);
        if(sig(t1 - 1) <= 0 && sig(t1) >= 0){
            ret[num++] = point(xx1 + t1 * dx, yy1 + t1 * dy);
        }
        if(sig(t2 - 1) <= 0 && sig(t2) >= 0){
            ret[num++] = point(xx1 + t2 * dx, yy1 + t2 * dy);
        }
    }
}
int dcmp(double k){
    return k < -EPS ? -1 : k > EPS ? 1 : 0;
}

double cross(const point &a,const point &b){
    return a.x * b.y - a.y * b.x;
}

//求圆与多边形交的面积
point crosspt(const point &a,const point &b,const point &p,const point& q){
    double a1 = cross(b - a, p - a);
    double a2 = cross(b - a, q - a);
    return (p * a2 - q * a1) / (a2 - a1);
}
const int MAXN = 10010;
point res[MAXN];
double r;
double sector_area(const point &a,const point &b){
    double theta = atan2(a.y,a.x) - atan2(b.y,b.x);
    while(theta <= 0)theta += 2 * PI;
    while(theta > 2*PI) theta -= 2 * PI;
    theta = min(theta,2 * PI - theta);
    return r * r * theta / 2;
}
double calc(P &a,P &b){
    point p[2];
    int num = 0;
    int ina = dcmp((a.abs()) - r) < 0;
    int inb = dcmp((b.abs()) - r) < 0;
    if(ina){
        if(inb){
            return fabs(cross(a,b)) / 2.0;
        }else{
            circle_cross_line(a,b,point(0,0),r,p,num);
            return sector_area(b,p[0]) + fabs(cross(a,p[0])) / 2.0;
        }
    }else {
        if(inb){
            circle_cross_line(a,b,point(0,0),r,p,num);
            return sector_area(p[0],a) + fabs(cross(p[0],b)) / 2.0;
        } else {
            circle_cross_line(a,b,point(0,0),r,p,num);
            if(num == 2){
                return sector_area(a,p[0]) + sector_area(p[1],b) + fabs(cross(p[0],p[1])) / 2.0;
            } else {
                return sector_area(a,b);
            }
        }
    }
}
int main(){
    ios::sync_with_stdio(0);

    return 0;
}

