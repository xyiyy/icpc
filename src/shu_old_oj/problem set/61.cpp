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
int dirx[8]={-2,-2,-1,-1,1,1,2,2};
int diry[8]={1,-1,2,-2,2,-2,1,-1};
int dis[9][9];
bool vis[9][9];
char xx1,xx2;
int yy1,yy2;
int bfs()
{
	CLR(vis,0);
	CLR(dis,INF);
	int sx=xx1-'a'+1;
	int sy=yy1;
	int gx=xx2-'a'+1;
	int gy=yy2;
	queue<PII>que;
	que.push(MP(sx,sy));
	dis[sx][sy]=0;
	vis[sx][sy]=1;
	PII p;
	int x,y,dx,dy;
	while(!que.empty())
	{
		p=que.front();
		que.pop();
		x=p.first,y=p.second;
		for(int i=0;i<8;i++)
		{
			dx=x+dirx[i],dy=y+diry[i];
			if(dx>0&&dx<=8&&dy>0&&dy<=8&&!vis[dx][dy])
			{
				dis[dx][dy]=dis[x][y]+1;
				que.push(MP(dx,dy));
				vis[dx][dy]=1;
			//	if(dx==gx&&dy==gy)return dis[dx][dy];
			}
		}
	}
	return dis[gx][gy];
}

		
		
	
int main()
{
	ios::sync_with_stdio(false);
	while(cin>>xx1>>yy1>>xx2>>yy2)
	{
		cout<<xx1<<yy1<<"==>"<<xx2<<yy2<<": "<<bfs()<<" moves"<<endl;
	}
	return 0;
}



