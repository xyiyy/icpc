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
int A,B,M,L,K;
int dp[20][110];
bool mark[110][110];	

int main()
{
	ios::sync_with_stdio(false);
	int t;
	cin>>t;
	while(t--)
	{
		int u,v,l;
		cin>>A>>B>>M>>L>>K;
		REP(i,A+B)
			REP(j,A+B)
			{
					G[i][j]=INF;
			}
		CLR(mark,0);	
		REP(i,M)
		{
			cin>>u>>v>>l;
			u--;v--;
			G[u][v]=l;
			G[v][u]=l;
			if(l<=L)mark[u][v]=mark[v][u]=1;
		}
		int N=A+B;
		
	//	REP(i,K)
	//		REP(j,N)
	//			dp[i][j]=INF;	
		REP(k,N)
		{
			REP(i,N)
			{
				REP(j,N)
				{
					G[i][j]=min(G[i][j],G[i][k]+G[k][j]);
					if(k<A&&G[i][j]<=L)mark[i][j]=mark[j][i]=1;
				}
			}
		}
		for(int i=0;i<N;i++)
		{
			dp[0][i]=G[i][0];
		}
		for(int i=0;i<=K;i++)
		{
			dp[i][0]=0;
		}
		int minn;
		for(int i=1;i<N;i++)
		{
			for(int k=1;k<=K;k++)
			{
				minn=INF;
				for(int j=0;j<i;j++)
				{
					if(mark[i][j])
					{
						minn=min(minn,dp[k-1][j]);
					}
					minn=min(minn,dp[k][j]+G[j][i]);
				}
				dp[k][i]=minn;
			}
		}
		cout<<dp[K][N-1]<<endl;
	}		
	return 0;
}


