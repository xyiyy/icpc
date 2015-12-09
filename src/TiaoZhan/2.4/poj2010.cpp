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
ll a[100010],b[100010];
int id[100010];
ll fro[100010],bac[100010];
#define ok cout<<"ok"<<endl
bool cmp(int x,int y)
{
	return a[x]<a[y];
}
bool scan_d(int &ret)
{
	char c;
	c=getchar();
	while(c!='-'&&(c<'0'||c>'9'))c=getchar();
	ret=c-'0';
	while(c=getchar(),c>='0'&&c<='9')ret=ret*10+(c-'0');
	return 1;
}
int main()
{
	int n,c;
	ll f;
	while(scanf("%d%d%lld",&n,&c,&f)!=EOF)
	{
		for(int i=1;i<=c;i++)
		{
			scanf("%lld%lld",&a[i],&b[i]);
			//scan_d(a[i]);
			//scan_d(b[i]);
			id[i]=i;
		}
		sort(id+1,id+c+1,cmp);
		if(c==1&&n==1)
		{
			if(b[id[1]]<=f)
			{
				printf("%d\n",a[id[1]]);
			}
			else printf("-1\n");
			continue;
		}
		else if(n==1)
		{
			int i;
			for(i=c;i>0;i--)
			{
				if(b[id[i]]<=f)break;
			}
			if(i<=0)printf("-1\n");
			else 
			{
				printf("%d\n",a[id[i]]);
			}
			continue;
		}
		int half=n/2;
		priority_queue<ll>q;
		ll sum=0;
		for(int i=1;i<=half;i++)
		{
			sum+=b[id[i]];
			q.push(b[id[i]]);
		}
		fro[half+1]=sum;
		for(int i=half+1;i<=c-half;i++)
		{
			if(q.top()>b[id[i]])
			{	
				fro[i+1]=fro[i]+b[id[i]]-q.top();
				q.pop();
				q.push(b[id[i]]);
			}
			else 
			{
				fro[i+1]=fro[i];
			}
		}
		priority_queue<ll>q1;
		sum=0;
		for(int i=c;i>c-half;i--)
		{
			sum+=b[id[i]];
			q1.push(b[id[i]]);
		}
		bac[c-half]=sum;
		for(int i=c-half;i>=half;i--)
		{
			if(q1.top()>b[id[i]])
			{	
				bac[i-1]=bac[i]+b[id[i]]-q1.top();
				q1.pop();
				q1.push(b[id[i]]);
			}
			else 
			{
				bac[i-1]=bac[i];
			}
		}
		int maxx=0;
		for(int i=c-half;i>half;i--)
		{
			if(bac[i]+fro[i]+b[id[i]]<=f)
			{
				maxx=a[id[i]];
				break;
			}
		}
		if(!maxx)printf("-1\n");
		else printf("%d\n",maxx);
	}
				
	return 0;
}


