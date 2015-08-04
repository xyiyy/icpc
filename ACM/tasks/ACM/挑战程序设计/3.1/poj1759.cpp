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
const double eps=1e-7;
double h[1010];
int main()
{
	ios::sync_with_stdio(false);
	int n;
	while(cin>>n>>h[0])
	{
		double l=-1,r=1000000000;
		bool flag=1;
		double ans;
		while(r-l>eps)
		{
			flag=1;
			h[1]=(l+r)/2.0;
			for(int i=2;i<n;i++)
			{
				h[i]=2*h[i-1]-h[i-2]+2;
				if(h[i]<0.00)
				{
				//	cout<<"low"<<endl;
					flag=0;
					break;
				}
			}
			if(flag)
			{
				r=h[1];
				ans=h[n-1];
			//	cout<<"high"<<endl;
			}
			else
			{
				l=h[1];
			}
		}
		cout<<fixed<<setprecision(2)<<ans<<endl;
	}
				
				
	return 0;
}


