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

long long dp[1000][1000];
long long a[110][3];
long long c[110][100];
int vis[21];
int main()
{
	ios::sync_with_stdio(false);
	int n,m,b;
	while(cin>>n>>m>>b)
	{
		memset(dp,0,sizeof(dp));
		memset(vis,0,sizeof(vis));
		for(int i=0;;i<n;i++)
		{
			cin>>a[i][0]>>a[i][1]>>a[i][2];
			for(int j=0;j<a[i][1];j++)
			{
				cin>>c[i][j];
			}
			
		}
		for()
		
	return 0;
}

