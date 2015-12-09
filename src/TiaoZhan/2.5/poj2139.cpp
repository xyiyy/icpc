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
int G[410][410];
void init(int n)
{
	for(int i=0;i<n;i++)
	{
		for(int j=0;j<n;j++)
		{
			if(i!=j)
			G[i][j]=INF;
			else G[i][j]=0;
		}
	}
}
int a[410];
int main()
{
	ios::sync_with_stdio(false);
	int n,m;
	while(cin>>n>>m)
	{
		init(n);
		int num;
		for(int i=0;i<m;i++)
		{
			cin>>num;
			for(int j=0;j<num;j++)
			{
				cin>>a[j];
				a[j]--;
			}
			for(int j=0;j<num;j++)
			{
				for(int k=0;k<num;k++)
				{
					if(a[j]!=a[k])
					G[a[j]][a[k]]=1;
				}
			}
		}
		for(int k=0;k<n;k++)
		{
			for(int i=0;i<n;i++)
			{
				for(int j=0;j<n;j++)
				{
					G[i][j]=min(G[i][j],G[i][k]+G[k][j]);
				}
			}
			
		}
		int minn=INF;
		int sum=0;
		for(int i=0;i<n;i++)
		{
			sum=0;
			for(int j=0;j<n;j++)
			{
				sum+=G[i][j];
			}
			minn=min(minn,sum);
		}
		cout<<minn*100/(n-1)<<endl;
	}
			
	return 0;
}


