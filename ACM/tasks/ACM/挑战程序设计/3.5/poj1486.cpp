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
const int MAX_V=70;
//vector<int> G[MAX_V];
int match[MAX_V];
bool used[MAX_V];
int net[MAX_V][MAX_V];
struct matrix{
	int lx1,ly1,lx2,ly2;
	/*matrix(int _lx1,int _ly1,int _lx2,int _ly2)
	{
		lx1=_lx1;
		ly1=_ly1;
		lx2=_lx2;
		ly2=_ly2;
	}*/
};
matrix mat[MAX_V];
int match2[MAX_V];
struct nnode{
	int x,y;
/*	nnode(int _x,int _y){
		x=_x;y=_y;
	}*/
}point[MAX_V];
		
void add_edge(int u,int v)
{
	net[u][v]=net[v][u]=1;
	//G[u].PB(v);
	//G[v].PB(u);
}

bool dfs(int v)//Ôö¹ãÂ· 
{
	used[v]=1;
	for(int i=0;i<V;i++)
	{
		if(!net[v][i])continue;
		int u=i,w=match[u];
		if(w<0||!used[w]&&dfs(w))
		{
			match[u]=v;
			match[v]=u;
			return 1;
		}	
	}
	return false ;
}
void del_edge(int u,int v)
{
	net[u][v]=net[v][u]=0;
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
bool in(int i,int j)
{
	if(point[j].x>mat[i].lx1&&point[j].x<mat[i].lx2&&point[j].y>mat[i].ly1&&point[j].y<mat[i].ly2)
	{
		return 1;
	}
	return 0;
}
int main()
{
	ios::sync_with_stdio(false);
	int n;
	int cas=1;
	while(scanf("%d",&n)!=EOF&&n)
	{
		CLR(net,0);
		V=2*n;
		int xmin,ymin,xmax,ymax;
		for(int i=0;i<n;i++)
		{
			scanf("%d%d%d%d",&xmin,&xmax,&ymin,&ymax);
			mat[i].lx1=xmin;
			mat[i].lx2=xmax;
			mat[i].ly1=ymin;
			mat[i].ly2=ymax;
		}
		for(int  i=0;i<n;i++)
		{
			scanf("%d%d",&xmin,&ymin);
			point[i].x=xmin;
			point[i].y=ymin;
		}
		for(int i=0;i<n;i++)
		{
			for(int j=0;j<n;j++)
			{
				if(in(i,j))
				{
		//			printf("%d  %d\n",i,j);
					add_edge(i,j+n);
				}
			}
		}
		/*for(int i=0;i<V;i++)
		{
			for(int j=0;j<V;j++)
			{
				printf("%d ",net[i][j]);
			}
			printf("\n");
		}*/
		int res=hungary();
	//	printf("%d\n",res);
		printf("Heap %d\n",cas++);
		if(res!=n)
		{
			printf("none");
		}
		else 
		{
			bool flag=0;
			for(int i=0;i<V;i++)
			{
				match2[i]=match[i];
			}
			for(int i=0;i<n;i++)
			{
				del_edge(i,match2[i]);
				int ret=hungary();
				//printf("%d\n",ret);
				if(ret==res)
				{
					continue;
			//		flag=1;
			//		break;
				}
				else 
				{
					if(flag)printf(" ");
					printf("(%c,%d)",'A'+i,match2[i]-n+1);
					flag=1;
				}	
				add_edge(i,match2[i]);
			}
			if(!flag)
			{
				printf("none");
			}
		//	else 
		//	{
		//		for(int i=0;i<n;i++)
		//		{
		//			if(i)printf(" ");
		//			printf("(%c,%d)",'A'+i,match2[i]-n+1);
		//		}
		//		printf("\n");
		//	}
		}
		printf("\n\n");
	}

	return 0;
}



