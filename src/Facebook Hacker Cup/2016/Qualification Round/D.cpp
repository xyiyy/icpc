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

char a[100010];
int b[100010][30];
bool tail[100010];
int used[3000030];
int tot = 1;
int num = 0;
vector<int>dp[100010];
int m;
void Init(){
    clr(tail,0);

    rep(i,num+1){
        int p = used[i];
        int x = p / 30;
        int y = p % 30;
        b[x][y] = 0;
    }
    tot = 1;
}

void Insert(){
    int len = strlen(a);
    int now = 1;
    rep(i,len){
        int c = a[i] - 'a';
        if(!b[now][c]){
            b[now][c] = ++tot;
            used[num++] = now * 30 + c;
        }
        now = b[now][c];
    }
    tail[now] = 1;
}
int dfs(int u){
    int sum = tail[u];
    rep(i,26){
        if(b[u][i]){
            sum+= dfs(b[u][i]);
        }
    }
    sum++;
    sum = min(sum,m+1);
    dp[u].resize(sum);
    rep(i,sum)dp[u][i] = INF;
    dp[u][0] = 0;
    if(tail[u])dp[u][1] = 0;
    rep(i,26){
        if(b[u][i]){
            int v = b[u][i];
            int sz = dp[v].size();
            dep(k,sum-1,0){
                rep(j,sz){
                    if(k<j)continue;
                    dp[u][k] = min(dp[v][j]+1+dp[u][k-j],dp[u][k]);
                }
            }
            dp[v].clear();
        }
    }
    return sum - 1;
}
int main()
{
    ios::sync_with_stdio(false);
    #ifdef LOCAL
        freopen("text_editor.txt","r",stdin);
        freopen("out.txt","w",stdout);
    #endif // LOCAL
    int t;
    scanf("%d",&t);
    int cas = 1;
    while(t--){
        int n;
        Init();
        scanf("%d%d",&n,&m);
        rep(i,n){
            scanf("%s",a);
            Insert();
        }
        dfs(1);
        cout << "Case #"  << cas++ << ": ";
        cout << dp[1][m] * 2 + m<<endl;
    }
    return 0;
}




