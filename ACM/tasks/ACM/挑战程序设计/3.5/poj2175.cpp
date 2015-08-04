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
const int MAX_V=410;
int X[110],Y[110],B[110];
int P[110],Q[110],C[110];
int E[110][110];
int n,m;
int g[MAX_V][MAX_V];
int pre[MAX_V][MAX_V];
bool used[MAX_V];
int V;
void solve()
{
	for(int k=0;k<V;k++)
	{
		for(int i=0;i<V;i++)
		{
			for(int j=0;j<V;j++)
			{
				if(g[i][j]>g[i][k]+g[k][j])
				{
					g[i][j]=g[i][k]+g[k][j];
					pre[i][j]=pre[k][j];
					if(i==j&&g[i][i]<0)
					{
						fill(used,used+V,0);
						for(int v=i;!used[v];v=pre[i][v])
						{
							used[v]=1;
							if(v!=n+m&&pre[i][v]!=n+m)
							{
								if(v>=n)
								{
									E[pre[i][v]][v-n]++;
								}
								else 
								{
									E[v][pre[i][v]-n]--;
								}
							}
						}
						cout<<"SUBOPTIMAL"<<endl;
						for(int x=0;x<n;x++)
						{
							for(int y=0;y<m;y++)
							{
								if(y)cout<<" ";
								cout<<E[x][y];
							}
							cout<<endl;
						}
						return ;
					}
				}
			}
		}
	}
	cout<<"OPTIMAL"<<endl;
}
					
int main()
{
	ios::sync_with_stdio(false);
	while(cin>>n>>m)
	{
		for(int i=0;i<n;i++)
		{
			cin>>X[i]>>Y[i]>>B[i];
		}
		for(int i=0;i<m;i++)
		{
			cin>>P[i]>>Q[i]>>C[i];
		}
		for(int i=0;i<n;i++)
		{
			for(int j=0;j<m;j++)
			{
				cin>>E[i][j];
			}
		}
		V=n+m+1;
		for(int i=0;i<V;i++)
		{
			fill(g[i],g[i]+V,INF);
		}
		for(int j=0;j<m;j++)
		{
			int sum=0;
			for(int i=0;i<n;i++)
			{
				int c=abs(X[i]-P[j])+abs(Y[i]-Q[j])+1;
				g[i][n+j]=c;
				if(E[i][j]>0)
				{
					g[n+j][i]=-c;
				}
				sum+=E[i][j];
			}
			if(sum>0)
			{
				g[n+m][n+j]=0;
			}
			if(sum<C[j])
			{
				g[n+j][n+m]=0;
			}
		}
	//
		for(int i=0;i<V;i++)
		{
			for(int j=0;j<V;j++)
			{
				pre[i][j]=i;
			}
		}
		solve();
		
	}
	return 0;
}



