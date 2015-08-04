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
typedef pair<int,int> PII;
typedef vector<PII> VII;
typedef vector<int> VI;
typedef long long ll;
#define MAXN 1010
ll hash[MAXN][MAXN];
int n,m,p,t,q;
char a[MAXN][MAXN];
char b[MAXN];
ll tmp[MAXN];
bool ok()
{
	for(int i=0;i+p-1<n;i++)
	{
		for(int j=q-1;j<m;j++)
		{
			int flag=1;
			for(int k=0;k<p;k++)
			{
				if(hash[i+k][j]!=tmp[k])
				{
					flag=0;
					break;
				}
			}
			if(flag)return true;
		}
	}
	return false;
}
int main()
{
	ios::sync_with_stdio(false);
	int cas=0;
	while(scanf("%d%d%d%d%d",&n,&m,&t,&p,&q)!=EOF&&(n||m||t||p||q))
	{
		for(int i=0;i<n;i++)scanf("%s",a[i]);
		memset(hash,0,sizeof(hash));
		for(int i=0;i<n;i++)
		{
			for(int j=0;j<q;j++)
			{
				if(a[i][j]=='*')hash[i][q-1]|=(1LL<<j);
			}
		}
		for(int i=0;i<n;i++)
		{
			for(int j=q;j<m;j++)
			{
				if(a[i][j-q]=='*')hash[i][j]=hash[i][j-1]-1LL;
				else hash[i][j]=hash[i][j-1];
				hash[i][j]>>=1LL;
				if(a[i][j]=='*')hash[i][j]|=(1LL<<(q-1));
			}
		}
		int ans=0;
		while(t--)
		{
			for(int i=0;i<p;i++)
			{
				scanf("%s",b);
				tmp[i]=0;
				for(int j=0;j<q;j++)
				{
					if(b[j]=='*')tmp[i]|=(1LL<<j);
				}
			}
			if(ok())ans++;
		}
		printf("Case %d: %d\n",++cas,ans);
	}
	return 0;
}



