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
int a[110],b[110];
bool cmp(int x,int y)
{
	return a[x]>a[y];
}
int main()
{
	ios::sync_with_stdio(false);
	int n,c;
	while(cin>>n>>c)
	{
		for(int i=0;i<n;i++)
		{
			cin>>a[i]>>b[i];
			id[i]=i;
		}
		sort(id,id+n,cmp);
		ll sum=0;
		int j=0;
		for(int i=0;i<n;i++)
		{
			if(a[id[i]]>=c)
			{
				sum+=b[id[i]];
			}
			else 
			{
				j=i;
				break;
			}
		}
		int l=j,r=n-1;
		int k;
		while(l<=r)
		{
			k=c/a[l];
			if(b[l]>=k)
			{
				b[l]-=k;
				if(k*a[l]==c)
				{
					sum++;
					continue;
				}
				else 
				{
					add=(c-k*a[l]+a[r]-1)/a[r];
					
				
			
				
	return 0;
}


