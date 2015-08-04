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
using namespace std;
#define XINF INT_MAX
#define INF 0x3FFFFFFF
#define MP(X,Y) make_pair(X,Y)
#define PB(X) push_back(X)
#define REP(X,N) for(int X=0;X<N;X++)
typedef pair<int,int> PII;
typedef vector<int> VI;
typedef long long ll;
int V;
vector<int> G[100010];
vector<int> rG[100010];
vector<int> vs;
int aa[100010];
int minn[100010];
bool used[100010];
int cmp[100010];
int sss[100010];
void add_edge(int from,int to)
{
	G[from].push_back(to);
	rG[to].push_back(from);
}

void dfs(int v)
{
	used[v]=true;
	for(int i=0;i<G[v].size();i++)
	{
		if(!used[G[v][i]])dfs(G[v][i]);
	}
	vs.push_back(v);
}

void rdfs(int v,int k)
{
	used[v]=true;
	cmp[v]=k;
	for(int i=0;i<rG[v].size();i++)
	{
		if(!used[rG[v][i]])rdfs(rG[v][i],k);
	}
}

int scc()
{
	memset(used,0,sizeof(used));
	vs.clear();
	for(int v=0;v<V;v++)
	{
		if(!used[v])dfs(v);
	}
	memset(used,0,sizeof(used));
	int k=0;
	for(int i=vs.size()-1;i>=0;i--)
	{
		if(!used[vs[i]])rdfs(vs[i],k++);
	}
	return k;
}



int main()
{
	ios::sync_with_stdio(false);
	int m;
	long long sum;
	while(cin>>V)
	{
		
		for(int i=0;i<=V;i++)
		{
			
			G[i].clear();
			rG[i].clear();
		}
		for(int i=0;i<V;i++)
		{
			cmp[i]=0;
			sss[i]=0;
			minn[i]=1000000000;
			cin>>aa[i];
		}
		cin>>m;
		int x,y;
		for(int i=0;i<m;i++)
		{
			cin>>x>>y;
			add_edge(x-1,y-1);
		}
		int num1=scc();
	//	for(int i=0;i<V;i++)
	//	{
	//		cout<<cmp[i]<<" ";
	//	}
	//	cout<<endl;
		for(int i=0;i<V;i++)
		{
			minn[cmp[i]]=min(minn[cmp[i]],aa[i]);
		}
		for(int i=0;i<V;i++)
		{
			if(minn[cmp[i]]==aa[i])
			{
				sss[cmp[i]]++;
			}
		}
		sum=0;
		for(int i=0;i<num1;i++)
		{
			sum+=minn[i];
		}
		long long wa=1;
		for(int i=0;i<num1;i++)
		{
			wa=(wa*sss[i])%1000000007;
		}
		cout<<sum<<" "<<wa<<endl;
	}
	return 0;
}

