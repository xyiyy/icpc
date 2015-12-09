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
const int maxn=100010;
char s[maxn];
ll bit1[maxn],bit2[maxn];
ll fu[maxn];
int len;
void Add1(int i,ll x)
{
	while(i<=len)
	{
		bit1[i]+=x;
		i+=i&-i;
	}
}
ll Sum1(int i)
{
	ll s=0;
	while(i>0)
	{
		s+=bit1[i];
		i-=i&-i;
	}
	return s;
}
void Add2(int i,ll x)
{
	while(i<=len)
	{
		bit2[i]+=x;
		i+=i&-i;
	}
}
ll Sum2(int i)
{
	ll s=0;
	while(i>0)
	{
		s+=bit2[i];
		i-=i&-i;
	}
	return s;
}
int num[10];
int vis[10];		
int main()
{
	ios::sync_with_stdio(false);
	for(int i=1;i<=8;i++)
	{
		num[i]=0;
	}
	for(int i=1;i<=8;i++)
	{
		CLR(vis,0);
		int m=1;
		for(int j=1;j+i-1<=8;j++)
		{
			m=1;
			for(int k=j;k<j+i;k++)
			{
				vis[k]+=m;
				m*=-1;
			}
		}
		for(int i=1;i<=8;i++)
		{
			cout<<vis[i]<<" ";
			num[i]+=vis[i];
		}
		cout<<endl;
		
	}
	for(int i=1;i<=8;i++)
	{
		cout<<num[i]<<" ";
	}
	cout<<endl;
	
		
	return 0;
}



