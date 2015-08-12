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
const int maxn= 100010;
int v[maxn],w[maxn],id[maxn];
struct node
{
	double key;
	int id;
	bool operator<(const node &b)const
	{
		return key>=b.key;
	}
}a[maxn];

int main()
{
	//ios::sync_with_stdio(false);
	int n,m;
	while(scanf("%d%d",&n,&m)!=EOF)
	{
		for(int i=0;i<n;i++)
		{
			scanf("%d%d",&v[i],&w[i]);
		}
		double l=0,r=1e11;
		double tot;
		for(int i=0;i<50;i++)
		{
			double mid=(l+r)/2.0;
			for(int i=0;i<n;i++)
			{
				a[i].key=v[i]-w[i]*mid;
				a[i].id=i;
			}
			sort(a,a+n);
			tot=0;
			for(int i=0;i<m;i++)
			{
				tot+=a[i].key;
			}
			if(tot-0.0>0)
			{
				l=mid;
			}
			else
			{
				r=mid;
			}
		}
		for(int i=0;i<m;i++)
		{
			id[i]=a[i].id+1;
		}
		sort(id,id+m);
		for(int i=0;i<m;i++)
		{
			if(i)printf(" ");
			printf("%d",id[i]);
		}
		printf("\n");
	}
			
		
	return 0;
}


