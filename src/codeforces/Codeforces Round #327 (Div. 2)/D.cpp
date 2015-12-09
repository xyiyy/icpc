//#####################
//Author:fraud
//Blog: http://www.cnblogs.com/fraud/
//#####################
//#pragma comment(linker, "/STACK:102400000,102400000")
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
double gao(double a,double b){
    return sqrt(a*a+b*b);
}
double dis(double a,double b,double c,double d){
    return gao(a-c,b-d);
}
int main()
{
    ios::sync_with_stdio(false);
    #ifdef LOCAL
        freopen("in.txt","r",stdin);
    #endif // LOCAL
    double sx,sy,gx,gy;
    double v,t;
    double vx,vy,wx,wy;
    while(cin>>sx>>sy>>gx>>gy){
        cin>>v>>t;
        cin>>vx>>vy>>wx>>wy;
        double px,py;
        px = sx + vx * t;
        py = sy + vy * t;
        double d = dis(px,py,gx,gy);
        if(v*t>=d){
            /*px = gx - sx;
            py = gy - sy;
            P dir = P(px,py);
            P ivzu = proj(P(0,0),dir,P(vx,vy));
            double fv = disLP(P(0,0),dir,P(vx,vy));
            int f = sig(ivzu.x*px);
            P vec = dir;
            //double tmp = vec/(dir.abs())*v.abs();
            double ans = dir.abs() / ( sqrt(v * v - fv * fv) + ivzu.abs() * f );
            cout << fixed << setprecision(15) << ans << endl;*/
            double ans = 1e15;
            double l = 0;
            double r = t;
            for(int i=0;i<3000;i++){
                double mid = (l+r)/2;
                double tx = sx + mid * vx;
                double ty = sy + mid * vy;
                d = dis(tx,ty,gx,gy);
                if(v*mid>=d)r = mid;
                else l = mid;
            }
            cout << fixed << setprecision(18) << l << endl;


        }else{
            double ans = 1e15;
            double l = t;
            double r = 1e10;
            for(int i=0;i<3000;i++){
                double mid = (l+r)/2;
                double tx = px + (mid - t) * wx;
                double ty = py + (mid - t) * wy;
                d = dis(tx,ty,gx,gy);
                if(v*mid>=d)r = mid;
                else l = mid;
            }
            cout << fixed << setprecision(18) << l << endl;

        }
    }
    return 0;
}

