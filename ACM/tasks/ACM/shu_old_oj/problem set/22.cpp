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
double add(double a,double b)
{return a+b;}
double sub(double a,double b)
{return a-b;}
double mul(double a,double b)
{return a*b;}
double div(double a,double b)
{ if(b==0) return -10000;
return a/b;}



int main()
{
	double (*op[4])(double,double) ={add,sub,mul,div};
	double a,b,c,d;
	int t=0;
	double sum;
	while(cin>>a>>b>>c>>d)
	{
		bool sign=0;
		for(int i=0;i<4;++i)
			for(int j=0;j<4;++j)
				for(int k=0;k<4;++k)
				{
					sum=op[k](op[j](op[i](a,b),c),d);
					if(abs(sum-24)<1e-9){sign=1;i=4;j=4;break;}
					
					sum=op[k](op[i](a,op[j](b,c)),d);
					if(abs(sum-24)<1e-9){sign=1;i=4;j=4;break;}
					
					sum=op[j](op[i](a,b),op[k](c,d));
					if(abs(sum-24)<1e-9){sign=1;i=4;j=4;break;}
					
					sum=op[i](a,op[k](op[j](b,c),d));
					if(abs(sum-24)<1e-9){sign=1;i=4;j=4;break;}
					
					sum=op[i](a,op[j](b,op[k](c,d)));
					if(abs(sum-24)<1e-9){sign=1;i=4;j=4;break;}
				}
		
		cout<<"Case "<<++t<<": ";
		if(sign)cout<<"Possible"<<endl;
		else cout<<"Impossible!"<<endl;
	}
	
	
	return 0;
}
