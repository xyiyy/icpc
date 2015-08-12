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
const int maxn=11;
vector<PII> road[maxn];
vector<PII> f[maxn];
int vis[maxn];
int ans=INF;
int n,m;
void dfs(int x,int fee)
{
	if(x==n&&ans>fee)
	{
		ans=fee;
		return;
	}
	int sz=road[x].size();
	for(int i=0;i<sz;i++)
	{
		int b=road[x][i].first;
		if(vis[road[x][i].first]<=3)
		{
			vis[b]++;
			if(vis[road[x][i].second])
			{
				dfs(b,fee+f[x][i].first);
			}
			else
			{
				dfs(b,fee+f[x][i].second);
			}
			vis[b]--;
		}
	}
}
	
	
int main()
{
	ios::sync_with_stdio(false);
	//int n,m;
	while(cin>>n>>m)
	{
		int a,b,c,p,r;
		for(int i=0;i<maxn;i++)
		{
			road[i].clear();
			f[i].clear();
		}
		for(int i=0;i<m;i++)
		{
			cin>>a>>b>>c>>p>>r;
		//	a--;b--;c--;
			road[a].PB(MP(b,c));
			f[a].PB(MP(p,r));
		}
		ans=INF;
		dfs(1,0);
		if(ans==INF)cout<<"impossible"<<endl;
		else cout<<ans<<endl;
	}
		
	return 0;
}


