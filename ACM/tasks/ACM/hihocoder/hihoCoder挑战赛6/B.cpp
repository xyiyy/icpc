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
double calc(double xx,double k,double b)
{
	return (k+0.5*k*k)/3*xx*xx*xx+(b+k*b+20000)/2*xx*xx+(b*b/2.0-2e8)*xx;
}
double cal(double x1,double y1,double x2,double y2)
{
	double k=(y1-y2)/(x1-x2);
	double b=(x1*y2-x2*y1)/(x1-x2);
	return calc(x1,k,b)-calc(x2,k,b);
}
const int maxn=8010;
int x[maxn],y[maxn];
int t1[maxn],t2[maxn];
int num[maxn];
bool cmp(int idx,int idy)
{
	return (t1[idx]<t2[idy])||(t1[idx]==t1[idy]&&t2[idx]<t2[idy]);
}
int id=0;
int check(int a,int b,int c)
{
	return (x[b]-x[a])*(t2[c]-y[a])-(t1[c]-x[a])*(y[b]-y[a]);
}
int main()
{
	ios::sync_with_stdio(false);
	int t;
	cin>>t;
	while(t--)
	{
		int n;
		id =0;
		cin>>n;
		for(int i=0;i<n;i++)
		{
			cin>>t1[i]>>t2[i];
			num[i]=i;
		}
		sort(num,num+n,cmp);
		for(int i=0;i<n;i++)
		{
			while(id>=2&&check(id-2,id-1,i)>=0)
			{
				id--;
			}
			x[id]=t1[i];
			y[id++]=t2[i];
		}
		for(int i=n-2,m=id+1;i>=0;i--)
		{
			while(id>=m&&check(id-2,id-1,i)>=0)
			{
				id--;
			}
			x[id]=t1[i];
			y[id++]=t2[i];
		}
		x[id]=x[0],y[id]=y[0];
		double sum=0;
		for(int i=0;i<id;i++)
		{
			if(fabs(x[i]-x[i+1])<=1e-8)continue;
			else 
			{
				sum+=cal(x[i],y[i],x[i+1],y[i+1]);
			}
		}
		cout<<fixed<<setprecision(2)<<-sum<<endl;
	}
	return 0;
}



