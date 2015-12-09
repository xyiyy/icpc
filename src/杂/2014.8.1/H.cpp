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
string ss,sb;
int main()
{
	ios::sync_with_stdio(false);
	int n;
	cin>>n;
	string s;
	int d,m,y;
	int ys=3000,yb=0,ms=3000,mb=0,ds=3000,db=0;
	while(n--)
	{
		cin>>s>>d>>m>>y;
		if(y<ys||(y==ys&&m<ms)||(y==ys&&m==ms&&d<ds))
		{
			ss=s;
			ys=y;ms=m;ds=d;
		}
		if(y>yb||(y==yb&&m>mb)||(y==yb&&m==mb&&d>db))
		{
			sb=s;
			yb=y;mb=m;db=d;
		}
	}
	cout<<sb<<endl<<ss<<endl;
			
		
	return 0;
}


