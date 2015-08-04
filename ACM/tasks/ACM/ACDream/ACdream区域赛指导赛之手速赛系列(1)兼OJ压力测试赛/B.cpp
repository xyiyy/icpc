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
using namespace std;
#define XINF INT_MAX
#define INF 0x3FFFFFFF
#define MP(X,Y) make_pair(X,Y)
#define PB(X) push_back(X)
#define REP(X,N) for(int X=0;X<N;X++)
typedef pair<int,int> PII;
typedef vector<int> VI;
typedef long long ll;


int main()
{
//	ios::sync_with_stdio(false);
	int n;
	cin>>n;
	long long a,b;
	long long c;
	long long maxx;
	long long minn;
	while(n--)
	{
		scanf("%lld%lld",&a,&b);

		if(a>=b)
		{
			maxx=a;
			minn=b;
		}
		else 
		{
			maxx=b;minn=a;
		}
		if(a==4611686018427387904&&b==-4611686018427387904||(a==-4611686018427387904&&b==4611686018427387904))
		{
			cout<<"9223372036854775808"<<endl;
		}
		else 
		{
			c=maxx-minn;
			printf("%lld\n",c);
		}
	}
	return 0;
}

