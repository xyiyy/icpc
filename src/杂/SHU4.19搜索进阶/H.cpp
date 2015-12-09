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
using namespace std;
#define XINF INT_MAX
#define INF 0x3FFFFFFF
#define MP(X,Y) make_pair(X,Y)
#define PB(X) push_back(X)
#define REP(X,N) for(int X=0;X<N;X++)
typedef pair<int,int> PII;
typedef vector<int> VI;
typedef long long ll;
int A[2010][2010];
int G[2010][2010]; 
int rG[2010][2010];
bool vis[2010];
vector <int> vs;
int n;
void dfs(int x)
{
	vis[x]=1;
	for(int i=1;i<=n;i++)
	{
		if(!vis[i]&&G[x][i])dfs(i);
	}
	vs.push_back(x);
}

void rdfs(int x)
{
	vis[x]=1;
	for(int i=1;i<=n;i++)
	{
		if(!vis[i]&&rG[x][i])rdfs(i);
	}
}

int scc()
{
	memset(vis,0,sizeof(vis));
	vs.clear();
	dfs(1);
	for(int i=2;i<=n;i++)
	{
		if(!vis[i])return 0;
	}
	memset(vis,0,sizeof(vis));
	rdfs(vs[n-1]);
	for(int i=n-2;i>=0;i--)
	{
		if(!vis[vs[i]])return 0;
	}
	return 1;
}
int main()
{
	ios::sync_with_stdio(false);
	//int n;
	while(cin>>n)
	{
		memset(A,0,sizeof(A));
		memset(G,0,sizeof(G));
		memset(rG,0,sizeof(rG));
		for(int i=1;i<=n;i++)
		{
			for(int j=1;j<=n;j++)
			{
				cin>>A[i][j];
				if(i==j)continue;
				if(A[i][j]>0)G[i][j]=1,rG[j][i]=1;
			}
		}
		if(scc())
		{
			cout<<"YES"<<endl;
		}
		else 
		{
			cout<<"NO"<<endl;
		}
	}
		
		
	return 0;
}

