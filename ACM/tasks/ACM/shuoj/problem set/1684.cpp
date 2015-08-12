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

int main()
{
	ios::sync_with_stdio(false);
	int n;
	while(cin>>n)
	{
		int a,b;
		double x=0,y=0;
		for(int i=0;i<n;i++)
		{
			cin>>a>>b;
			x+=a;
			if(b>=90)
			{
				y+=a*4;
			}
			else if(b>=80)
			{
				y+=a*3;
			}
			else if(b>=70)
			{
				y+=a*2;
			}
			else if(b>=60)
			{
				y+=a;
			}
			else if(b==-1)
			{
				x-=a;
			}
		}
		double ans=y*1.0/x;
		cout<<fixed<<setprecision(2)<<ans<<endl;
	}

	return 0;
}



