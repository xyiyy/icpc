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
//#define INF 0x3FFFFFFF
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
const ll INF = 1ll<<62; 
const int maxn=55;
typedef pair<long long ,int >PLI;
vector<int > G[maxn];
ll dis[maxn];
void dijkstra(int u,ll p)
{
	REP(i,maxn)dis[i] = i==u ? p : INF;
	int vis[maxn]={0};
	CLR(vis,0);
	/*for(int i=0;i<52;i++)
	{
		int id;
		ll minn=INF;
		for(int j=1;j<=52;j++)
		{
			if(!vis[j]&&dis[j]<minn)
			{
				minn=dis[j];
				id=j;
			}
		}
		if(minn==INF)
		{
			break;
		}
		vis[id]=1;
		for(int j=0;j<G[id].size();j++)
		{
			ll temp;
			if(id<27)temp=(ll)ceil(dis[id]/19.0);
			else temp=1;
			if(dis[id]+temp<dis[G[id][j]]&&!vis[G[id][j]])
			{
				dis[G[id][j]]=dis[id]+temp;
			}
		}
	}*/
	priority_queue<PLI,vector<PLI>,greater<PLI> > q;
	q.push(MP(p,u));
	while(!q.empty())
	{
		PLI pa=q.top();
		q.pop();
		int x=pa.second;
		if(vis[x])continue;
		vis[x]=1;
		for(int j=0;j<G[x].size();j++)
		{
			int y=G[x][j];
			if(!vis[y])
			{
				if(x<=26&&(dis[y]>(dis[x]+(ll)ceil((dis[x])/19.0))))
				{
					dis[y]=dis[x]+(ll)ceil((dis[x])/19.0);
					q.push(MP(dis[y],y));
				}
				else if(x>26&&dis[y]>dis[x]+1)
				{
					dis[y]=dis[x]+1;
					q.push(MP(dis[y],y));
				}
			}
		}
	}
}
		
ll ddec;

int main()
{
	int n;
	char a[30],b[30];
	int cas=1;
	ll p;
	while(scanf("%d",&n)!=EOF)
	{
		if(n==-1)break;
		int u,v;
		for(int i=1;i<53;i++)G[i].clear();
		for(int i=0;i<n;i++)
		{
			scanf("%s%s",a,b);
			if(a[0]<='z'&&a[0]>='a')u=a[0]-'a'+27;
			else u=a[0]-'A'+1;
			if(b[0]<='Z'&&b[0]>='A')v=b[0]-'A'+1;
			else v=b[0]-'a'+27;
			G[u].PB(v);
			G[v].PB(u);
		}
		scanf("%lld%s%s",&p,a,b);
		if(a[0]<='z'&&a[0]>='a')u=a[0]-'a'+27;
		else u=a[0]-'A'+1;
		if(b[0]<='Z'&&b[0]>='A')v=b[0]-'A'+1;
		else v=b[0]-'a'+27;
		dijkstra(v,p);
		printf("Case %d:\n",cas++);
		printf("%lld\n",dis[u]);
		int now=u;
		printf("%c",a[0]);
		int minn=110;
		while(now!=v)
		{
			minn=110;
			for(int i=0;i<G[now].size();i++)
			{
				int y=G[now][i];
				if(y<=26)
				{
					ddec=(ll)ceil(dis[now]/20.0);
				}
				else 
				{
					ddec=1;
				}
				if(dis[now]-ddec==dis[y]&&minn>y)
				{
					minn=y;
				}
			}
			printf("-%c", minn<27?(minn-1+'A'):(minn-27+'a'));
			now=minn;
		}
		printf("\n");
			 
	}
		
		
		
		
	return 0;
}


