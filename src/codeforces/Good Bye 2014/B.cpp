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
char G[310][310];
int a[310];
int id[310];
int ans[310];
bool cmp(int x,int y)
{
	return a[x]<a[y];
}
int main()
{
	ios::sync_with_stdio(false);
	int n;
	while(cin>>n)
	{
		for(int i=0;i<n;i++)
		{
			cin>>a[i];
			id[i]=i;
		}
		sort(id,id+n,cmp);
		CLR(G,0);
		for(int i=0;i<n;i++)
		{
			for(int j=0;j<n;j++)
			{
				cin>>G[i][j];
			}
		}
		for(int k=0;k<n;k++)
		{
			for(int i=0;i<n;i++)
			{
				for(int j=0;j<n;j++)
				{
					if(G[i][k]=='1'&&G[k][j]=='1')G[i][j]='1';
				}
			}
		}
		for(int i=0;i<n;i++)G[i][i]='1';
		/*for(int i=0;i<n;i++)
		{
			for(int j=0;j<n;j++)
			{
				cout<<char('0'+G[i][j])<<" ";
			}
			cout<<endl;
		}*/
	//	for(int i=0;i<n;i++)cout<<id[i]<<endl;
		CLR(ans,0);
		for(int i=0;i<n;i++)
		{
			for(int j=0;j<n;j++)
			{
				if(G[id[i]][j]=='1'&&ans[j]==0)
				{
					ans[j]=a[id[i]];
					break;
				}
			}
		}
		for(int i=0;i<n;i++)
		{
			cout<<ans[i]<<" ";
		}
		cout<<endl;
	}
	return 0;
}



