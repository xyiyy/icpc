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
int G[110][110];
int vis[110];
int n,m;
int num;
int minn;
void dfs(int x,int cost)
{
	//cout<<num<<"  "<<x<<"   "<<cost<<endl;
	if(num==m)
	{
		minn=min(minn,cost);
		return ;
	}
	for(int i=0;i<m;i++)
	{
		if(G[x][i]&&!vis[i])
		{
			num++;
			vis[i]=1;
			dfs(i,cost+G[x][i]);
			num--;
			vis[i]=0;
		}
	}
	return ;
}
int main()
{
	ios::sync_with_stdio(false);
	int u,v,cap;
	while(cin>>n>>m&&n)
	{
		CLR(vis,0);
		CLR(G,0);
		minn=INF; 
		for(int i=0;i<n;i++)
		{
			cin>>u>>v>>cap;
			G[u-1][v-1]=G[v-1][u-1]=cap;
		}
		for(int i=0;i<m;i++)
		{
			vis[i]=1;
			num=1;
			dfs(i,0);
			CLR(vis,0);
		}
		if(minn==INF)
		{
			cout<<"?"<<endl;
		}
		else cout<<minn<<endl;
	}
	return 0;
}


