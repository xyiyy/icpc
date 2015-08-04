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
//int G[1010][1010];
//int deg[1000010];
bool  vis[1000010];
bool vis2[1000010];
int flag;
//queue<int > q[100010];
/*
void dfs(int x)
{
	while(!flag&&q[x].size())
	{
		if(!vis2[q[x].front()])vis2[q[x].front()]=1;
		else
		{
			flag=1;
			return ;
		}
		dfs(q[x].front());
		q[x].pop();
	}
	return ;
}*/
	
int main()
{
	ios::sync_with_stdio(false);
	int u,v;
	int cas=1,index;
	while(cin>>u>>v)
	{
		if(u==0&&v==0)
		{
			
		//	flag=0;
			index=-1;
			for(int i=0;i<1000010;i++)
			{
				if(vis2[i]&&!vis[i]&&index!=-1)
				{
					flag=1;
					break;
				}
				if(vis2[i]&&!vis[i])
				{
					index=i;
				}
			}
		//	CLR(vis,0);
			//vis2[index]=1;
		//	cout<<index<<endl;
		//	dfs(index);
			cout<<"Case "<<cas++<<" is ";
			if(flag)cout<<"not ";
			cout<<"a tree."<<endl;
			CLR(vis,0);
			//CLR(G,0);
			//CLR(deg,0);	
			flag=0;
			CLR(vis2,0);
		////	for(int i=0;i<100010;i++)
		//	{
		//		while(q[i].size())q[i].pop();
		//	}
		}
		else if(u>0&&v>0)
		{
			vis2[u]=1;
			if(vis[v])flag=1;
			vis[v]=1;
		//	deg[v]++;
		///	q[u].push(v);
		}
		else 
		{
			break;
		}
	}
	return 0;
}


