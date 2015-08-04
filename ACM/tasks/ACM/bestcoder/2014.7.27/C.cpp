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
vector<int> G[1010];
ll x[1010];
ll y[1010];
bool vis[1010];
int last[1010];
queue<int > que;
int sz,pos;
int t,n,times;
ll l;
ll sx,sy,d;
ll ex,ey;
int main()
{
	ios::sync_with_stdio(false);
	scanf("%d",&t);
	while(t--)
	{
		scanf("%d %I64d",&n,&l);
		for(int i=0;i<1010;i++)G[i].clear();
		while(!que.empty())que.pop();
		scanf("%I64d %I64d",&sx,&sy);
		scanf("%I64d %I64d",&ex,&ey);
		x[0]=sx,x[n+1]=ex;
		y[0]=sy,y[n+1]=ey;
		CLR(vis,0);
		for(int i=1;i<=n;i++)
		{
			scanf("%I64d %I64d",&x[i],&y[i]);
		}
		for(int i=0;i<=n+1;i++)
		{
			for(int j=0;j<=n+1;j++)
			{
				if(i==j)continue;
				d=(x[i]-x[j])*(x[i]-x[j])+(y[i]-y[j])*(y[i]-y[j]);
				if(d<=l*l)
				{
					G[i].PB(j);
					G[j].PB(i);
				}
			}
		}
		
		sz=G[0].size();
		pos=0;
		vis[0]=1;
		while(pos<sz)
		{
			que.push(G[0][pos]);
			last[0]=G[0][pos];
			vis[G[0][pos]]=1;
			pos++;
		}
		d=0;
		times=0;
		while(que.size())
		{
			d=que.front();
			que.pop();
			if(d==n+1)
			{
				break;
			}
			sz=G[d].size();
			pos=0;
			while(pos<sz)
			{
				if(!vis[G[d][pos]])
				{
					que.push(G[d][pos]);
					last[times+1]=G[d][pos];
					vis[G[d][pos]]=1;
				}
				pos++;
			}
			//last[d]=G[d][pos-1];
			if(d==last[times])
			times++;
		}
		if(d!=n+1)
		{
			printf("impossible\n");
		}
		else
		{
		//	if(!times)
			printf("%d\n",times);
		//	else 
		//	printf("%d\n",times+1);
		}
			
	}
				
			
		
		
	return 0;
}


