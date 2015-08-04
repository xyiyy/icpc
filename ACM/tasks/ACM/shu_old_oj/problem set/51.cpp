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
	int maxx,minn,sum,a;
	double ave;
	while(cin>>n)
	{
		maxx=-1;
		minn=110;
		sum=0;
		for(int i=0;i<n;i++)
		{
			cin>>a;
			maxx=max(a,maxx);
			minn=min(a,minn);
			sum+=a;
		}
		ave=sum*1.0/(n*1.0);
		cout<<maxx<<" "<<minn<<" "<<sum<<" "<<fixed<<setprecision(2)<<ave<<endl;
	//	cout<<scientific;
	//	printf("%lf %lf %lf %.2lf\n",maxx,minn,sum,ave);
	}
		
	return 0;
}


