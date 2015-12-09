//gaoshenbaoyou  ------ pass system test
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
int n;
int d[2010][2010];
priority_queue<PII,vector<PII>,greater<PII> >q;
vector<PII>G[2010];
bool vis[2010];//[2010];
/**********************************
	并查集模板 
	2014.3.18
**********************************/

#define MAXN 3000

int pa[MAXN]; // parent
int ra[MAXN]; // rank
 
void init(int n)
{
	for(int i = 0; i < n; i++)
	{
		pa[i] = i;
		ra[i] = 0;
	}
}

int find(int x)
{
	if(pa[x]!=x) pa[x] = find(pa[x]);
	return pa[x];
}

// 0: already united;  1: successfully united;
int unite(int x, int y)
{
	x = find(x);
	y = find(y);
	if(x==y)return 0;
	if(ra[x] < ra[y])
	{
		pa[x] = y;
	}else{
		pa[y] = x;
		if(ra[x] == ra[y]) ra[x]++;
	}
	return 1;
}

bool same(int x, int y)
{
	return find(x) == find(y);
}
bool flag=1;

void dfs(int x,int y,ll sum)
{
	if(vis[y]||!flag)return;
	vis[y]=1;
	//if(x==y)
	for(int i=0;i<G[y].size();i++)
	{
	//	cout<<d[x][G[y][i].first]<<" "<<sum<<" "<<G[y][i].second<<" "<<x<<" "<<G[y][i].first<<endl;
		if(vis[G[y][i].first])continue;
		if(d[x][G[y][i].first]!=sum+G[y][i].second)
			flag=0;
		dfs(x,G[y][i].first,sum+G[y][i].second);	
	}
}
	
int main()
{
	ios::sync_with_stdio(false);
	int n;
	while(scanf("%d",&n)!=EOF)
	{
		flag=1;
		init(n);
		//bool flag=1;
	//	int maxx=0;
	//	int minn=INF;
		for(int i=0;i<n;i++)
		{
			for(int j=0;j<n;j++)
			{
				scanf("%d",&d[i][j]);
		//		maxx=max(maxx,d[i][j]);
				if(i<j)
				q.push(MP(d[i][j],i*10000+j));
				if(i==j&&d[i][j]!=0)flag=0;
				if(i!=j&&d[i][j]==0)flag=0;
			}
		}
	//	if(maxx==0)flag=0;
	//	if(minn==0)flag=0;
		for(int i=0;i<n;i++)
		{
			for(int j=i+1;j<n;j++)
			{
				if(d[i][j]!=d[j][i])flag=0;
			}
		}
		if(flag)
		{
			//CLR(d,0);
			while(!q.empty())
			{
				PII p=q.top();
				q.pop();
				if(!same((p.second)/10000,p.second%10000))
				{
				//if(!d[p.second.first][p.second.first])
					//d[p.second.first][p.second.second]=p.first;
					unite(p.second/10000,p.second%10000);
				//	cout<<p.second/10000<<"  "<<p.second%10000<<endl;
					G[p.second/10000].PB(MP(p.second%10000,p.first));
					G[p.second%10000].PB(MP(p.second/10000,p.first));
				}
			}
			for(int i=0;i<n;i++)
			{
				CLR(vis,0);
				dfs(i,i,0LL);
			}
		}
		if(flag)printf("YES\n");
		else printf("NO\n");
	}
			
			
				
	return 0;
}



