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
double x[2][10];
int main()
{
	ios::sync_with_stdio(false);
	double a,b,c,d,l,r;
	while(cin>>a>>b>>c>>d>>x[0][0]>>x[1][0])
	{
		l=x[0][0],r=x[1][0];
		for(int i=1;i<3;i++)
		{
			x[1][i]=x[1][i-1]*x[1][0];
			x[0][i]=x[0][i-1]*x[0][0];
		}
		double delta=4.0*b*b-12.0*a*c;
		double ans=0;
		if((fabs(a)<1e-8&&fabs(b)<1e-8))
			ans=max(fabs(a*x[0][2]+b*x[0][1]+c*x[0][0]+d),fabs(a*x[1][2]+b*x[1][1]+c*x[1][0]+d));
		else if(fabs(a)<1e-8)
		{
			double x1=-c/(2.0*b);
			ans=max(fabs(a*x[0][2]+b*x[0][1]+c*x[0][0]+d),fabs(a*x[1][2]+b*x[1][1]+c*x[1][0]+d));
			if(x1>=l&&x1<=r)
			{
				x[0][0]=x1;
				for(int i=1;i<3;i++)
					x[0][i]=x[0][i-1]*x[0][0];
				ans=max(fabs(a*x[0][2]+b*x[0][1]+c*x[0][0]+d),ans);
			}
		}
		else if(delta<1e-10)
			ans=max(fabs(a*x[0][2]+b*x[0][1]+c*x[0][0]+d),fabs(a*x[1][2]+b*x[1][1]+c*x[1][0]+d));
		else 
		{
			delta=sqrt(delta);
			double x1=(-2.0*b+delta)/(6.0*a);
			double x2=(-2.0*b-delta)/(6.0*a);
			ans=max(fabs(a*x[0][2]+b*x[0][1]+c*x[0][0]+d),fabs(a*x[1][2]+b*x[1][1]+c*x[1][0]+d));
			if(x1-l>1e-10&&r-x1>1e-10)
			{
				x[0][0]=x1;
				for(int i=1;i<3;i++)
					x[0][i]=x[0][i-1]*x[0][0];
				ans=max(fabs(a*x[0][2]+b*x[0][1]+c*x[0][0]+d),ans);
			}
			if(x2-l>1e-10&&r-x2>1e-10)
			{
				x[0][0]=x2;
				for(int i=1;i<3;i++)
					x[0][i]=x[0][i-1]*x[0][0];
				ans=max(fabs(a*x[0][2]+b*x[0][1]+c*x[0][0]+d),ans);
			}
		}
		cout<<fixed<<setprecision(2)<<ans<<endl;
	}
	return 0;
}



