#include<cstdio>
#include<cstring>
#include<algorithm>
#include<set>
#include<map>
#include<vector>
#define rep(i,j,k) for(int i=(int)j;i<=(int)k;i++)
#define per(i,j,k) for(int i=(int)j;i>=(int)k;i--)
using namespace std;
typedef long long LL;
typedef double db;
const int N=315;
namespace __{
    int head[N],np[N*N*8],p[N*N*8],flow[N*N*8],cost[N*N*8],tot;
    int S,T;
    void init(){
        S=304;T=305;
        rep(i,1,T)head[i]=0;
        rep(i,1,tot)np[i]=p[i]=flow[i]=cost[i]=0;
        tot=1;
    }
    void add(int a,int b,int c,int d){
        ++tot;p[tot]=b;np[tot]=head[a];head[a]=tot;flow[tot]=c;cost[tot]=d;
        swap(a,b);c=0;d=-d;
        ++tot;p[tot]=b;np[tot]=head[a];head[a]=tot;flow[tot]=c;cost[tot]=d;
    }
    int q[N*N*10];int dis[N],inq[N],pre[N],bb[N];
    int spfa(){
        rep(i,1,T)dis[i]=-(1e9);
        rep(i,1,T)inq[i]=0;
        rep(i,1,T)pre[i]=-1;
        
        q[q[0]=1]=S;dis[S]=0;inq[S]=1;
        rep(i,1,q[0]){
            int x=q[i];
            for(int u=head[x];u;u=np[u])
            if(flow[u]>0)
            if(dis[p[u]]<dis[x]+cost[u]){
                dis[p[u]]=dis[x]+cost[u];pre[p[u]]=x;bb[p[u]]=u;
                if(!inq[p[u]]){
                    inq[p[u]]=1;q[++q[0]]=p[u];
                }
            }
            inq[x]=0;
        }
        return pre[T];
    }
    int costflow(){
        int ans=0;
        while(spfa()!=-1){
            if(dis[T]<=0)break;
            ans+=dis[T];
            for(int x=T;x!=S;x=pre[x]){
                flow[bb[x]]--;flow[bb[x]^1]++;
            }
        }
        return ans;
    }
};
int T;
int n,m;
int lv[N],tz[N],atk[N];
int ha[N][N];
int tmp[N];
int main(){
    scanf("%d",&T);
    while(T--){
        scanf("%d%d",&n,&m);
        __::init();
        memset(ha,0,sizeof ha);
        rep(i,1,n)scanf("%d%d%d",&tz[i],&lv[i],&atk[i]);
        rep(i,1,12)tmp[i]=0;
        rep(i,1,m){
            int level,ATK,r;
            scanf("%d%d%d",&level,&ATK,&r);
            if(r==0){
                tmp[level]=max(tmp[level],ATK);
            }
            else if(r==1){
                int x;scanf("%d",&x);
                rep(j,1,n)if(tz[x]!=tz[j]&&lv[x]+lv[j]==level){
                    if(tz[x])ha[x][j]=max(ha[x][j],ATK-atk[x]-atk[j]);
                    else ha[j][x]=max(ha[j][x],ATK-atk[x]-atk[j]);
                }
            }
            else{
                int x,y;scanf("%d%d",&x,&y);
                if(tz[x])ha[x][y]=max(ha[x][y],ATK-atk[x]-atk[y]);
                else ha[y][x]=max(ha[y][x],ATK-atk[x]-atk[y]);
            }
        }
        rep(i,1,n)if(tz[i])rep(j,1,n)if(!tz[j])
        ha[i][j]=max(ha[i][j],tmp[lv[i]+lv[j]]-atk[i]-atk[j]);
        rep(i,1,n)if(tz[i])__::add(__::S,i,1,0);
        else __::add(i,__::T,1,0);
        rep(i,1,n)rep(j,1,n)if(ha[i][j]>0)
        __::add(i,j,1,ha[i][j]);
        
        int ans=0;
        rep(i,1,n)ans+=atk[i];
        ans+=__::costflow();
        printf("%d\n",ans);
    }
    return 0;
}