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
ll dp1[4010];
ll dp2[4010];
ll num[2010][2010];
int main()
{
	ios::sync_with_stdio(false);
	int n;
	while(cin>>n)
	{
		//ll a;
		CLR(dp1,0);
		CLR(dp2,0);
		ll maxx1=0,maxx2=0;
	//	ll maxn1=0,maxn2=0;
		ll x1=1,x2=1,y1=1,y2=2;
		for(int i=1;i<=n;i++)
		{
			for(int j=1;j<=n;j++)
			{
				cin>>num[i][j];
				dp1[2000+i-j]+=num[i][j];
				dp2[i+j]+=num[i][j];
				/*if(dp1[2000+i-j]>maxx1)
				{
					maxx2=maxx1;
					x2=x1;
					maxx1=dp1[2000+i-j];
					x1=i-j;
					
				}
				else if(dp1[2000+i-j]<=maxx1&&dp1[2000+i-j]>maxx2)
				{
					 x2=i-j;
					 maxx2=dp1[2000+i-j];
				}
				if(dp2[i+j]>maxn1)
				{
					maxn2=maxn1;
					y2=y1;
					maxn1=dp2[i+j];
					y1=i+j;
				}
				else if(dp2[i+j]<=maxn1&&dp2[i+j]>maxn2)
				{
					y2=i+j;
					maxn2=dp2[i+j];
				}*/
			}
		}
		ll temp;
		for(int i=1;i<=n;i++)
		{
			for(int j=1;j<=n;j++)
			{
				temp=dp2[i+j]+dp1[2000+i-j]-num[i][j];
				if((i+j)%2==1&&temp>maxx1)
				{
					maxx1=temp;
					x1=i;
					y1=j;
				}
				else if((i+j)%2==0&&temp>maxx2)
				{
					maxx2=temp;
					x2=i;
					y2=j;
				}
			}
		}
		cout<<maxx1+maxx2<<endl;
		cout<<x1<<" "<<y1<<" "<<x2<<" "<<y2<<endl;
	}
		
		
	return 0;
}



