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
using namespace std;
#define XINF INT_MAX
//#define INF 0x3FFFFFFF
#define MP(X,Y) make_pair(X,Y)
#define PB(X) push_back(X)
#define REP(X,N) for(int X=0;X<N;X++)
typedef pair<int,int> PII;
typedef vector<int> VI;
typedef long long ll;

#define inf 1<<30  
#define N 1004  
#define sta que  
const int INF = (1<<30);  
struct edge{  
    int u,v,w,c;  
    int next;
}e[N*25];  
int head[N];
int dis[N];
bool vis[N];
int cnt[N];
int ecnt;  
int n,m;  
  
void init(){  
    ecnt = 0;  
    memset(head,-1,sizeof(head));  
}  
void add(int u,int v,int w,int cost){  
    e[ecnt].u = u;  
    e[ecnt].v = v;  
    e[ecnt].w = w;  
    e[ecnt].c = cost;  
    e[ecnt].next = head[u];  
    head[u] = ecnt++; 
    e[ecnt].u = v;  
    e[ecnt].v = u;  
    e[ecnt].w = w;  
    e[ecnt].c = cost;  
    e[ecnt].next = head[v];  
    head[v] = ecnt++;  
}  
bool SPFA(int s){
    queue<int>  qq;  
    int i;  
    for(i=1;i<=n;++i){  
        dis[i] = INF;        
        vis[i] = 0;  
        cnt[i] = 0;  
    }  
    dis[s]=0;             
    vis[s] = 1;  
   cnt[s]++;         
    qq.push(s);  
    int u,v;  
    while(!qq.empty()){  
        u = qq.front();  
        qq.pop();  
        vis[u] = 0;  
        for(i=head[u];i!=-1;i = e[i].next){  
            v = e[i].v;  
            int cost = e[i].w;  
            if(dis[v] > cost+dis[u]){  
                dis[v] = cost+dis[u];  
               if(!vis[v]){  
                    vis[v] = 1;  
                    qq.push(v);  
                    cnt[v]++;  
                    if(cnt[v] >= n)return false;  
                }  
            }  
        }  
    }  
    return true;  
}  
int h[N];  
int gap[N];  
int source,sink;  
inline int dfs(int pos,int cost){  
    if (pos==sink){  
        return cost;  
    }  
    int j,minh=n-1,lv=cost,d;  
    for (j=head[pos];j!=-1;j=e[j].next){  
        int v=e[j].v,val=e[j].c;  
        if(val>0){  
            if (h[v]+1==h[pos]){  
                if (lv<e[j].c) d=lv;  
                else d=e[j].c;  
  
                d=dfs(v,d);  
                e[j].c-=d;  
                e[j^1].c+=d;  
                lv-=d;  
                if (h[source]>=n) return cost-lv;  
                if (lv==0) break;  
            }  
  
            if (h[v]<minh)   minh=h[v];  
        }  
    }  
    if (lv==cost){  
        --gap[h[pos]];  
       if (gap[h[pos]]==0) h[source]=n;  
        h[pos]=minh+1;  
        ++gap[h[pos]];  
    }  
    return cost-lv;  
  
}  
  
int sap(int st,int ed){  
    source=st;  
    sink=ed;  
   int ans=0;  
    memset(gap,0,sizeof(gap));  
    memset(h,0,sizeof(h));  
  
    gap[st]=n;  
  
    while (h[st]<n){  
        ans+=dfs(st,INT_MAX);  
    }  
  
    return ans;  
}  
int main(){  
    int s,t;  
    while(scanf("%d%d",&n,&m) && (n+m)){  
        int i,j;  
        scanf("%d%d",&s,&t);  
        init();  
        for(i=0;i<m;i++){  
            int u,v,w,c;  
            scanf("%d%d%d%d",&u,&v,&w,&c);  
            add(u,v,w,c);  
        }  
        SPFA(s);//cout<<ecnt<<endl;  
        for(i=0;i<ecnt;i+=2){  
            int u = e[i].u;  
            int v = e[i].v;  
          if(dis[u] + e[i].w != dis[v]){  
                e[i].c = 0;  
            }  
            if(dis[v] + e[i].w != dis[u]){  
                e[i+1].c=0;  
            }  
        }  
        printf("%d\n",sap(s,t));  
    }  
    return 0;  
}  


