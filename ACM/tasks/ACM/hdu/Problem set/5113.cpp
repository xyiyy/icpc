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
const int maxn=30;
int a[maxn];
bool flag=0;
int ans[10][10];
int n,m,k;
void dfs(int x,int y,int left)
{
	if(!left)
	{
		flag=1;
		return;
	}
	for(int i=1;i<=k;i++)
		if(a[i]>(left+1)/2)return;
	for(int i=1;i<=k;i++)
	{
		if(!a[i])continue;
		if(x&&ans[x-1][y]==i)continue;
		if(y&&ans[x][y-1]==i)continue;
		a[i]--;
		ans[x][y]=i;
		if(y<m-1)dfs(x,y+1,left-1);
		else dfs(x+1,0,left-1);
		if(flag)return;
		a[i]++;	
	}
	return;
}
bool scan_d(int &ret){
	char c;int sgn;
	while(c!='-'&&(c<'0'||c>'9'))c=getchar();
	sgn=(c=='-')?-1:1;
	ret=(c=='-')?0:(c-'0');
	while(c=getchar(),c>='0'&&c<='9')
	{
		ret=ret*10+(c-'0');
	}
	ret*=sgn;
	return 1;
}
void out(int x)
{
	if(x>9)out(x/10);
	putchar(x%10+'0');
}
int main()
{
	//ios::sync_with_stdio(false);
	int t;
	scan_d(t);
	int cas=1;
	while(t--)
	{
		flag=0;
		scan_d(n);
		scan_d(m);
		scan_d(k);
		int sum=0;
		int maxx=0;
		int tot=n*m;
		for(int i=1;i<=k;i++)
			scan_d(a[i]);
		printf("Case #%d:\n",cas++);
		dfs(0,0,tot);
		if(flag)
		{
			printf("YES\n");
			for(int i=0;i<n;i++)
			{
				for(int j=0;j<m;j++)
				{
					if(j)putchar(' ');
					out(ans[i][j]);
				}
				puts("");
			}
		}
		else 
			printf("NO\n");
	}
	return 0;
}



