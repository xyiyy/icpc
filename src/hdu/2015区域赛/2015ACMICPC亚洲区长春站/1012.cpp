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
int a[110][110];
int main()
{
    ios::sync_with_stdio(false);
    #ifdef LOCAL
        freopen("in.txt","r",stdin);
    #endif // LOCAL
    int t;
    int n,m;
    scanf("%d",&t);
    while(t--){
        scanf("%d%d",&n,&m);
        clr(a,0);
        int ans = 0;
        rep2(i,1,n){
            rep2(j,1,m){
                scanf("%d",&a[i][j]);
                if(a[i][j])ans++;
            }
        }
        rep2(i,1,n){
            rep2(j,1,m+1){
                ans += abs(a[i][j-1]-a[i][j]);
            }
        }
        rep2(i,1,n+1){
            rep2(j,1,m)ans += abs(a[i-1][j]-a[i][j]);
        }
        printf("%d\n",ans);
    }
    return 0;
}
