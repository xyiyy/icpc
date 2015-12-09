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
int fast_mod(unsigned long long m)
{
	int ret=1;
	int ans=4;
	while(m)
	{
		if(m&1)ret=(ret*ans)%10000;
		ans*=ans;
		ans%=10000;
		m>>=1;
	}
	return ret%100;
}
int main()
{
	ios::sync_with_stdio(false);
	int t;
//	freopen("1837.in","r",stdin);
//	freopen("1837.out","w",stdout);
	int cas=0;
	while(cin>>t&&t)
	{
		if(cas)cout<<endl;
		cas++;
		unsigned long long m;
		for(int i=0;i<t;i++)
		{
			cin>>m;
			cout<<"Case "<<i+1<<": "<<fast_mod(m-1)%100<<endl;
		}
	}
	return 0;
}



