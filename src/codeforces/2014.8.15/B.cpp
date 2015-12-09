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
const int maxn=300010;
ll a[maxn];
int main()
{
	ios::sync_with_stdio(false);
	ll n;
	//ll ans=0;
	while(cin>>n)
	{
		ll maxx=-INF;
		ll minn=INF;
		for(int i=0;i<n;i++)
		{
			cin>>a[i];
			minn=min(minn,a[i]);
			maxx=max(maxx,a[i]);
		}
		ll num1=0,num2=0;
		for(int i=0;i<n;i++)
		{
			if(a[i]==maxx)num1++;
			if(a[i]==minn)num2++;
		}
		ll ans=0;
		cout<<maxx-minn<<" ";
		if(maxx==minn)
		{
			ans=n*(n-1)/2;
		}
		else 
		{
			ans=num1*num2;
		}
		cout<<ans<<endl;
	}
	return 0;
}


