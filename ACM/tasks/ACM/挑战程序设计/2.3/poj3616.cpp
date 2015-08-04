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
int lx[1010],rx[1010],e[1010];
int id[1010];
int dp[1010][2];
bool cmp(int x,int y)
{
	return rx[x]<rx[y];
}
int main()
{
	ios::sync_with_stdio(false);
	int N,n,r;
	while(cin>>N>>n>>r)
	{
		CLR(dp,0);
		for(int i=1;i<=n;i++)
		{
			cin>>lx[i]>>rx[i]>>e[i];
			id[i]=i;
		}
		sort(id+1,id+n+1,cmp);
		for(int i=1;i<=n;i++)
		{
			dp[id[i]][1]=e[id[i]];
			for(int j=i-1;j>0;j--)
			{
				if(lx[id[i]]>=rx[id[j]]+r)
				dp[id[i]][1]=max(dp[id[i]][1],max(dp[id[j]][1]+e[id[i]],dp[id[j]][0]+e[id[i]]));
				dp[id[i]][0]=max(dp[id[i]][0],max(dp[id[j]][1],dp[id[j]][0]));
			}
			//cout<<dp[id[i]][0]<<"   "<<dp[id[i]][1]<<endl;
		}
		cout<<max(dp[id[n]][0],dp[id[n]][1])<<endl;
	}
	return 0;
}


