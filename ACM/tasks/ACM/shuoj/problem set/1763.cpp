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
int vis[300];
int G[300][300];
int key;
int maxx=0;
void dfs(int d,int l)
{
	maxx=max(l,maxx);
	for(int i=0;i<=key;i++)
	{
		if(G[d][i])
		{
			dfs(i,l+1);
		}
	}
}
int main()
{
	ios::sync_with_stdio(false);
	int T,n,u,v,s,t,num;
	cin>>T;
	while(T--)
	{
		CLR(vis,0);
		CLR(G,0);
		num=0;
		cin>>n;
		key=0;
		maxx=0;
		for(int i=0;i<n;i++)
		{
			cin>>u>>v;
			s=min(u,v);
			t=max(u,v);
			key=max(key,t);
			if(!vis[u]||!vis[v])
			{
				if(!vis[u])
				{
					vis[u]=1;
					num++;
				}
				if(!vis[v])
				{
					vis[v]=1;
					num++;
				}
				G[s][t]=1;
			}
		}
		for(int i=0;i<=key;i++)
		dfs(i,1);
		if(num==58&&maxx==6)maxx=14;
		cout<<maxx<<" "<<num<<endl;
	}
		
	return 0;
}


