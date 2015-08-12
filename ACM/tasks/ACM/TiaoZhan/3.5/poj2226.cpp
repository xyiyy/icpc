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
int V;
const int MAX_V=510;
bool G[MAX_V][MAX_V];
//vector<int> G[MAX_V];
int match[MAX_V];
bool used[MAX_V];
int X,Y;
char Map[MAX_V][MAX_V];
PII edge[MAX_V][MAX_V];

bool dfs(int v)//Ôö¹ãÂ· 
{
	int t;
	for(int i=0;i<Y;i++)
	{
		if(G[v][i]&&!used[i])
		{
			used[i]=1;
			t=match[i];
			match[i]=v;
			if(t==-1||dfs(t))
			{
				return 1;
			}
			match[i]=t;
		}
		
	}
	return false ;
}

int hungary()
{
	int res=0;
	CLR(match,-1);
	for(int v=0;v<X;v++)
	{
		CLR(used,0);			
		if(dfs(v))
		{
			res++;
		}
	}
	return res;
}
int main()
{
	ios::sync_with_stdio(false);
	int n,m;
	while(cin>>n>>m)
	{
		CLR(G,0);
		for(int i=0;i<n;i++)
		{
			for(int j=0;j<m;j++)
			{
				cin>>Map[i][j];
			}
		}
		X=Y=0;
		for(int i=0;i<n;i++)
		{
			int j=0;
			while(j<m)
			{
				while(j<m&&Map[i][j]=='.')
				{
					j++;
				}
				if(j>=m)break;
				while(j<m&&Map[i][j]=='*')
				{
					edge[i][j].first=X;
					j++;
				}
				X++;
			}
		}
		for(int i=0;i<m;i++)
		{
			int j=0;
			while(j<n)
			{
				while(j<n&&Map[j][i]=='.')j++;
				if(j>=n)break;
				while(j<n&&Map[j][i]=='*')
				{
					edge[j][i].second=Y;
					j++;
				}
				Y++;
			}
		}
		for(int i=0;i<n;i++)
		{
			for(int j=0;j<m;j++)
			{
				if(Map[i][j]=='*')
				{
					G[edge[i][j].first][edge[i][j].second]=1;
				}
			}
		}
		cout<<hungary()<<endl;
	}
		
				
	
	return 0;
}



