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
int num;
const int maxn=50010;
struct node
{
	int d,c,next;
}edge[maxn*3];
int head[maxn];
int p;
bool v[maxn];
int dis[maxn];
int maxx,minn;
void add(int a,int b,int c)
{
	edge[p].d=b;
	edge[p].c=c;
	edge[p].next=head[a];
	head[a]=p++;
}
void spfa()
{
	queue<int>q;
	v[minn]=1;
	q.push(minn);
	dis[minn]=0;
	int k;
	while(!q.empty())
	{
		k=q.front();
		q.pop();
		v[k]=0;
		for(int i=head[k];i!=-1;i=edge[i].next)
		{
			if(dis[edge[i].d]<dis[k]+edge[i].c)
			{
				dis[edge[i].d]=dis[k]+edge[i].c;
				if(!v[edge[i].d])
				{
					v[edge[i].d]=1;
					q.push(edge[i].d);
				}
			}
		}
	}
}
int main()
{
//	ios::sync_with_stdio(false);
	while(scanf("%d",&num)!=EOF)
	{
		CLR(head,-1);
		CLR(v,0);
		maxx=p=0;
		minn=INF;
		for(int i=0,a,b,c;i<num;i++)
		{
			scanf("%d%d%d",&a,&b,&c);
			b++;
			maxx=max(maxx,b);
			minn=min(minn,a);
			add(a,b,c);
		}
		for(int i=minn;i<maxx;i++)
		{
			add(i,i+1,0);
			add(i+1,i,-1);
		}
		for(int i=minn;i<=maxx;i++)dis[i]=-INF;
		spfa();
		printf("%d\n",dis[maxx]-dis[minn]);
	}
		
	return 0;
}


