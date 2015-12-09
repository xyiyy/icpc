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
int m,n;
const int dx[5]={-1,0,0,0,1};
const int dy[5]={0,1,0,-1,0};
const int maxn=20;
int a[maxn][maxn];
int ans[maxn][maxn];
int temp[maxn][maxn];

bool in(int x,int y)
{
	return x>=0&&x<m&&y>=0&&y<n;
}
int query(int x,int y)
{
	int c=a[x][y];
	for(int i=0;i<5;i++)
	{
		int dx1=x+dx[i],dy1=y+dy[i];
		if(in(dx1,dy1))
		{
			c+=temp[dx1][dy1];
		}
	}
	return c%2;
}

int fun()
{
	for(int i=1;i<m;i++)
	{
		for(int j=0;j<n;j++)
		{
			if(query(i-1,j)!=0)
			{
				temp[i][j]=1;
			}
		}
	}
	for(int j=0;j<n;j++)
	{
		if(query(m-1,j)!=0)
		{
			return -1;
		}
	}
	int res=0;
	for(int i=0;i<m;i++)
	{
		for(int j=0;j<n;j++)
		{
			res+=temp[i][j];
		}
	}
	return res;
}

void solve()
{
	int res=-1;
	for(int i=0;i<(1<<n);i++)
	{
		CLR(temp,0);
		for(int j=0;j<n;j++)
		{
			temp[0][n-1-j]=i>>j&1;
		}
		int num=fun();
		if(num>=0&&(res<0||res>num))
		{
			res=num;
			for(int i=0;i<m;i++)
			{
				for(int j=0;j<n;j++)
				{
					ans[i][j]=temp[i][j];
				}
			}
		}
	}
	if(res<0)
	{
		cout<<"IMPOSSIBLE"<<endl;
	}
	else
	{
		for(int i=0;i<m;i++)
		{
			for(int j=0;j<n;j++)
			{
				if(j)cout<<" ";
				cout<<ans[i][j];
			}
			cout<<endl;
		}
	}
}



int main()
{
	ios::sync_with_stdio(false);
	while(cin>>m>>n)
	{
		for(int i=0;i<m;i++)
		{
			for(int j=0;j<n;j++)
			{
				cin>>a[i][j];
			}
		}
		solve();
	}



	return 0;
}
