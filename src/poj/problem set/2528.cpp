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
int b[10010],a[10010];
int tem[20010],id1[20010];
int id[10010*3][2];
//bool vis[60010];
const int maxn=10010;
int segtree[maxn*6*3];
int temp[maxn*6*3];
bool hash[maxn*6];
int ans=0;
#define lson l,m,rt<<1
#define rson m+1,r,rt<<1|1
//struct Seg
//{
//	int l,r,c;
//}seg[maxn*6];

void pushdown(int rt)
{
	if(segtree[rt]!=-1)
	{
		segtree[rt<<1]=segtree[rt<<1|1]=segtree[rt];
		segtree[rt]=-1;
	}
}
void update(int beg,int end,int va,int l,int r,int rt)
{
	if(beg<=l&&r<=end)
	{
		segtree[rt]=va;
		return ;
	}
	pushdown(rt);
	int m=(l+r)>>1;
	if(beg<=m)
		update(beg,end,va,lson);
	if(end>m)
		update(beg,end,va,rson);
}

void query(int l,int r,int rt)
{
	if(segtree[rt]!=-1)
	{
		if(!hash[segtree[rt]])ans++;
		hash[segtree[rt]]=1;
		return ;
	}
	if(l==r)return ;
	int m=(l+r)>>1;
	query(lson);
	query(rson);
}

bool cmp(int a,int b)
{
	return tem[a]<tem[b];
}
int main()
{
	ios::sync_with_stdio(false);
	int t,n;
	scanf("%d",&t);
	while(t--)
	{
		//s.clear();
		//CLR(vis,0);
		scanf("%d",&n);
		CLR(segtree,-1);
		CLR(hash,0);
		int j=0;
		for(int i=0;i<n;i++)
		{
			 scanf("%d %d",&a[i],&b[i]);
			 id1[j]=j;
			 tem[j]=a[i];
			 j++;
			 id1[j]=j;
			 tem[j]=b[i];
			 j++;
		}
		sort(id1,id1+j,cmp);
		int index=0;
		int k=0;
		id[id1[0]/2][k]=0;
		for(int i=1;i<j;i++)
		{
			k=id1[i]%2;
			if(tem[id1[i]]==tem[id1[i-1]])
			{
				id[id1[i]/2][k]=index;
			//	cout<<index<<endl;
				;
			}
			else if(tem[id1[i]]==tem[id1[i-1]]+1)
			{
				index++;
				//cout<<index<<endl;
				id[id1[i]/2][k]=index;
				//index++;
			}
			else if(tem[id1[i]]>tem[id1[i-1]]+1)
			{
				index+=2;
				//cout<<index+1<<endl;
				id[id1[i]/2][k]=index;
			//	index+=2;
			}
		}
		//for(int i=0;i<n;i++)
		//{
		//	cout<<id[i][0]<<"  "<<id[i][1]<<endl;
		//}
		//cout<<"ok"<<endl;
		for(int i=0;i<n;i++)
		{
		//	cout<<a[i]<<"  "<<b[i]<<endl;
			update(id[i][0],id[i][1],i+1,0,index,1);
		}
		//cout<<"ok"<<endl;
		ans=0;
		query(0,index,1);
		printf("%d\n",ans);
	}
		
		
			 
	return 0;
}


