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
const int maxn=110;
int a[maxn],b[maxn];
map<int,int>ms;
map<int,int>::IT x,y;
int main()
{
	ios::sync_with_stdio(false);
	int n,m;
	while(cin>>n>>m)
	{
		ms.clear();
		ms.insert(MP(0,0));
		ms.insert(MP(INF,0));
		int l,r;
		for(int i=0;i<m;i++)
		{
			cin>>l>>r;
			if(ms.lower_bound(r+1)->first!=r+1)
			{
				x=ms.lower_bound(r+1);
				x--;
				ms.insert(MP(r+1,x->second));
			}
			x=ms.lower_bound(l);
			int k=ms.upper_bound(r)->first;
			while(k>x->first)
			{
				ms.erase(x);
				x=ms.lower_bound(l);
			}
			ms.insert(MP(l,1));
		}
		int ans=0;
		for(x=ms.begin();x->first<=n;)
		{
			y=x;
			x++;
			ans+=(y->second)*(x->first-y->first);
		}
		cout<<n+1-ans<<endl;
	}
			
			
	return 0;
}



