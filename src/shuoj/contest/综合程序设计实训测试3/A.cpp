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
int G[1001][1001];
int main()
{
	ios::sync_with_stdio(false);
	int n,m;
	while(cin>>n>>m)
	{
		for(int i=0;i<n;i++)
		{
			for(int j=0;j<n;j++)
			{
				if(i==j)
				G[i][j]=0;
				else
				G[i][j]=INF;
			}
		}
		int x,y,z;
		for(int i=0;i<m;i++)
		{
			cin>>x>>y>>z;
			G[x][y]=z;
			G[y][x]=z;
		}
		for(int k=0;k<n;k++)
		{
			for(int i=0;i<n;i++)
			{
				for(int j=0;j<n;j++)
				{
					if(G[i][k]+G[k][j]<G[i][j])
					G[i][j]=G[i][k]+G[k][j];
				}
				
			}
		}
		cin>>x>>y;
		if(G[x][y]<INF)
		cout<<G[x][y]<<endl;
		else cout<<"-1"<<endl;
		
	}
			
	return 0;
}


