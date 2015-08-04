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
const ll kk=100000;
int main()
{
	ios::sync_with_stdio(false);
	int t;
	cin>>t;
	ll n,m;
	while(t--)
	{
		cin>>n>>m;
		m=n*n-m+1;
		ll l=-1e12,r=1e12;
		ll mid;
		while(l+1<r)
		{
			mid=(l+r)/2;
			ll num=0;
			ll l1,r1;
			ll mid1;
			for(ll j=1;j<=n;j++)
			{
				l1=0,r1=n+1;
				while(l1+1<r1)
				{
					mid1=(l1+r1)/2;
					if(mid1*mid1+(100000)*mid1+j*j-(100000)*j+mid1*j>=mid)
					{
						r1=mid1;
					}
					else
					{
						l1=mid1;
					}
				}
				num+=n-r1+1;
			}
			if(num>=m)
			{
				l=mid;
			}
			else
			{
				r=mid;
			}
		}
		cout<<l<<endl;
	}
				
		
	return 0;
}


