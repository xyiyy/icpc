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
int a[200010];
int f[200010],g[200010];
int main()
{
    ios::sync_with_stdio(false);
    #ifdef LOCAL
        freopen("in.txt","r",stdin);
    #endif // LOCAL
    int t;
    scanf("%d",&t);
    while(t--){
        int n;
        scanf("%d",&n);
        rep(i,n){
            scanf("%d",&a[i+1]);
        }
        f[1] =1;
        g[n] =1;
        rep2(i,2,n){
            if(a[i]>=a[i-1])f[i]=f[i-1]+1;
            else f[i] = 1;
        }
        dep(i,n-1,1){
            if(a[i]<=a[i+1])g[i] = g[i+1]+1;
            else g[i]=1;
        }
        int ok = 0;
        rep2(i,2,n-1){
            if(a[i-1]<=a[i+1]&&f[i-1]+g[i+1]>=n-1)ok = 1;
        }
        if(f[n-1]==n-1||g[2]==n-1||f[n]==n)ok = 1;
        rep2(i,1,n){
            a[i] = 200010 - a[i];
        }
        f[1] =1;
        g[n] =1;
        rep2(i,2,n){
            if(a[i]>=a[i-1])f[i]=f[i-1]+1;
            else f[i] = 1;
        }
        dep(i,n-1,1){
            if(a[i]<=a[i+1])g[i] = g[i+1]+1;
            else g[i]=1;
        }
        //int ok = 0;
        rep2(i,2,n-1){
            if(a[i-1]<=a[i+1]&&f[i-1]+g[i+1]>=n-1)ok = 1;
        }
        if(f[n-1]==n-1||g[2]==n-1||f[n]==n)ok = 1;
        if(ok)puts("YES");
        else puts("NO");

    }
    return 0;
}

