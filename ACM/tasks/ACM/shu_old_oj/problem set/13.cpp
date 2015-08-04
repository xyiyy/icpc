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
const int maxn=1010;
bool G1[maxn][maxn];
int main()
{
	ios::sync_with_stdio(false);
	int n,m,u,v,t;
	cin>>t;
	ll num;
	while(t--)
	{
		cin>>n>>m;
		CLR(G1,0);
		for(int i=0;i<m;i++)
		{
			cin>>u>>v;
			G1[u][v]=1;
			G1[v][u]=1;
		}
		num=0;
		for(int i=1;i<=n;i++)
		{
			for(int j=i+1;j<=n;j++)
			{
				for(int k=j+1;k<=n;k++)
				{
					if(G1[j][k]==G1[i][j]&&G1[i][j]==G1[i][k])num++;
				}
			}
		}
		cout<<num<<endl;
	}
			
	return 0;
}



