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
int G[101][101];
bool vis[10];
bool flag;
bool dfs(int x,int y)
{
	vis[G[x][y]]=1;
	if(x==9)
	{
		flag=1;
		return 1;
	}
	if(vis[G[x+1][y]]==0)
	{
		if(dfs(x+1,y))
		{
			return 1;
		}
		vis[G[x+1][y]]=0;
	}
	if(vis[G[x+1][y+1]]==0)
	{
		if(dfs(x+1,y+1))
		{
			return 1;
		}
		vis[G[x+1][y+1]]=0;
	}
	//else return 0;
	return 0;
}
	
int main()
{
	ios::sync_with_stdio(false);
	int n;
	int cas=1;
	//bool flag;
	cin>>n;
	while(n--)
	{
		CLR(vis,0);
		for(int i=1;i<=9;i++)
		{
			for(int j=1;j<=i;j++)
			{
				cin>>G[i][j];
			}
		}
		int x=1,y=1;
		flag=0;
		//flag=dfs(x,y);
		dfs(x,y);
		cout<<"Case "<<cas++<<":"<<endl;
		if(flag)
		cout<<"Possible"<<endl;
		else cout<<"Impossible"<<endl;
	}
	
	return 0;
}


