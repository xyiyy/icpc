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
int a[5][5];
int dx[4]={-1,0,0,1};
int dy[4]={0,1,-1,0};
int num;
set<int > s;
void dfs(int x,int y,int res,int k)
{
	if(k==6)
	{
		s.insert(res);
		return ;
	}
	else 
	{
	//	cout<<x<<"  "<<y<<"  "<<res<<"  "<<k<<endl;
		//res=res*10+a[x][y];
		for(int i=0;i<4;i++)
		{
			int tx=x+dx[i];
			int ty=y+dy[i];
			if(tx>=0&&tx<5&&ty>=0&&ty<5)
			{
				dfs(tx,ty,res*10+a[tx][ty],k+1);
			}
		}
	}
	return ;
}
	
	
int main()
{
	ios::sync_with_stdio(false);
	while(cin>>a[0][0])
	{
		num=0;
		s.clear();
		for(int i=0;i<5;i++)
		{
			for(int j=0;j<5;j++)
			{
				if(i==j&&i==0)
				continue;
				else cin>>a[i][j];
			}
		}
		for(int i=0;i<5;i++)
		{
			for(int j=0;j<5;j++)
			{
				dfs(i,j,a[i][j],1);
			}
		}
		cout<<s.size()<<endl;
	}
	return 0;
}


