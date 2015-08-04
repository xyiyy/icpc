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
typedef pair<ll,ll> PII;
typedef vector<PII> VII;
typedef vector<int> VI;
PII p[10010];
int siz[10010];
int main()
{
	ios::sync_with_stdio(false);
	ll n;
	while(cin>>n)
	{	
		CLR(siz,0);
		int id=0;
		ll maxn=sqrt(n*1.0)+1;
		ll sum=0;
		ll s=1,t=0;
		for(;;)
		{
			while(t<=maxn&&sum<n)
			{
				t++;
				sum+=t*t;
			}
			if(t>maxn)break;
			if(sum==n)
			{
				p[id].first=s;
				p[id].second=t;
				sum-=s*s;
				id++;
				s++;
			}
			else if(sum>n)
			{
				sum-=s*s;
				s++;
			}
		}
		cout<<id<<endl;
		for(int i=0;i<id;i++)
		{
			cout<<p[i].second-p[i].first+1;
			for(int j=p[i].first;j<=p[i].second;j++)
			{
				cout<<" "<<j;
			}
			cout<<endl;
		}
	}
			
			
			
	return 0;
}


