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
const int MAXN=100010;
int vis[MAXN];
int prime[MAXN];
int mu[MAXN];
int N=100010;
int cnt;
void init()
{
	memset(vis,0,sizeof(vis));
	mu[1]=1;
	cnt=0;
	for(int i=2;i<N;i++)
	{
		if(!vis[i])
		{
			prime[cnt++]=i;
			mu[i]=-1;
		}
		for(int j=0;j<cnt&&i*prime[j]<N;j++)
		{
			vis[i*prime[j]]=1;
			if(i%prime[j])mu[i*prime[j]]=-mu[i];
			else 
			{
				mu[i*prime[j]]=0;
				break;
			}
		}
	}
}

		
		 
int main()
{
	ios::sync_with_stdio(false);
	int t;
	init();
	cin>>t;
	int n,m;
	while(t--)
	{
		cin>>n>>m;
		ll ans=0;
		if(n<m)swap(n,m);
		for(int i=1;i<=m;i++)
		{
			ans+=(ll)mu[i]*(n/i)*(m/i);
		}
		cout<<ans<<endl;
		/*ans=0;
		for(int i=1;i<=n;i++)
		{
			for(int j=1;j<=m;j++)
			{
				if(__gcd(i,j)==1)
				{
					ans++;
				}
			}
		}
		cout<<ans<<endl;*/
	}
	return 0;
}



