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
ll c[100010];
double dp[100010];
int main()
{
    ios::sync_with_stdio(false);
    #ifdef LOCAL
        //freopen("in3.txt","r",stdin);
        //freopen("out3.txt","w",stdout);

    #endif // LOCAL

    int t;
    scanf("%d",&t);
    while(t--){
        int n;
        ll a,b;
        scanf("%d%lld%lld",&n,&a,&b);
        ll tot = 0;
        double sum = 0;
        double len = b - a;
        double ans = 0;
        double r = 0;
        rep(i,n){
            scanf("%lld",&c[i]);
            tot += c[i];
            r = c[i] / 2.0 * (c[i] / len);
        }
        int lnum = 0,rnum = 0;
        lnum = a / tot;
        rnum = b / tot;
        if(lnum == rnum){

        }





    }

    return 0;
}
