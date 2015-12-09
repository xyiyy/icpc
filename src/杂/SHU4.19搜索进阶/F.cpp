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
//#include <map>
#include <cstdio>
#include <cstdlib>
#include <cmath>
#include <cstring>
#include <climits>
using namespace std;
#define XINF INT_MAX
#define INF 0x3FFFFFFF
#define MP(X,Y) make_pair(X,Y)
#define PB(X) push_back(X)
#define REP(X,N) for(int X=0;X<N;X++)
typedef pair<int,int> PII;
typedef vector<int> VI;
typedef long long ll;
char map[220][220];
int dx[4]={-1,0,0,1};
int dy[4]={0,1,-1,0};
int n,m;
struct node
{
	int x,y,step;
	bool friend operator <(node a,node b)
	{
		return a.step>b.step;
	}
};

int bfs(node angle)
{
	priority_queue<node> q;
	q.push(angle);
	node now,next;
	while(!q.empty())
	{
		now=q.top();
		q.pop();
		for(int i=0;i<4;i++)
		{
			next.x=now.x+dx[i];
			next.y=now.y+dy[i];
			if(map[next.x][next.y]=='r')
			{
				next.step=now.step+1;
				while(!q.empty())
				{
					q.pop();
				}
				return next.step;
			}
			int x=next.x;int y=next.y;
			if(x>=0&&y>=0&&x<n&&y<m&&map[x][y]!='#')
			{
				if(map[x][y]=='x')
				{
					next.step=now.step+2;
					map[x][y]='#';
					q.push(next);
				}
				else
				{
					next.step=now.step+1;
					map[x][y]='#';
					q.push(next);
				}
			}
		}
	}
	return -1;
}



int main()
{
	ios::sync_with_stdio(false);
	while(cin>>n>>m)
	{
		int sx,sy;
		for(int i=0;i<n;i++)
		{
			for(int j=0;j<m;j++)
			{
				cin>>map[i][j];
				if(map[i][j]=='a')
				{
					sx=i;
					sy=j;
				}
			}
		}
		node angle;
		angle.x=sx;
		angle.y=sy;
		angle.step=0;
		int step=bfs(angle);
		if(step<0)cout<<"Poor ANGEL has to stay in the prison all his life."<<endl;
		else cout<<step<<endl;
	}
		
	return 0;
}

