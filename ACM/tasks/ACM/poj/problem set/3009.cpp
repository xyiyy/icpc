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
int a[25][25];
int vis[25][25];

int dx[4]={-1,0,0,1};
int dy[4]={0,1,-1,0};
int sx,sy;
int m,n;
int minn,num;
void dfs(int x,int y)
{
	if(num>10)return ;
	for(int i=0;i<4;i++)
	{
		int tx=x+dx[i];
		int ty=y+dy[i];
		if(a[tx][ty]==3)minn=min(minn,num);
		if(a[tx][ty]==1)continue;
		while(a[tx][ty]==0&&tx>=0&&tx<n&&ty>=0&&ty<m)
		{
			tx=tx+dx[i];
			ty=ty+dy[i];
			if(a[tx][ty]==3)
			{
				minn=min(minn,num);
				break;
			}
			if(a[tx][ty]==1)
			{
				num++;
				a[tx][ty]=0;
				dfs(tx-dx[i],ty-dy[i]);
				num--;
				a[tx][ty]=1;
				break;
			}
		}
	}
}

			
int main()
{
	ios::sync_with_stdio(false);

	while(cin>>m>>n&&(m||n))
	{
		num=1;
		CLR(a,0);
		minn=20;
		for(int i=0;i<n;i++)
		{
			for(int j=0;j<m;j++)
			{
				cin>>a[i][j];
				if(a[i][j]==2)
				{
					sx=i;
					sy=j;
					a[i][j]=0;
				}
			}
		}
		dfs(sx,sy);
		if(minn<=10)
		cout<<minn<<endl;
		else cout<<"-1"<<endl;
		
	}
	return 0;
}


