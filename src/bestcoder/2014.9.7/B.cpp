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
	ll n,m;
	while(cin>>n>>m)
	{
		unsigned long long ans=1,temp=4;
		if(n&1)
		{
			n=(n+1)/2;
			while(n)
			{
				if(n&1)ans=(ans*temp)%(3*m);
				//if(ans>10*m)ans%=m;
				temp=temp*temp;
				//if(temp>10*m)
				temp%=(3*m);
				n>>=1;
			}
			ans/=3;
		}
		else 
		{
			n/=2;
			while(n)
			{
				if(n&1)ans=(ans*temp)%(3*m);
				//if(ans>10*m)ans%=m;
				temp=temp*temp;
				//if(temp>10*m)
				temp%=(3*m);
				n>>=1;
			}
			ans/=3;
			ans*=2;
		}
		ans=ans%m;
		cout<<ans<<endl;
	}
	return 0;
}



