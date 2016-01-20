/**
 * @author xyiyy @https://github.com/xyiyy
 */

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
#define mp(X, Y) make_pair(X,Y)
#define pb(X) push_back(X)
#define rep(X, N) for(int X=0;X<N;X++)
#define rep2(X, L, R) for(int X=L;X<=R;X++)
#define dep(X, R, L) for(int X=R;X>=L;X--)
#define clr(A, X) memset(A,X,sizeof(A))
#define IT iterator
#define ALL(X) (X).begin(),(X).end()
#define PQ std::priority_queue
typedef long long ll;
typedef unsigned long long ull;
typedef pair<int, int> PII;
typedef vector<PII> VII;
typedef vector<int> VI;



void Scan(int &n) {
    int x = 0, f = 1;
    char c = getchar();
    while ((c < '0' || c > '9') && c != '-' && c != EOF)c = getchar();
    if (c == EOF)return;
    if (c == '-')c = getchar(), f = -1;
    while (c >= '0' && c <= '9')x *= 10, x += (c - '0'), c = getchar();
    n = x * f;
}

void Out(ll n) {
    if (n < 0) {
        putchar('-');
        n = -n;
    }
    int len = 0, data[20];
    while (n) {
        data[len++] = n % 10;
        n /= 10;
    }
    if (!len)data[len++] = 0;
    while (len--)putchar(data[len] + 48);
}
struct node{
    int to,Next;
};
struct qnode{
    int to,w,Next;
    int type;
    int lca;
};
const int MAXN = 100010;
node edge[MAXN << 1];
qnode qedge[MAXN << 1];
bool vis[MAXN];
int head[MAXN];
int qhead[MAXN];
ll d[MAXN];
ll res[MAXN];
int fa[MAXN];
int pa[MAXN];
ll dise[MAXN];
bool used[MAXN];

int tot1, tot2;
void addedge1(int u,int v){
    edge[tot1].to = v;
    edge[tot1].Next = head[u];
    head[u] = tot1;
    tot1++;

    edge[tot1].to = u;
    edge[tot1].Next = head[v];
    head[v] = tot1;
    tot1++;
}
void addedge2(int u,int v){
    qedge[tot2].to = v;
    qedge[tot2].Next = qhead[u];
    qhead[u] = tot2;
    tot2++;
}
int find(int x){
    if(pa[x]!=x){
        pa[x] = find(pa[x]);
    }
    return pa[x];
}

void tarjan(int u,int f){
    pa[u] = u;
    vis[u] = 1;
    fa[u] = f;
    for(int i = head[u];i!=-1;i = edge[i].Next){
        int v = edge[i].to;
        if(!vis[v]){
            tarjan(v,u);
            pa[v] = u;
        }
    }
    for(int i = qhead[u];i!=-1;i = qedge[i].Next){
        int v = qedge[i].to;
        if(vis[v]){
            qedge[i].lca = find(v);
            //cout << qedge[i].lca << endl;
            if(qedge[i].type == 2){
                int lca = qedge[i].lca;
                int w = qedge[i].w;
                dise[lca] -= w * 2;
                dise[u] += w;
                dise[v] += w;
            }else{
                int lca = qedge[i].lca;
                int w = qedge[i].w;
                d[lca] -= w;
                //if(fa[lca])
                d[fa[lca]] -= w;
                d[u] += w;
                d[v] += w;
            }
        }
    }
}
void dfs(int u,int f){
    for(int i = head[u];i!=-1;i=edge[i].Next){
        int v = edge[i].to;
        if(v == f)continue;
        dfs(v,u);
        d[u] += d[v];
        dise[u] += dise[v];
        res[i/2] = dise[v];
    }

}

int main(){
    int t;
    int cas =1;
    Scan(t);
    while(t--){
        int n,m;
        Scan(n);
        Scan(m);
        /*clr(vis,0);
        clr(head,-1);
        clr(qhead,-1);
        clr(d,0);
        clr(dise,0);*/
        rep(i,n+1)vis[i] = d[i] = dise[i] = used[i] = 0;
        rep(i,n+1)head[i] = qhead[i] = -1;
        tot1 = tot2 = 0;
        int l,r,inc;
        rep(i,n-1){
            Scan(l);
            Scan(r);
            addedge1(l,r);
        }
        addedge1(1,0);
        addedge1(0,0);
        rep(i,m){
            char c = getchar();
            while(c!='1'&& c!='2')c = getchar();
            Scan(l);
            Scan(r);
            Scan(inc);
            if(c=='1'){
                qedge[tot2].w = inc;
                qedge[tot2].type = 1;
                addedge2(l,r);

            }else{
                qedge[tot2].w = inc;
                qedge[tot2].type = 2;
                addedge2(l,r);
            }
        }
        tarjan(0,-1);
        dfs(0,-1);
        printf("Case #%d:\n",cas++);

        rep(i,n){
            if(i)putchar(' ');
            Out(d[i+1]);
        }
        puts("");
        rep(i,n-1){
            if(i)putchar(' ');
            Out(res[i]);
        }
        puts("");
    }
    return 0;
}
