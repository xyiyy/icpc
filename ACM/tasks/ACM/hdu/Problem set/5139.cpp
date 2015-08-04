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
const int mod=1000000007;
const int maxn=100007;
int  a[maxn];
int b[maxn];
int id[maxn];
bool cmp(int x,int y)
{
	return a[x]<a[y];
}
int main()
{
	ios::sync_with_stdio(false);
	int n;
	int i=0;
	while(scanf("%d",&a[i])!=EOF)
	{
		i++;
		id[i]=i;
	} 
	int size=i;
	ll t1=1,t2=1,t3=1;
	ll temp;
	sort(id,id+size,cmp);
	ll j=1;
	for(i=0;i<size;i++)
	{
		while(j<=a[id[i]])
		{
			t2=t2*j;
			t2%=mod;
			t3*=t2;
			t3%=mod;
			j++;
		}
		b[id[i]]=t3;
		
	}
	for(i=0;i<size;i++)
	{	
		printf("%d\n",b[i]);
	}
	return 0;
}



