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
ll dp[21][3];
int a[20];
int main()
{
	ios::sync_with_stdio(false);
	int T;
	CLR(dp,0);
	dp[0][0]=1;
	for(int i=1;i<21;i++)
	{
		dp[i][0]=dp[i-1][0]*10-dp[i-1][1];
		dp[i][1]=dp[i-1][0];
		dp[i][2]=dp[i-1][2]*10+dp[i-1][1];
	}
	unsigned long long n;
//	ll n;
	ll ans;
	int last;
	int flag;
	cin>>T;
	while(T--)
	{
		 cin>>n;
		 ans=0;
		 last=0;
		 int i=0;
		 //n++;
		 CLR(a,0);
		 n++;
		 while(n)
		 {
		 	a[++i]=n%10;
		 	n/=10;
		 }
		 //cout<<dp[1][0]<<endl;
		 flag=0;
		 for(int j=i;j>=1;j--)
		 {
		 	ans+=dp[j-1][2]*a[j];
		 	if(flag)
		 	{
		 		ans+=dp[j-1][0]*a[j];
			}
			if(!flag&&a[j]>4)
			{
				ans+=dp[j-1][1];
			}
			if(last==4&&a[j]==9)
			{
				flag=1;
			}
			last =a[j];
			//cout<<ans<<endl;
		}
		cout<<ans<<endl;
	}
		 
		 	
	return 0;
}


