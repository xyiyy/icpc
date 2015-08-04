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
ll n,m,k;
int main()
{
	ios::sync_with_stdio(false);
	ll t1,t2,t3,t4,p,ans;
	while(cin>>n>>m>>k)
	{
		if(k>(n-1)+(m-1))cout<<"-1"<<endl;
		/*else if(k==0)
		{
			cout<<m*n<<endl;
		}*/
		else 
		{
			t3=0;t4=0;
			t1=min(n,m)*(max(n,m)/(k+1));
			t2=max(n,m)*(min(n,m)/(k+1));
			if(k>max(m-1,n-1))
			{
				p=k-max(m-1,n-1);
				t3=min(n,m)/(p+1);
			}
			if(k>min(m-1,n-1))
			{
				p=k-min(n-1,m-1);
				t4=max(n,m)/(p+1);
			}
			//k-=max(m-1,n-1);
			//cout<<min(n,m)/(k+1)<<endl;
			ans=max(t1,max(t2,max(t3,t4)));
			cout<<ans<<endl;
			
		}
	}
	return 0;
}


