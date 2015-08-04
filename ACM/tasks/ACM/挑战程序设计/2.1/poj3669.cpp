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
int dir[4][2]={-1,0,0,-1,1,0,0,1};
int a[400][400];
int vis[400][400];
int d[400][400];

int step;
bool in(int x,int y)
{
	if(x<0||x>=400||y<0||y>=400)
	return 0;
	return 1;
}
	
bool bfs()
{
	CLR(vis,0);
	CLR(d,0);
	queue<PII> q;
	while(!q.empty())q.pop();
	q.push(MP(0,0));
	PII p;
	int x,y;
	int dx,dy;
	if(a[0][0]<=0)return 0;
	d[0][0]=0;
	vis[0][0]=1;
	while(q.size())
	{
		p=q.front();
		q.pop();
		x=p.first;
		y=p.second;
		//vis[x][y]=1;
		if(a[x][y]==INF)
		{
			step=d[x][y];
			return 1;
		}
		for(int i=0;i<4;i++)
		{
			dx=x+dir[i][0],dy=y+dir[i][1];
			if(in(dx,dy)&&!vis[dx][dy]&&(d[x][y]+1)<a[dx][dy])
			{
				q.push(MP(dx,dy));
				d[dx][dy]=d[x][y]+1;
				vis[dx][dy]=1;
			}
		}
	}
	return 0;
}


int main()
{
	ios::sync_with_stdio(false);
	int m;
	while(cin>>m)
	{
		for(int i=0;i<400;i++)
		{
			for(int j=0;j<400;j++)
			{
				a[i][j]=INF;
			}
		}
		int x,y,t;
		int dx,dy;
		for(int i=0;i<m;i++)
		{
			cin>>x>>y>>t;
			a[x][y]=min(a[x][y],t);
			for(int j=0;j<4;j++)
			{
				dx=x+dir[j][0],dy=y+dir[j][1];
				if(in(dx,dy))
				{
					a[dx][dy]=min(a[dx][dy],t);
				}
			}
		}
		if(bfs())
		{
			cout<<step<<endl;
		}
		else cout<<-1<<endl;
	}
	return 0;
}


