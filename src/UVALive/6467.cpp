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
vector<int >edge[maxn];
int n,m;
int deg[maxn];
int pre[maxn];
int a[maxn],b[maxn];
int toposort()
{
	queue<int >q;
	for(int i=1;i<=n;i++)
	{
		a[i]=0;
		pre[i]=-1;
		b[i]=0;
		if(deg[i]==0)
		{
			q.push(i);
			b[i]=1;
			a[i]=1;
		}
	}
	while(!q.empty())
	{
		int x=q.front();
		q.pop();
		for(int i=0;i<edge[x].size();i++)
		{
			int y=edge[x][i];
			if(pre[y]==-1)
			{
				pre[y]=a[x];
				a[y]=a[x];
				b[y]=1;
			}
			else 
			{
				if(pre[y]<a[x])
				{
					pre[y]=a[x];
					a[y]=a[x];
					b[y]=1;
				}
				else if(pre[y]==a[x]&&b[y]==1)
				{
					if(a[y]!=a[x]+1)
					{
						a[y]=a[x]+1;
					}
				}
				
			}
			deg[y]--;
			if(deg[y]==0)q.push(y);
		}
	}
	int maxx=a[1];
	for(int i=2;i<=n;i++)
	{
		maxx=max(a[i],maxx);
	}
	
	cout<<maxx<<endl;
}
	
	
int main()
{
	ios::sync_with_stdio(false);
	int t,cas;
	cin>>t;
	while(t--)
	{
		int u,v;
		cin>>cas>>n>>m;
		CLR(deg,0);
		for(int i=0;i<maxn;i++)edge[i].clear();
		for(int i=0;i<m;i++)
		{
			cin>>u>>v;
			edge[u].PB(v);
			deg[v]++;
		}
		cout<<cas<<" ";
		toposort();
	}
	return 0;
}


