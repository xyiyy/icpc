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


P cc[310];
double rx[310];
P poly[10010];
line seg[10010];
int cir;
int segnum;
point ps;
double calc(double mid){
    int num = 0;
    point ret[2];
    double totlen = 0;
    rep(i,cir){
        double d = (cc[i] - ps).abs();
        if(d > mid + rx[i]){
            continue;
        }
        double delta = (sqr(rx[i]) + sqr(d) - sqr(mid)) / (2.0 * rx[i] * d);
        totlen += delta * mid * 2.0;
    }
    rep(i,segnum){
        num = 0;
        point a = seg[i].a;
        point b = seg[i].b;
        int ina = sig(a.abs() - mid) < 0;
        int inb = sig(b.abs() - mid) < 0;
        if(ina){
            if(inb){
                totlen += fabs(det(a,b)) / 2.0;
            }else{
                circle_cross_line(a,b,ps,mid,ret,num);
                totlen += (ret[0] - a).abs();
            }
        }else{
            if(inb){
                circle_cross_line(a,b,ps,mid,ret,num);
                totlen += (ret[0] - b).abs();
            }else ;
        }
    }
    return totlen;
}
int main()
{
    ios::sync_with_stdio(false);
    #ifdef LOCAL
        freopen("in.txt","r",stdin);
    #endif // LOCAL
    int t;
    scanf("%d",&t);
    int cas = 1;
    while(t--){
        int n;
        double m;
        scanf("%d%lf",&n,&m);
        cir = 0;
        int num = 0;
        char str[10];
        point tmp;
        segnum = 0;
        rep(i,n){
            scanf("%s",str);
            if(str[0]=='C'){
                cc[cir].input();
                scanf("%lf",&rx[cir]);
                cir++;
            }else{
                int p = 0;
                scanf("%d",&p);
                rep(i,p){
                    poly[num].input();
                    num++;
                }
                poly[num] = poly[0];
                rep(i,p){
                    seg[segnum] = point_make_line(poly[i],poly[i+1]);
                    segnum++;
                }
            }
        }
        //point ps;
        ps.input();
        double l = 0;
        double r = 20010.0;
        double ans = 0;
        int nn = 0;
        point ret[2];
        double totlen;
        //cout << segnum << endl;
        //cout << cir << endl;
        //rep(i,200){
            double mid = 1.22;//(l + r) / 2.0;
            totlen = 0;
            rep(i,cir){
                double d = (cc[i] - ps).abs();
                //cout << d << endl;
                if(sig(d - mid - rx[i]) == 1){
                    continue;
                }
                double delta = (sqr(rx[i]) + sqr(d) - sqr(mid)) / (2.0 * rx[i] * d);
                //cout << delta << endl;
                totlen += delta * rx[i];
            }
            rep(i,segnum){
                num = 0;
                point a = seg[i].a;
                point b = seg[i].b;
                int ina = sig(a.abs() - mid) < 0;
                int inb = sig(b.abs() - mid) < 0;
                if(ina){
                    if(inb){
                        totlen += fabs(det(a,b)) / 2.0;
                    }else{
                        circle_cross_line(a,b,ps,mid,ret,num);
                        totlen += (ret[0] - a).abs();
                    }
                }else{
                    if(inb){
                        circle_cross_line(a,b,ps,mid,ret,num);
                        totlen += (ret[0] - b).abs();
                    }else{
                        circle_cross_line(a,b,ps,mid,ret,num);
                        if(num == 2){
                            totlen += (ret[0] - ret[1]).abs();
                        }
                    }
                }
            }
            if(totlen > m){
                r = mid;
            }else{
                l = mid;
            }
            ans = mid;
            //cout << ans<<endl;
        //}
        cout << totlen << " " << m << endl;
        printf("Case #%d: ",cas++);
        cout << ans << endl;
        if(sig(totlen - m) == 0){
            double lx = ans + 1e-2;
            double ly = ans - 1e-2;
            double tot1 = calc(lx);
            double tot2 = calc(ly);
            if(sig(m - tot1) == 0 || sig(m - tot2) == 0){
                printf("inestimable");
            }else{
                printf("%.2f",ans);
            }
        }else{
            if(sig(ans - 20010) == 0){
                printf("inestimable");
            }
            //if(sig(totlen - m) < 0){
            else printf("impossible");
        }
        puts("");
    }
    return 0;
}

