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
bool vis[100010];
int a[10];
int main()
{
	ios::sync_with_stdio(false);
	int n,maxx,minn,i=0;
	while(cin>>n)
	{
		cout<<"Number="<<n<<endl;
		CLR(vis,0);
		while(!vis[n])
		{
			i=0;
			vis[n]=1;
			while(n)
			{
				a[i++]=n%10;
				n/=10;
			}
			sort(a,a+5);
			maxx=0;
			minn=0;
			for(int j=0;j<5;j++)
			{
				minn=minn*10+a[j];
			}
			for(int j=4;j>=0;j--)
			{
				maxx=maxx*10+a[j];
			}
			n=maxx-minn;
			cout<<maxx<<"-"<<minn<<"="<<n<<endl;
			
		}
		cout<<endl;
	}
	return 0;
}


