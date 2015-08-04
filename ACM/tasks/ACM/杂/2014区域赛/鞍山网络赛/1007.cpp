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
const double pai=3.1415926535898;
struct point
{
	double x,y;
};
point init[11];
point last[11];
double p[11];
void cal(int i,int j)
{
	double tempx,tempy;
	double x=last[j].x,y=last[j].y,x0=init[i].x,y0=init[i].y;
	/*double l=sqrt((x-x0)*(x-x0)+(y-y0)*(y-y0));
	double ang=atan2(y-y0,x-x0);
	ang+=p[i];
	last[j].x=l*cos(ang)+x0;
	last[j].y=l*sin(ang)+y0;
	cout<<last[j].x<<" "<<last[j].y<<endl;*/
	tempx=(x-x0)*cos(p[i])-(y-y0)*sin(p[i])+x0;
	tempy=(x-x0)*sin(p[i])+(y-y0)*cos(p[i])+y0;
	last[j].x=tempx;
	last[j].y=tempy;
	//cout<<last[j].x<<" "<<last[j].y<<endl;
	return ;
}
double ansx,ansy,ansp;
bool flagx,flagy,flagp;
	
int main()
{
	ios::sync_with_stdio(false);
	int t;
	cin>>t;
	while(t--)
	{
		int n;
		cin>>n;
		for(int i=0;i<n;i++)
		{
			cin>>init[i].x>>init[i].y;
			cin>>p[i];
		}
		last[0].x=0;
		last[0].y=-1;
		last[1].x=1;
		last[1].y=1;
		last[2].x=-1;
		last[2].y=1;
		double a=last[0].x;
		double b=last[0].y;
		double c=last[1].x;
		double d=last[1].y;
		double e=last[2].x;
		double f=last[2].y;
		ansx=0,ansy=0,ansp=0;
		for(int i=0;i<n;i++)
		{
			for(int j=0;j<3;j++)
			{
				cal(i,j);
			}
		}
		flagx=flagy=flagp=0;
		init[0].x=a;
		init[0].y=b;
		init[1].x=c;
		init[1].y=d;
		init[2].x=e;
		init[2].y=f;
		a=init[0].x;b=init[0].y;
		c=last[0].x;d=last[0].y;
	//	cout<<a<<" "<<b<<" "<<c<<" "<<d<<endl;
		flagx=flagy=flagp=0;
		double k,m;
		if(fabs(a-c)<=1e-10)
		{
			flagy=1;
			ansy=(b+d)/2.0;
			k=0;m=ansy;
		}
		if(fabs(b-d)<=1e-10)
		{
			flagx=1;
			ansx=(a+c)/2.0;
		}
		if(fabs(a-c)<=1e-10&&fabs(b-d)<=1e-10)
		{
			flagp=0;
			ansp=0;
		}	
	//	cout<<flagx<<" "<<flagy<<endl;
		for(int i=1;i<3;i++)
		{
			double a1,b1,c1,d1;
			a1=init[i].x;b1=init[i].y;
			c1=last[i].x;d1=last[i].y;
			double k1,m1;
			bool flagx1=0,flagy1=0;
			if(fabs(a1-c1)<=1e-10)
			{
				flagy=1;
				flagy1=1;
				ansy=(b1+d1)/2.0;
				k=0;m=ansy;
			}
			if(fabs(b1-d1)<=1e-10)
			{
				flagx=1;
				flagx1=1;
				ansx=(a1+c1)/2.0;
			}
			if(flagx&&flagy)break;
			if(flagy1)
			{
				if(fabs(a-c)<=1e-10)continue;
				k=-(a-c)/(b-d);
				m=(b+d)/2.0+(a+c)*(a-c)/(2*b-2*d);
				ansx=(ansy-m)/k;
				flagx=1;
				break;
			}
			if(flagx1)
			{
				if(fabs(b-d)<=1e-10)continue;
				k=-(a-c)/(b-d);
				m=(b+d)/2.0+(a+c)*(a-c)/(2*b-2*d);
				ansy=k*ansx+m;
				flagy=1;
				break;
			}
			if(flagx)
			{
				k1=-(a1-c1)/(b1-d1);
				m1=(b1+d1)/2.0+(a1+c1)*(a1-c1)/(2*b1-2*d1);
				ansy=k1*ansx+m1;
				flagy=1;
				break;
			}
			if(flagy)
			{
				k1=-(a1-c1)/(b1-d1);
				m1=(b1+d1)/2.0+(a1+c1)*(a1-c1)/(2*b1-2*d1);
				ansx=(ansy-m1)/k1;
				flagx=1;
				break;
			}
			k=-(a-c)/(b-d);
			k1=-(a1-c1)/(b1-d1);
			if(fabs(k1-k)<=1e-10)continue;
			m=(b+d)/2.0+(a+c)*(a-c)/(2.0*b-2.0*d);
			m1=(b1+d1)/2.0+(a1+c1)*(a1-c1)/(2.0*b1-2.0*d1);
			//cout<<k<<" "<<m<<" "<<k1<<" "<<m1<<endl;
			ansx=(m1-m)/(k-k1);
			ansy=k1*(ansx)+m1;
			//ansy=(k*m1)-(k1*m);
			flagx=flagy=1;
		//	cout<<ansx<<" "<<ansy<<endl;
		//	cout<<flagx<<" "<<flagy<<endl;
			break;
		}
		if(flagx&&flagy&&!flagp)
		{
			double temp1=atan2(b-ansy,a-ansx);
			double temp2=atan2(d-ansy,c-ansx);
			if(temp1-temp2>1e-12)temp2+=2*pai;
			ansp=temp2-temp1;
		}
		cout<<fixed<<setprecision(10)<<ansx<<" "<<ansy<<" "<<ansp<<endl;
	}
	return 0;
}



