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
struct point
{
	double x,y;
}p[5];
struct Line
{
	point a,b;
}l[4];
double len[4];


int main()
{
	ios::sync_with_stdio(false);
	int T,cas=1;
	cin>>T;
	while(T--)
	{
		cout<<"Case "<<cas++<<":"<<endl; 
		for(int i=0;i<4;i++)
		{
			cin>>p[i].x>>p[i].y;
		}
		p[4].x=p[0].x;p[4].y=p[0].y;
		for(int i=0;i<4;i++)
		{
			l[i].a.x=p[i].x;
			l[i].a.y=p[i].y;
			l[i].b.x=p[i+1].x;
			l[i].b.y=p[i+1].y;
		}
		double s=0;
		for(int i=0;i<4;i++)
		{
			len[i]=sqrt(1.0*((l[i].a.x-l[i].b.x)*(l[i].a.x-l[i].b.x)+(l[i].a.y-l[i].b.y)*(l[i].a.y-l[i].b.y)));
			s+=len[i];
		}
		s/=2.0;
		double sum=1.0;
		for(int i=0;i<4;i++)
		{
			sum*=(s-len[i]);
		}
		sum=sqrt(sum);
		double x,y,sum2=0,sum3,a,b,c;
		cin>>x>>y;
		bool flag=1;
		for(int i=0;i<4;i++)
		{
			a=sqrt(1.0*(x-p[i].x)*(x-p[i].x)+(y-p[i].y)*(y-p[i].y));
			b=sqrt(1.0*(x-p[i+1].x)*(x-p[i+1].x)+(y-p[i+1].y)*(y-p[i+1].y));
			c=len[i];
			s=(a+b+c)/2.0;
			sum3=sqrt(s*(s-a)*(s-b)*(s-c));
			if(sum3<=10e-8&&sum3>=-(10e-8))flag=0;
		//	cout<<sum3<<endl;
			sum2+=sum3;
		}
	/*	for(int i=0;i<4;i++)
		{
			cout<<len[i]<<endl;
		}
		cout<<sum<<"  "<<sum2<<endl;
		cout<<flag<<endl;*/
		if(flag&&fabs(sum2-sum)<=10e-1)cout<<"In"<<endl;
		else cout<<"No"<<endl;
	}
	return 0;
}


