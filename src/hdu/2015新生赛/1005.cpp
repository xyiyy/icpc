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
ll ans[110];
ll C[50][50];
ll fac[20];
int main()
{
    ios::sync_with_stdio(false);
    #ifdef LOCAL
        freopen("in.txt","r",stdin);
    #endif // LOCAL
    int n;
    rep(i,40){
        C[i][0] = 1;
        rep2(j,1,i){
            C[i][j] = C[i-1][j] + C[i-1][j-1];
        }
    }
    fac[0] =1;
    for(int i =1;i<20;i++)fac[i] =fac[i-1] * i;
    while(cin>>n&&n){
        if(!ans[n]){
            int x = n / 2;
            int y = n / 3;
            x++;y++;
            int a, b,c;
            ll tmp = 0;
            rep(i,x){
                rep(j,y){
                    if(i * 2 + j * 3 > n)break;
                    b = i;c = j;
                    a = n - i * 2 - j * 3;
                    ll gao= 1LL;
                    rep(k,b){
                        gao *= C[(b - k)*2][2];
                    }
                    gao/=fac[b];
                    ll p = 1;
                    rep(k,c){
                        p *= C[(c-k)*3][3];
                    }
                    p/=fac[c];
                    gao *= C[n][a] * C[n - a][b * 2] * p;
                    //out << gao << endl;
                    ans[n] += gao;
                }
            }
            cout << ans[n] << endl;
        }else{
            cout << ans[n] << endl;
        }
    }
    return 0;
}


