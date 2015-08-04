
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
bool vis[3010];
vector<int>G[3010];
void dijkstra(int s,int dis){
    CLR(vis,0);
    for(int i=0;i<3010;i++){
        dis[i]=INF;
    }
    dis[s]=0;
    priority_queue<PII,VII,greater<PII> >q;
    q.push(MP(0,s));
    while(!q.empty()){
        PII p = q.top();
        q.pop();
        int x = p.second;
        if(vis[x])continue;
        vis[x]=1;
        for(int i=0;i<G[x].size();i++){
            int y = G[x][i];
            if(dis[y]>dis[x]+1){
                dis[y]=dis[x]+1;
                q.push(MP(dis[y],y));
            }
        }
    }
}
int main()
{
	ios::sync_with_stdio(false);
    int n,m;
    cin>>n>>m;
    for(int i=0;i<n;i++){
        cin>>u>>v;
        G[u].PB(v);
        G[v].PB(u);
    }
    cin>>s1>>t1>>l1;
    cin>>s2>>t2>>l2;

	return 0;
}


