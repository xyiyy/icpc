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
long long  a[1010];
int n;
unsigned long long m;
unsigned long long num;
int main()
{
	//ios::sync_with_stdio(false);
	int T;
	scanf("%d",&T);
	while(T--)
	{
		scanf("%d%d",&n,&m);
		num=0;
		for(int i=0;i<n;i++)
		{
			scanf("%d",&a[i]);
		}
		sort(a,a+n);
		for(int i=0;i<n-2;i++)
		{
			for(int j=i+1;j<n-1;j++)
			{
				int k=m-a[i]-a[j];
				int lb=j,ub=n-1;
				while(ub-lb>1)
				{
					int mid = (lb+ub)/2;
					if(a[mid]>=k)
					{
						ub=mid;
					}
					else 
					{
						lb=mid;
					}
				}
			//	cout<<lb<<" "<<ub<<endl;
				if(a[ub]>=k)
				num+=n-1-lb;
			}
		}
		printf("%d\n",num);
	}
	
		
		 
	return 0;
}

