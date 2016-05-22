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
int a[10];
int b[110];
vector<int>vec[110];
class LCMGCD{
public:
    PII gao(int x){
        int px = 0;
        while(x % 3 == 0){
            x /= 3;
            px++;
        }
        int py = 0;
        while(x % 2 == 0){
            x /= 2;
            py++;
        }
        return mp(px,py);
    }
    int gx = 0;
    int gy = 0;
    int ff(int u,int v){
        if(u == v)return 1;
        else if(u < v )return 0;
        else return 2;
    }
    int gg(PII p){
        int px = p.first;
        int py = p.second;
        px = ff(px,gx);
        py = ff(py,gx);
        a[px* 3 + py]++;
        return px * 3 + py;
    }
    bool check(){
        if(a[0] || a[2] || a[6] || a[8])return 1;
        return 0;
    }
    string isPossible(vector <int> x, int t){
        PII p = gao(t);
        gx = p.first;
        gy = p.second;
        clr(a,0);
        //cout << gx << gy << endl;
        int sz = x.size();
        rep(i,sz){
            int tmp = gg(gao(x[i]));
            b[i] = tmp;
            vec[tmp].pb(i);
        }
        //rep(i,10)cout << a[i] <<endl;
        bool ok = 0;
        bool ch = check();
        string str = "Possible";
        if(a[1]){
            if(a[3]){
                if(ch){
                    if(a[0] || (a[2] && a[6]) || a[8])ok = 1;
                }else ok = 1;
            }else{
                if(a[5] && a[6]){
                    a[5]--;a[6]--;
                    if(check()){
                        if(a[0] || (a[2] && a[6]) || a[8])ok = 1;
                    }else{
                        ok = 1;
                    }
                    a[5]++,a[6]++;
                }
            }
        }
        if(a[3]){
            if(!a[1]){
                if(a[2] && a[7]){
                    a[2]--;a[7]--;
                    if(check()){
                        if(a[0] || (a[2] && a[6]) || a[8])ok = 1;
                    }else{
                        ok = 1;
                    }
                    a[2]++;a[7]++;
                }
            }
        }
        if(a[4]){
            if(ch){
                if(a[0] || (a[2] && a[6]) || a[8])ok = 1;
            }else ok = 1;
        }
        if(a[5]){
            if(a[7]){
                if(ch){
                    if(a[0] || (a[2] && a[6]) || a[8])ok = 1;
                }else ok = 1;
            }else{
                if(a[1] && a[6]){
                    a[1]--;a[6]--;
                    if(check()){
                        if(a[0] || (a[2] && a[6]) || a[8])ok = 1;
                    }else{
                        ok = 1;
                    }
                    a[1]++;a[6]++;
                }
            }
        }
        if(a[7]){
            if(!a[5]){
                if(a[3] && a[2]){
                    a[2]--;
                    if(check()){
                        if(a[0] || (a[2] && a[6]) || a[8])ok = 1;
                    }else ok = 1;
                    a[2]++;
                }
            }
        }

        if(ok) return str;
        else return "Impossible";



    }


};


int main()
{
    ios::sync_with_stdio(false);
    #ifdef LOCAL
        //freopen("in.txt","r",stdin);
    #endif // LOCAL
    LCMGCD *p = new LCMGCD();
    vector<int >x;
    x.pb(100663296);
    x.pb(544195584);
    x.pb(229582512);
    x.pb(59049);
    cout << p->isPossible(x,60466176);


    return 0;
}
