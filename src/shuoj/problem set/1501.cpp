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
double m,l,s,k;
int main()
{
	ios::sync_with_stdio(false);
	double g=9.81;
	double v;
	double a;
	while(cin>>m>>l>>s>>k)
	{
		if(l>=s)
		{
			v=sqrt(2*m*g*s/m);
		}
		else 
		{
			a=m*g*s-0.5*k*(s-l)*(s-l);
			if(a<1e-8)v=-1;
			else 
			{
				v=sqrt(a/(0.5*m));
			}
		}
		if(v<1e-8)cout<<"S"<<endl;
		else if(v-10>1e-8)cout<<"D"<<endl;
		else cout<<"Y"<<endl;
	}
	return 0;
}



