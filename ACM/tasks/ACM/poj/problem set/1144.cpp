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
int n; 
int G[110][110],vis[110];
int low[110],label[110];
int dclock,cri;

void dfs(int v)
{
	int minn=0;
	vis[v]=minn=++dclock;
	for(int i=1;i<=n;i++)
	{
		if(G[v][i]==1)
		{
			if(vis[i]==0)
			{
				dfs(i);
				if(low[i]<minn)minn=low[i];
				if(low[i]>=vis[v])label[v]=1;
			}
			else if(vis[i]<minn)minn=vis[i];
		}
	}
	low[v]=minn;
}

int main()
{
	ios::sync_with_stdio(false);
	string s;
	 while(cin>>n&&n)
	 {
	 	memset(G,0,sizeof(G));
	 	memset(vis,0,sizeof(vis));
	 	memset(label,0,sizeof(label));
	 	memset(low,0,sizeof(low));
	 	cri=0;
	 	dclock=0;
	 	cin.ignore();
	 	while(getline(cin,s,'\n'))
	 	{
		 	stringstream ss(s);
		 	int u,v;
		 	ss>>u;
		 	if(u==0)
		 	break;
		 	else{
		 		while(ss>>v)
		 		{
		 			G[u][v]=G[v][u]=1;
		 		}
		 	}
		 }
		 vis[1]=++dclock;
		 low[1]=1;
		 int i;
		 for(i=1;i<=n;i++)
		 {
		 	if(G[1][i]==1)break;
		 }
		 dfs(i);
		 if(dclock<n)
		 {
		 	label[1]=1;
		 	for(i=1;i<=n;i++)
		 	{
		 		if(G[1][i]&&vis[i]==0)
		 		dfs(i);
		 	}
		 }
		 for(int i=1;i<=n;i++)
		 {
		 	if(label[i]==1) cri++;
		 }
		 cout<<cri<<endl;
	}	
	return 0;
}

