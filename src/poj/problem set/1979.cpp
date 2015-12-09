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
char a[25][25];
int vis[25][25];
int n,m;
int num=0;
int dirx[4]={-1,0,0,1};
int diry[4]={0,1,-1,0};
void dfs(int x,int y)
{
	if(a[x][y]=='#'||vis[x][y]==1)return ;
	if(x<0||x>=n||y<0||y>=m)return ;
	if((a[x][y]=='.'&&vis[x][y]==0)||(vis[x][y]==0&&a[x][y]=='@'))
	{
		vis[x][y]=1;
		num++;
		for(int i=0;i<4;i++)
		{
			dfs(x+dirx[i],y+diry[i]);
		}
	}
	return ;
}
int main()
{
	ios::sync_with_stdio(false);

	int sx,sy;
	while(cin>>m>>n&&(m||n))
	{
		CLR(vis,0);
		for(int i=0;i<n;i++)
		{
			for(int j=0;j<m;j++)
			{
				cin>>a[i][j];
				if(a[i][j]=='@')
				{
					sx=i;
					sy=j;
				}
			}
		}
	//	vis[sx][sy]=1;
	//	num=1;
		num=0;
		dfs(sx,sy);
		cout<<num<<endl;
	}
		
	return 0;
}


