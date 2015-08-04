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
const int maxn=50010;
ll a[maxn],b[maxn];
int id[maxn];
bool cmp(int x,int y)
{
	return a[x]+b[x]<a[y]+b[y];
}
int main()
{
	ios::sync_with_stdio(false);
	int n;
	while(cin>>n)
	{
		for(int i=0;i<n;i++)
		{
			cin>>a[i]>>b[i];
			id[i]=i;
		}
		sort(id,id+n,cmp);
		ll sum=0;
		ll ans=-1000000;
		for(int i=0;i<n;i++)
		{
			ans=max(sum-b[id[i]],ans);
			sum+=a[id[i]];
		}
		cout<<ans<<endl;
	}
	return 0;
}


