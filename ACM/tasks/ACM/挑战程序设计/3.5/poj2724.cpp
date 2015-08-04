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
int V;
const int MAX_V=2010;
vector<int> G[MAX_V];
int match[MAX_V];
bool used[MAX_V];

void add_edge(int u,int v)
{
	G[u].PB(v);
	G[v].PB(u);
}

bool dfs(int v)//Ôö¹ãÂ· 
{
	used[v]=1;
	for(int i=0;i<G[v].size();i++)
	{
		int u=G[v][i],w=match[u];
		if(w<0||!used[w]&&dfs(w))
		{
			match[u]=v;
			match[v]=u;
			return 1;
		}	
	}
	return false ;
}

int hungary()
{
	int res=0;
	CLR(match,-1);
	for(int v=0;v<V;v++)
	{
		if(match[v]<0)
		{
			CLR(used,0);
			if(dfs(v))
			{
				res++;
			}
		}
	}
	return res;
}
int num[10010];
int main()
{
	ios::sync_with_stdio(false);
	int n,m;
	while(cin>>n>>m&&(n||m))
	{
	//	set<int> s1,s2;
		CLR(num,0);
		string s;
		int id=0;
		for(int i=0;i<m;i++)
		{
			cin>>s;
			int len=s.length();
			len--;
		//	stack<int>tmp;
		//	int temp=1; 
			int k=-1;
			for(int j=0;j<len;j++)
			{
				if(s[j]=='*')k=j;
				else num[id]|=(s[j]-'0')<<j;
			}
			id++;
			if(k!=-1)
			{
				num[id]=num[id-1]|(1<<k);
				id++;
			}
		}
		sort(num,num+id);
		id=unique(num,num+id)-num;
		V=1<<n;
		for(int i=0;i<1030;i++)G[i].clear();
		for(int i=0;i<id;i++)
		{
			for(int j=i+1;j<id;j++)
			{
				int temp=num[i]^num[j];
				if(temp&&((temp&(temp-1))==0))
				{
					add_edge(i,j);
				}
			}
		}
		cout<<id-hungary()<<endl;
	}
				
	return 0;
}



