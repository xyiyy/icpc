
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
int a[10],b[10];
int c[10];
int calb;
int cal(int *x){
    sort(x,x+3);
    int ret = 0;
    int f = 0;
    rep(i,2){
        if(x[i] == x[i+1])f++;
    }
    if(!f)ret = x[2] * 100 + x[1] * 10 + x[0];
    else if(f==1){
        if(x[0]==x[1])ret = 1000 * x[1] + x[2];
        else ret = 1000 * x[1] + x[0];
    }else{
        ret = x[2] * 100000;
    }
    return ret;

}
bool check(){
    return cal(c) > calb;
}
double ans ;
void gao(){
    cout << fixed << setprecision(3) << ans << endl;
}
int main()
{
    ios::sync_with_stdio(false);
    #ifdef LOCAL
        freopen("in.txt","r",stdin);
    #endif // LOCAL
    int t;
    cin >> t;
    while(t--){
        rep(i,3)cin>>a[i];
        rep(i,3)cin>>b[i];
        calb = cal(b);
        rep(i,3)c[i] = a[i];
        ans = 0;
        if(check()){
            ans = 1;
            gao();
        }else{
            int flag = 0;
            int f = 0;
            rep(i,3){
                f = 0;
                rep2(j,1,6){
                    rep(k,3){
                        if(i==k)c[k] = j;
                        else c[k] = a[k];
                    }
                    if(check())f++;
                }
                flag = max(flag,f);
            }
            ans = flag / 6.0;
            gao();
        }
    }
    return 0;
}

