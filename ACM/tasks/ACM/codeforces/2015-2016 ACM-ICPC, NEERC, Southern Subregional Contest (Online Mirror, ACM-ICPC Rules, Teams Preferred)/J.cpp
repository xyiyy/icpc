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
char a[20][20];
int n,m;
int dirx[4] = {-1,0,1,0};
int diry[4] = {0,1,0,-1};
int gao(int x){
    return (x + 1) % 4;
}
bool in(int x,int y){
    if(x < 0 || x >= n || y < 0 || y >= m)return 0;
    if(a[x][y]=='*')return 0;
    return 1;
}
bool vis[110][110];
int main()
{
    ios::sync_with_stdio(false);
    #ifdef LOCAL
        freopen("in.txt","r",stdin);
    #endif // LOCAL
    cin>>n>>m;
    int dir = 0;
    int sx,sy;
    rep(i,n){
        rep(j,m){
            cin>>a[i][j];
            if(a[i][j]!='.'&&a[i][j]!='*'){
                sx = i;
                sy = j;
                if(a[i][j]=='U')dir = 0;
                else if(a[i][j]=='R')dir = 1;
                else if(a[i][j]=='D')dir = 2;
                else if(a[i][j]=='L')dir = 3;
                a[i][j] = '.';
            }
        }
    }
    int x = sx,y = sy;
    for(int i=0;i<10000;i++){
        if(!vis[x][y])vis[x][y] = 1;
        int k = 0;
        int f = 0;
        while(k < 4){
            int dx = x + dirx[dir];
            int dy = y + diry[dir];
            if(in(dx,dy)){
                f = 1;
                x = dx,y = dy;
                break;
            }
            dir = gao(dir);
            k++;
        }
        //if(!f)break;
    }
    int ans = 0;
    rep(i,n){
        rep(j,m){
            ans += vis[i][j];
        }
    }
    cout << ans << endl;
    return 0;
}

