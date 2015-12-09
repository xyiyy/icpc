//#####################
//Author:fraud
//Blog: http://www.cnblogs.com/fraud/
//#####################
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
#define MAXN 100010
int head[MAXN];
int p[MAXN],Next[MAXN];
int deg[MAXN];
int tot=0;
bool vis[MAXN];
void init(){
	CLR(head,-1);
	tot=0;
	CLR(vis,0);
	CLR(deg,0);
}
void add_edge(int u,int v){
	p[tot]=v;
	Next[tot]=head[u];
	head[u]=tot++;
}

int main()
{
	ios::sync_with_stdio(false);
	int n,m,k;
	while(scanf("%d%d%d",&n,&m,&k)!=EOF){
		init();
		int u,v;
		for(int i=0;i<m;i++){
			scanf("%d%d",&u,&v);
			deg[v]++;
			add_edge(u,v);
		}
		priority_queue<int> q;
		for(int i=1;i<=n;i++){
			if(deg[i]<=k){
				q.push(i);
				vis[i]=1;
			}
		}
		int num=0;
		int x;
		while(num<n){
			x=q.top();
			q.pop();
			vis[x]=0;
			if(deg[x]<=k){
				k-=deg[x];
				deg[x]=0;
			}else
			 continue;
			if(num)printf(" ");
			printf("%d",x);
			num++;
			for(int i=head[x];i!=-1;i=Next[i]){
				if(deg[p[i]]){
					deg[p[i]]--;
					if(deg[p[i]]<=k&&!vis[p[i]]){
						q.push(p[i]);
						vis[p[i]]=1;
					}
				}
			}
		}		
		printf("\n");
	}
	return 0;
}



