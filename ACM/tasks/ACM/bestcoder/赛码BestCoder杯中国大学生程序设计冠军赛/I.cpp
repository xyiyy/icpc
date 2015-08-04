#pragma comment(linker, "/STACK:102400000,102400000")
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
#define MP(X,Y) make_pair(X,Y)
#define PB(X) push_back(X)
#define REP(X,N) for(int X=0;X<N;X++)
#define REP2(X,L,R) for(int X=L;X<=R;X++)
#define DEP(X,R,L) for(int X=R;X>=L;X--)
#define CLR(A,X) memset(A,X,sizeof(A))
#define IT iterator
typedef long long ll;
typedef pair<int,int> PII;
typedef vector<PII> VII;
typedef vector<int> VI;
#define MAXN 1000010
int vis[MAXN];
bool used[MAXN];
//map<int,int>Map[MAXN];
//map<int,int>Map1[MAXN];
bool flag=1;
int head[MAXN];//,head[MAXN];
int To[2*MAXN];//,To1[MAXN*2];
int Next[2*MAXN];//Next1[MAXN*2];
bool gao[2*MAXN];//bool gao[MAXN];
int m1;
int tot1,tot;
//stack<int>st;
void dfs(int x,int d){
    //cout<<x<<endl;

    if(vis[x]==d){
        flag=1;
    }
    if(flag)return;
    vis[x]=d;
    //st.push(x);
    //int temp;
    int v;
    //used[x]=1;
    //for(map<int,int>::iterator it=Map[x].begin();it!=Map[x].end();it++){
    for(int i=head[x];i!=-1;i=Next[i]){
        v = To[i];
        if(gao[i])continue;
        gao[i]=1;
        if(i<m1*2)gao[i^1]=1;
        if(vis[v]!=INF)
        dfs(v,d);
        if(flag)return;
    }
    vis[x]=INF;
}
void add_edge(int u,int v){
    Next[tot]=head[u];
    To[tot]=v;
    gao[tot]=0;
    head[u]=tot++;
}
int deg[MAXN];

int main()
{
	ios::sync_with_stdio(false);
    int t;
    scanf("%d",&t);
    //cin>>t;
    while(t--){
            flag=0;
        int n,m2;
        scanf("%d%d%d",&n,&m1,&m2);
        for(int i=0;i<n;i++)head[i]=-1;
        tot=0;
        flag=0;
        for(int i=0;i<n;i++){vis[i]=-1;}
        int u,v;

        for(int i=0;i<m1;i++){
                scanf("%d%d",&u,&v);
            //cin>>u>>v;
            u--;
            v--;
            if(u>v)swap(u,v);
            add_edge(u,v);
            add_edge(v,u);
        }
        for(int i=0;i<m2;i++){
            scanf("%d%d",&u,&v);
            //cin>>u>>v;
            u--;v--;
            add_edge(u,v);
        }
        for(int i=0;i<n;i++){
            if(flag)break;
            if(vis[i]==-1){
                dfs(i,i);
            }
        }
    if(flag)cout<<"YES"<<endl;
    else cout<<"NO"<<endl;
    }
	return 0;
}




