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

/*
1
5 40 140
4 9 1 12 7

*/
int main()
{
    ios::sync_with_stdio(false);
    #ifdef LOCAL
        freopen("in3.txt","r",stdin);
        freopen("out3.txt","w",stdout);

    #endif // LOCAL

    int t,cas = 1;
    scanf("%d",&t);
    while(t--){
        int n;
        ll a,b;
        scanf("%d%lld%lld",&n,&a,&b);
        ll tot = 0;
        long double sum = 0;
        long double len = b - a;
        long double ans = 0;
        long double R = 0;
        unsigned long long temp = 0;
        rep(i,n){
            scanf("%lld",&c[i]);
            tot += c[i];
            dp[i] = c[i] / 2.0 * c[i] / len;
            temp +=  c[i] * c[i] ;
        }
        //cout << temp << " " << len << endl;
        R = temp / (2 * len);
        //R = tot / 2.0;
        //cout << R <<endl;
        //cout << tot << " " << R << endl;
        int lnum = 0,rnum = 0;
        lnum = a / tot;
        rnum = b / tot;
        int l = 0;
        int r = 0;
        ll x = a % tot;
        ll y = b % tot;
        for(;c[l]<=x;l++){
            x -= c[l];
        }
        for(;c[r]<=y;r++){
            y-=c[r];
        }
        ans = ans + (c[l] + x) / 2.0 * ((c[l] - x) / len);
        l++;
        //cout << ans << endl;
        if(lnum < rnum){
            while(l < n){
                ans += dp[l];
                l++;
            }
        }else{
            while(l < r){
                ans += dp[l];
                l++;
            }
        }
        //cout << ans << endl;
        //cout << lnum << " " << rnum << endl;
        if(l==n){
            ans += (rnum - lnum - 1)  * R;
            //cout << ans << endl;
            rep(i,r){
                ans += dp[i];
            }
        }
        ans += (y / 2.0) * (y / len);
        cout << "Case #" << cas++ << ": " <<  fixed << setprecision(12) << ans << endl;






    }

    return 0;
}
