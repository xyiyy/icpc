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
int gao(int x,int y){
    return (x+y-1)/y;
}

int main()
{
    ios::sync_with_stdio(false);
    #ifdef LOCAL
        freopen("in.txt","r",stdin);
    #endif // LOCAL
    int n,m;
    int a,b;
    while(scanf("%d%d%d%d",&n,&m,&a,&b)!=EOF){
        int x = (n-1)/a;
        int y = (m-1)/b;
        int ans = INF;
        ans = min(ans,gao(y+1,a/(n-x*a))+gao(x,b/(m-y*b)));
        ans = min(ans,gao(y,a/(n-x*a))+gao(x+1,b/(m-y*b)));
        cout << ans + x * y <<  endl;

    }
    return 0;
}

