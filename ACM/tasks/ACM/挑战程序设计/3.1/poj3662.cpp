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
//#include <map>
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
#define MAXN 1010

struct Edge{
    int v,w;
    Edge(int vv,int ww):v(vv),w(ww){}
};

int dist[MAXN];
bool mark[MAXN];
int edge[MAXN*22];
int n,m,k,tag,NE;

vector<vector<Edge> >map,Graph;
int SPFA(vector<vector<Edge> >map,int limit)
{
    memset(mark,false,sizeof(mark));
    for(int i=1;i<=n;i++)dist[i]=INF;
    dist[1]=0;
    queue<int>Q;
    Q.push(1);
    while(!Q.empty()){
        int u=Q.front();
        Q.pop();
        mark[u]=false;
        for(int i=0;i<map[u].size();i++){
            int v=map[u][i].v,w=map[u][i].w;
            if(tag){
                w=(w<=limit)?0:1;
            }
            if(dist[u]+w<dist[v]){
                dist[v]=dist[u]+w;
                if(!mark[v]){ mark[v]=true;Q.push(v); }
            }
        }
    }
    return dist[n];
}

void Solve()
{
      
}

int main()
{
    int u,v,w,ans;
    while(~scanf("%d%d%d",&n,&m,&k))
	{
    	map.clear();Graph.clear();
        map.resize(n+2);Graph.resize(n+2);
        NE=0;
        while(m--)
		{
        	scanf("%d%d%d",&u,&v,&w);
        	edge[NE++]=w;
            map[u].push_back(Edge(v,w));
            map[v].push_back(Edge(u,w));
            Graph[u].push_back(Edge(v,1));
            Graph[v].push_back(Edge(u,1));
        }
        tag=0;
        ans=SPFA(Graph,0);
        if(ans>=INF)
		{
            printf("-1\n");
        }
		else if(ans<=k)
		{
            printf("0\n");
        }
		else 
		{
        	tag=1;
            sort(edge,edge+NE);
            int low=0,high=NE-1,mid,u,v,num;
   			while(low<=high)
			{
        		mid=(low+high)>>1;
        		if(SPFA(map,edge[mid])<=k)
				{
        		    high=mid-1;
        		}
				else
            		low=mid+1;
    		}
    		printf("%d\n",edge[low]); 
        }
    }    
    return 0;
}
