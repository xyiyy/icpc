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
vector<PII> G[1010];
int dis[1010];
bool vis[1010];
void cal(int s,int n){
    fill(dis,dis+n,INF);
    dis[s]=0;
    priority_queue<PII,VII,greater<PII> > q;
    q.push(MP(0,s));
    while(!q.empty()){
        PII p = q.top();
        q.pop();
        int x = p.second;
        for(int i=0;i<G[x].size();i++){
            int y = G[x][i].first;
            int d = G[x][i].second;
            if(dis[y]>max(d,dis[x])){
                dis[y]=max(d,dis[x]);
                q.push(MP(dis[y],y));
            }
        }
    }
}
int main()
{
	ios::sync_with_stdio(false);
    int t;
    scanf("%d",&t);
    int cas=1;
    while(t--){
        int n,m;
        scanf("%d%d",&n,&m);
        for(int i=0;i<n;i++)G[i].clear();
        int u,v,d;
        for(int i=0;i<m;i++){
            //cin>>u>>v>>d;
            scanf("%d%d%d",&u,&v,&d);
            G[u].PB(MP(v,d));
            G[v].PB(MP(u,d));
        }
        int s;
        //cin>>s;
        scanf("%d",&s);
        cal(s,n);
        //cout<<"Case "<<cas++<<":"<<endl;
        printf("Case %d:\n",cas++);
        for(int i=0;i<n;i++){
            if(dis[i]==INF){
                printf("Impossible\n");
            }else{
                printf("%d\n",dis[i]);
            }
        }
    }
	return 0;
}


