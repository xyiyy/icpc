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
#define INF 0x3FFFFF
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
int a[310][310];
int vis[310][310];
int d[310][310]; 
int dx[4]={-1,0,0,1};
int dy[4]={0,1,-1,0};
//int vis[310][310];
int sx,sy;
int num;
queue<PII> q;
void bfs()
{
	CLR(vis,0);
	
	int tx,ty,x,y;
	while(!q.empty())q.pop();
	if(a[sx][sy]<0)
	{
		num=-1;
		return ;
	}
	q.push(MP(sx,sy));
	num=0;
	vis[0][0]=1;
	d[sx][sy]=0;
	int flag=0;
	while(q.size())
	{
		PII p=q.front();
		q.pop();
		x=p.first;
		y=p.second;
		if(a[x][y]==INF)
		{
			num=d[x][y];
			flag=1;
			break;
		}
		for(int i=0;i<4;i++)
		{
			tx=x+dx[i];
			ty=y+dy[i];
			if(tx>=0&&tx<310&&ty>=0&&ty<310&&a[tx][ty]>d[x][y]+1&&!vis[tx][ty])
			{
				vis[tx][ty]=1;
				d[tx][ty]=d[x][y]+1;
				q.push(MP(tx,ty));
				vis[tx][ty]=1;
			}
		}
	}
	if(!flag)num=-1;
}
int main()
{
	ios::sync_with_stdio(false);
	int x,y,t;
	int tx,ty;
	while(cin>>n)
	{
		for(int i =0;i<310;i++)
		{
			for(int j=0;j<310;j++)
			{
				a[i][j]=INF;
			}
		}
		CLR(d,0);
		CLR(vis,0);
		for(int i=0;i<n;i++)
		{
			cin>>x>>y>>t;
			a[x][y]=min(t,a[x][y]);
			for(int i=0;i<4;i++)
			{
				tx=x+dx[i];
				ty=y+dy[i];
				if(tx>=0&&tx<310&&ty>=0&&ty<310)
				{
					a[tx][ty]=min(t,a[tx][ty]);
				}
			}
		}
		sx=0;sy=0;
		bfs();
		//if(num>=0)
		cout<<num<<endl;
		//else cout<<""
	}
	return 0;
}


