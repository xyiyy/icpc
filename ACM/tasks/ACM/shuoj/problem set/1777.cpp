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
const int MAXN=210;
int G[MAXN][MAXN];

void Floyed()
{
	REP(k,MAXN)
	REP(i,MAXN)
	REP(j,MAXN)
	if(i!=j && i!=k && j!=k)
	{
		G[i][j] = min(G[i][j], G[i][k] + G[k][j]);
	}
}
int main()
{
	ios::sync_with_stdio(false);
	int n,m,k;
	int cas=1;
	while(cin>>n>>m>>k)
	{
		int u,v,l;
		for(int i=0;i<210;i++)
		{
			for(int j=0;j<210;j++)
			{
				G[i][j]=INF;
			}
		}
		for(int i=0;i<m;i++)
		{
			cin>>u>>v>>l;
			G[u][v]=l;
			G[v][u]=l;
		}
		Floyed();
		cout<<"Case "<<cas++<<endl;
		for(int i=0;i<k;i++)
		{
			cin>>u>>v;
			if(G[u][v]==INF)cout<<-1<<endl;
			else cout<<G[u][v]<<endl;
		}
	}
		
	return 0;
}


