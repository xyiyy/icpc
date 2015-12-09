//#####################
//Author:fraud
//Blog: http://www.cnblogs.com/fraud/
//#####################
//#pragma comment(linker, "/STACK:102400000,102400000")
#include <iostream>
#include <sstream>
#include <ios>
#include <iomanip>
#include <functional>
#include <algorithm>
#include <vector>
#include <string>
#include <list>
#include <queue>
#include <deque>
#include <stack>
#include <set>
#include <map>
#include <cstdio>
#include <cstdlib>
#include <cmath>
#include <cstring>
#include <climits>
#include <cctype>
using namespace std;
#define XINF INT_MAX
#define INF 0x3FFFFFFF
#define mp(X,Y) make_pair(X,Y)
#define pb(X) push_back(X)
#define rep(X,N) for(int X=0;X<N;X++)
#define rep2(X,L,R) for(X=L;X<=R;X++)
#define dep(X,R,L) for(int X=R;X>=L;X--)
#define clr(A,X) memset(A,X,sizeof(A))
#define IT iterator
typedef long long ll;
typedef pair<int,int> PII;
typedef vector<PII> VII;
typedef vector<int> VI;
const int N = 10010;
int dfn[N],low[N],head[N],vis[N];
bool cut[N];
int k,n,cnt,root;

struct Edge{
    int to,nxt;
}edge[N<<1];

void addedge(int cu,int cv){
    edge[cnt].to=cv;
    edge[cnt].nxt=head[cu];
    head[cu]=cnt++;
}

void Tarjan(int u,int fa){
    int son=0;
    vis[u]=1;
    dfn[u]=low[u]=++k;
    for(int i=head[u];i!=-1;i=edge[i].nxt){
        int v=edge[i].to;
        if(vis[v]==1 && v!=fa)
            low[u]=min(low[u],dfn[v]);
        if(vis[v]==0){
            Tarjan(v,u);
            son++;
            low[u]=min(low[u],low[v]);
            if((u==root && son>1) || (u!=root && dfn[u]<=low[v]))
                cut[u]=1;
        }
    }
    vis[u]=2;
}

int a[10];
int main(){
    ios::sync_with_stdio(false);
    int ans = 0;
    freopen("g.out","w",stdout);
    rep2(a[1],1,4){
        rep2(a[2],1,4){
            rep2(a[3],1,4){
                rep2(a[4],1,4){
                //    rep2(a[5],1,6){
                //        rep2(a[6],1,6){
                        int x;
                        memset(head,-1,sizeof(head));
                        memset(dfn,0,sizeof(dfn));
                        memset(low,0,sizeof(low));
                        memset(vis,0,sizeof(vis));
                        memset(cut,0,sizeof(cut));
                        cnt=0;
                        rep2(x,1,4){
                            if(x==a[x])continue;
                            addedge(x,a[x]);
                            addedge(a[x],x);
                        }
                        root = 1;
                        Tarjan(root,-1);
                        ans = 0;
                        //cout << cut[1] << cut[2] << cut[3] <<cut[4]<<endl;
                        //cout<<cut[1]<<cut[2]<<endl;
                        rep2(x,1,4){
                            ans += cut[x];
                        }
                        cout << ans << endl;
                        }
                    }
               // }
           // }
        }
    }
   // cout<<ans<<endl;

    return 0;
}

