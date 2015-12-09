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
const int maxn=1010;
int dclock,cut[maxn],low[maxn],dfn[maxn];
vector<int>Map[maxn];
void tarjan(int u,int fa,int limit)
{
	if(u==limit)return;
	int son=0;
	dfn[u]=low[u]=dclock++;
//	cout<<u<<"  "<<dclock<<endl;
	for(int i=0;i<Map[u].size();i++)
	{
		int v=Map[u][i];
		if(v==limit)continue;
		if(dfn[v]<0)
		{
			tarjan(v,u,limit);
			son++;
			low[u]=min(low[v],low[u]);
			if((fa<0&&son>1)||(fa>=0&&low[v]>=dfn[u]))cut[u]=1;
		}
		else if(low[u]>low[v]&&v!=fa)
		{
			low[u]=min(low[u],dfn[v]);
		}
	}
}
int main()
{
	ios::sync_with_stdio(false);
	int n,m;
	while(cin>>n>>m&&(n||m))
	{
		int u,v;
		for(int i=0;i<n;i++)Map[i].clear();
		for(int i=0;i<m;i++)
		{
			cin>>u>>v;
			Map[u].PB(v);
			Map[v].PB(u);
		}
		bool flag=0;
		for(int i=0;i<n;i++)
		{
			dclock=0;
			CLR(dfn,-1);
			CLR(low,0);
			CLR(cut,0);
			tarjan((i+1)%n,-1,i);
			for(int j=0;j<n;j++)
			{
				if(i==j)continue;
				if(cut[j]||dfn[j]<0)flag=1;
			}
		//	cout<<flag<<endl;
			if(flag)break;
		}
		if(flag)cout<<"NO"<<endl;
		else cout<<"YES"<<endl;
	}
			
		
	return 0;
}



