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
const int MAXSIZE = 1000;
typedef struct Node NODE;

struct Node
{
	int color;
	vector<int> neigh_list;
};

bool checkAllNodesVisited(NODE *graph, int numNodes, int &index)
{
	for (int i=0; i<numNodes; i++)
	{
		if (graph[i].color == -1)
		{
			index = i;
			return false;
		}
	}
	return true;
}

bool JudgeBiGraph(NODE *graph, int numNodes)
{
	int start = 0;
	do 
	{
		queue<int> Myqueue;
		Myqueue.push(start);
		graph[start].color = 0;

		while(!Myqueue.empty())
		{
			int gid = Myqueue.front();
			for(int i=0; i<graph[gid].neigh_list.size(); i++)
			{
				int neighid = graph[gid].neigh_list[i];
				if(graph[neighid].color == -1)
				{
					graph[neighid].color = (graph[gid].color+1)%2;
					Myqueue.push(neighid);
				}
				else
				{
					if(graph[neighid].color == graph[gid].color) 
					return false;
				}
			}
			Myqueue.pop();
		}
	}while (!checkAllNodesVisited(graph, numNodes, start));

	return true;
}

int main()
{
	int T;
	int M;
	int caseid = 0;
	scanf("%d",&T);
	
	while(T--)
	{
		scanf("%d",&M);
		map<string,int> Mymap;
		NODE graph[MAXSIZE];

		int id = 0;
		for(int i=0;i<M;i++)
		{
			char s1[MAXSIZE],s2[MAXSIZE];
			scanf("%s %s",s1,s2);
			string str_s1(s1),str_s2(s2);
			NODE node1,node2;
			int id1,id2;
			if(Mymap.count(str_s1)==0)
			{
				Mymap[str_s1] = id;
				id1 = id;
				id++;
			}
			else
				id1 = Mymap[str_s1];
			if(Mymap.count(str_s2)==0)
			{
				Mymap[str_s2] = id;
				id2 = id;
				id++;
			}
			else
				id2 = Mymap[str_s2];
			graph[id1].neigh_list.push_back(id2);
			graph[id2].neigh_list.push_back(id1);
		}

		for(int i=0;i<id;i++)
		{
			graph[i].color = -1;
		}
		if(JudgeBiGraph(graph,id))
			printf("Case #%d: Yes\n",caseid+1);
		else
			printf("Case #%d: No\n",caseid+1);
		caseid++;
	}
	return 0;
}
