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
int a[310][310];
int b[310][310];
int c[310][310];
int main()
{
    ios::sync_with_stdio(false);
    #ifdef LOCAL
        freopen("in.txt","r",stdin);
    #endif // LOCAL
    int n;
    while(scanf("%d",&n)!=EOF){
        rep(i,n)
        rep(j,n)scanf("%d",&a[i][j]);
        rep(i,n)
        rep(j,n)scanf("%d",&b[i][j]);
        int ans = INF;
        rep(i,n){
            int num = 0;
            rep(j,n)
            rep(k,n)c[j][k] = a[j][k];
            rep(j,n)swap(c[i][j],c[0][j]);
            if(i)num++;
            rep(j,n){
                if(c[0][j]!=b[0][j]){
                    int k = j;
                    for(k = j + 1;k<n;k++)if(b[0][j]==c[0][k])break;
                    rep(l,n)swap(c[l][k],c[l][j]);
                    num++;
                }
            }
            rep2(j,1,n-1){
                if(b[j][0]!=c[j][0]){
                    int k = j;
                    for(k = j + 1;k<n;k++)if(b[j][0]==c[k][0])break;
                    if(k>n)break;
                    rep(l,n)swap(c[j][l],c[k][l]);
                    num++;
                }
            }
            int f = 0;
            rep(j,n)
            rep(k,n)
                    if(c[j][k]!=b[j][k])f = 1;
            if(f)continue;
            ans = min(num,ans);

        }
        if(ans == INF)ans = -1;
        cout << ans << endl;
    }



    return 0;
}

