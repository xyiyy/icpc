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
const double EPS = 1e-4;

int sig(double x){
    if(fabs(x)<EPS)return 0;
    return  x < 0 ? -1 : 1;
}
double add(double a, double b){
    if(fabs(a+b)<EPS*(fabs(a) + fabs(b)))return 0;
    return  a+b;
}

class P{
public:
    double x,y;

    P(){}

    P(double x,double y):x(x),y(y){}

    P  operator + (const P &p){
        return P(add(x,p.x),add(y,p.y));
    }

    P operator - (const P &p){
        return P(add(x,-p.x),add(y,-p.y));
    }

    P operator *(const double &d){
        return P(x*d,y*d);
    }

    P operator /(const double &d){
        return P(x/d,y/d);
    }

    double Dot(P p) {
        return x * p.x + y * p.y;
    }

    double dot(P p){
        return add(x*p.x,y*p.y);
    }

    double Det(P p) {
        return x * p.y - y * p.x;
    }

    double  det(P p){
        return add(x*p.y,-y*p.x);
    }


    double abs(){
        return sqrt(abs2());
    }

    double abs2(){
        return dot(*this);
    }

    P rot(double rad){
        return P(add(x*cos(rad),-y*sin(rad)),add(x*sin(rad),y * cos(rad)));
    }
    P rot90(){
        return P(-y,x);
    }
    bool equals(P p){
        return compareTo(p) == 0;
    }
    int compareTo(P p){
        int b = sig(x-p.x);
        if(b!=0)return b;
        return sig(y-p.y);
    }

};

int main()
{
    ios::sync_with_stdio(false);
    #ifdef LOCAL
        freopen("in.txt","r",stdin);
    #endif // LOCAL
    int t;
    cin>>t;
    int cas  = 1;
    vector<P> ps;
    while(t--){
        ps.resize(4);
        rep(i,4){
            cin>>ps[i].x>>ps[i].y;
        }
        ps.pb(ps[0]);
        int dvichang = 0;
        int linchang = 0;
        int pal = 1;
        cout << "Case #" << cas++ << ": ";
        rep(i,2){
            if(sig((ps[i+1]-ps[i]).det(ps[i+3]-ps[i+2])) != 0)pal = 0;
        }
        if(!pal){
            cout << "Others"<<endl;
            continue;
        }
        int i = 0;
        if(sig((ps[i+1]-ps[i]).abs() - (ps[i+2]-ps[i+1]).abs()) == 0){
            linchang = 1;
        }
        int zhi = 0;
        if(sig((ps[i+1]-ps[i]).dot(ps[i+2]-ps[i+1])) == 0){
            zhi = 1;
        }
        if(linchang && zhi){
            cout << "Square" << endl;
        }else if(linchang){
            cout << "Diamond" << endl;
        }else if(zhi){
            cout << "Rectangle" << endl;
        }else {
            cout << "Parallelogram" << endl;
        }
    }
    return 0;
}

