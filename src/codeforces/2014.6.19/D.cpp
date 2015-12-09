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
double a[110];
double b[110];

int main()
{
	ios::sync_with_stdio(false);
	int n;
	double p=0,q=0;
	while(cin>>n)
	{
		for(int i=0;i<n;i++)
		{
			cin>>a[i];
		}
		sort(a,a+n);
		reverse(a,a+n);
		double maxn=0;
		for(int i=0;i<n;i++)
		{
			b[i]=1-a[i];
		}
		maxn=a[0];
		for(int i=1;i<=n;i++)
		{
			q=0;
			for(int j=0;j<i;j++)
			{	
				p=1.0;
				for(int k=0;k<i;k++)
				{
					if(k==j)
					{
						p=p*a[k];
					}else 
					{
						p=p*b[k];
					}
				}
				q+=p;
			}
			maxn=max(q,maxn);
		}
		cout<<fixed<<setprecision(12)<<maxn<<endl;
	}
	return 0;
}

