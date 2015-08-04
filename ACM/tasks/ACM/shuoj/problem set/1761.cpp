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
const int maxn=10010;
int pre[maxn];
bool vis[maxn];
void dfs1(int x)
{
	vis[x]=1;
	if(x==0)return;
	dfs1(pre[x]);
	return;
}
int dfs2(int y)
{
	if(vis[y])return y;
	return dfs2(pre[y]);
}
int main()
{
	ios::sync_with_stdio(false);
	int t,n,m;
	int cas=1;
	cin>>t;
	while(t--)
	{
		cin>>n;
		int u,v;
		for(int i=0;i<n;i++)
		{
			 cin>>u>>v;
			 pre[v]=u;
		}
		cout<<"Case "<<cas++<<":"<<endl;
		cin>>m;
		int x,y;
		for(int i=0;i<m;i++)
		{
			cin>>x>>y;
			CLR(vis,0);
			dfs1(x);
			//cout<<endl;
			if(i)cout<<" ";
			cout<<dfs2(y);
		}
		cout<<endl;
	}	
	return 0;
}


