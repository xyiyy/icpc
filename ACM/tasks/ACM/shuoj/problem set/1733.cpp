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
const int maxn=40;
int a[maxn][maxn];
int n,m;
bool in(int x,int y)
{
	if(x<n&&y<m)return 1;
	return 0;
}
int dfs(int x,int y)
{
	if(a[x][y])return 0;
	int k;
	for(k=1;in(x+k,y+k);k++)
	{
		for(int i=0;i<=k;i++)
		{
			if(a[x+k][y+i])return k;
		}
		for(int i=0;i<=k;i++)
		{
			if(a[x+i][y+k])return k;
		}
	}
	return k;
}


int main()
{
	ios::sync_with_stdio(false);
	int t;
	cin>>t;
	while(t--)
	{
		//CLR(a,0);
		cin>>n>>m;
		for(int i=0;i<n;i++)
		{
			for(int j=0;j<m;j++)
		 	{
		 		cin>>a[i][j];
		 	}
		}
		int len=0;
		for(int i=0;i<n;i++)
		{
			for(int j=0;j<m;j++)
			{
				len=max(len,dfs(i,j));
		 	}
		}
		cout<<len<<endl;
	}
	return 0;
}


