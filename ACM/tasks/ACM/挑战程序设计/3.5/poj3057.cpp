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
//int V;
const int MAX_V=144*144+144;
vector<int> G[MAX_V];
int match[MAX_V];
bool used[MAX_V];

void add_edge(int u,int v)
{
	G[u].PB(v);
	G[v].PB(u);
}

bool dfs(int v)//Ôö¹ãÂ· 
{
	used[v]=1;
	for(int i=0;i<G[v].size();i++)
	{
		int u=G[v][i],w=match[u];
		if(w<0||!used[w]&&dfs(w))
		{
			match[u]=v;
			match[v]=u;
			return 1;
		}	
	}
	return false ;
}
int dirx[4]={-1,0,0,1};
int diry[4]={0,-1,1,0};
const int MAX_X=13;
const int MAX_Y=13;
char field[MAX_X][MAX_Y+1];
vector<PII>door;
vector<PII>human;
int dis[MAX_X][MAX_Y][MAX_X][MAX_Y];
int X,Y;


void bfs(int x,int y,int d[MAX_X][MAX_Y])
{
	queue<PII> que;
	d[x][y]=0;
	que.push(MP(x,y));
	PII p;
	while(!que.empty())
	{
		//cout<<"ok"<<endl;
		p=que.front();
		que.pop();
		x=p.first;
		y=p.second;
		for(int k=0;k<4;k++)
		{
			int dx=x+dirx[k],dy=y+diry[k];
			if(dx>=0&&dx<X&&dy>=0&&dy<Y&&field[dx][dy]=='.'&&d[dx][dy]<0)
			{
				d[dx][dy]=d[x][y]+1;
			//	cout<<dx<<"    "<<dy<<endl;
				que.push(MP(dx,dy));
			}
		}
	}
}
void solve()
{
	cin>>X>>Y;
	int n=X*Y;
	door.clear();
	CLR(field,0);
	human.clear();
	CLR(dis,-1);
	for(int i=0;i<X;i++)
	{
		cin>>field[i];
	}
	for(int x=0;x<X;x++)
	{
		for(int y=0;y<Y;y++)
		{
			//cin>>field[x][y];				
			if(field[x][y]=='D')
			{
				door.PB(MP(x,y));
				bfs(x,y,dis[x][y]);
			}
			else if(field[x][y]=='.')
			{
				human.PB(MP(x,y));
			}
		}
	}
	int d=door.size();
	int p=human.size();
	for(int i=0;i<n*d+p;i++)
	{
		G[i].clear();
	}
	//cout<<d<<"   "<<p<<endl;
	int dx,dy,px,py;
	for(int i=0;i<d;i++)
	{
		dx=door[i].first,dy=door[i].second;
		for(int j=0;j<p;j++)
		{
			px=human[j].first,py=human[j].second;
			if(dis[dx][dy][px][py]>=0)
			{
				for(int k=dis[dx][dy][px][py];k<=n;k++)
				{
					add_edge((k-1)*d+i,n*d+j);
				}
			}
		}
	}
	if(p==0)
	{
		cout<<0<<endl;
		return;
	}
	int num=0;
	CLR(match,-1);
	for(int v=0;v<n*d;v++)
	{
		CLR(used,0);
		if(dfs(v))
		{
			//cout<<"ok"<<endl;
			if((++num)==p)
			{
				cout<<v/d+1<<endl;
				return ;
			}
		}
	}
	cout<<"impossible"<<endl;
}
		
	

int main()
{
	ios::sync_with_stdio(false);
	int t;
	cin>>t;
	while(t--)
	{
		solve();
	}
				
		 
	return 0;
}



