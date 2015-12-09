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
int n;
const int maxn=1000010;
ll dp[maxn];
int vis[maxn];
int vis1[maxn];
ll bit[maxn];
int a[maxn];
void add(int i,int x)
{
	while(i<=n)
	{
		bit[i]+=x;
		i+=i&-i;
	}
}
ll sum(int i)
{
	ll s=0;
	while(i>0)
	{
		s+=bit[i];
		i-=i&-i;
	}
	return s;
}
int main()
{
	ios::sync_with_stdio(false);
	while(cin>>n)
	{
		CLR(dp,0);
		map<int,int>m;
		for(int i=1;i<=n;i++)
		{
			cin>>a[i];
			if(i<n)
			{
				m[a[i]]++;
				vis[i]=m[a[i]];
			}
		}
		for(int i=1;i<n;i++)
		{
			add(vis[i],1);
		}
		map<int,int>m2;
		for(int i=n;i>1;i--)
		{
			m2[a[i]]++;
			vis1[i]=m2[a[i]];
		}
		ll ans=0;
		for(int i=n;i>1;i--)
		{
			ans+=i-1-sum(vis1[i]);
		//	add(vis1[i],-1);
			add(vis[i-1],-1);
		}
		cout<<ans<<endl;
	}
		
			
			
			
			
	return 0;
}


