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

const int maxn=1010;
int perm[maxn];
bool vis[maxn];
int num;//置换节个数
 
void polya(int n)//n表示要求的为0~n-1的一个置换
{
	num=0;
	CLR(vis,0);
	int j;
	int ret=1;//返回置换最小周期 
	for(int i=0;i<n;i++)
	{
		if(!vis[i])
		{
			num++;
			int p=i;
			for(j=0;!vis[p=perm[p]];j++)
			{
				vis[p]=1;
			}
			//ret*=j/__gcd(ret,j);
		}
	}
	//return ret;
}
ll fast_mod(ll m,int n)
{
	ll temp=m;
	m=1;
	while(n)
	{
		if(n&1)m=m*temp;
		temp=temp*temp;
		n>>=1;
	}
	return m;
}
int main()
{
	ios::sync_with_stdio(false);
	int n,c;
	while(cin>>c>>n&&(n||c))
	{
		ll ans=0;
		for(int i=0;i<n;i++)
		{
			for(int j=0;j<n;j++)
			{
				perm[j]=(j+i)%n;
			}
			polya(n);
			ans+=fast_mod(c,num);
		}
		if(n&1)
		{
			num=n/2;
			ans+=n*fast_mod(c,num+1);
			ans/=(2*n);
		}
		else
		{
			num=n/2;
			ans+=num*fast_mod(c,num);
			ans+=num*fast_mod(c,num+1);
			ans/=(n*2);
		}
		cout<<ans<<endl;
	}
	
	return 0;
}



