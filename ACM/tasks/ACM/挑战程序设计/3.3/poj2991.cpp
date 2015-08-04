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
const int st_size=(1<<15)-1;
const double PI=3.1415926535898;
int n,c;
const int max_n=10010;
int len[max_n];

double vx[st_size],vy[st_size];
double ang[st_size];

double prv[max_n];
void init(int l,int r,int cur)
{
	ang[cur]=vx[cur]=0.0;
	if(r==l)
	{
		vy[cur]=len[l];
		return ;
	}
	int mid=(l+r)/2;
	init(l,mid,cur<<1);
	init(mid+1,r,cur<<1|1);
	vy[cur]=vy[cur<<1]+vy[cur<<1|1];
}

void change(int s,double a,int l,int r,int cur)
{
	if(s<=l)return ;
	else if(s<=r)
	{
		int mid=(l+r)/2;
		change(s,a,l,mid,cur<<1);
		change(s,a,mid+1,r,cur<<1|1);
		if(s<=mid+1)ang[cur]+=a;
		double x=sin(ang[cur]),y=cos(ang[cur]);
		vx[cur]=vx[cur<<1]+(y*vx[cur<<1|1]-x*vy[cur<<1|1]);
		vy[cur]=vy[cur<<1]+(x*vx[cur<<1|1]+y*vy[cur<<1|1]);
	}
}
	

void solve()
{
	for(int i=0;i<n;i++)
	{
		scanf("%d",len+i);
	}
	init(0,n-1,1);
	for(int i=1;i<n;i++)
	{
		prv[i]=PI;
	}
	int s;
	double a;
	for(int i=0;i<c;i++)
	{
		scanf("%d",&s);
		scanf("%lf",&a);
		a=a/360.0*2*PI;
		change(s,a-prv[s],0,n-1,1);
		prv[s]=a;
		printf("%.2f %.2f\n",vx[1],vy[1]);
	}
}

int main()
{
	//ios::sync_with_stdio(false);
	while(scanf("%d%d",&n,&c)!=EOF)solve();
	return 0;
}


