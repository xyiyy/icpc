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
using namespace std;
#define XINF INT_MAX
#define INF 0x3FFFFFFF
#define MP(X,Y) make_pair(X,Y)
#define PB(X) push_back(X)
#define REP(X,N) for(int X=0;X<N;X++)
typedef pair<int,int> PII;
typedef vector<int> VI;
typedef long long ll;
int a[1000010];
long long l,now,r,ans;

int main()
{
	ios::sync_with_stdio(false);
	int n,m;
	cin>>n>>m;
	REP(i,n)cin>>a[i];
	now=n/2;r=n-1;l=0;ans=0;
	while(r>now){ans+=a[r]-a[now];ans+=a[r]-a[now];r-=m;}
	while(l<now){ans+=a[now]-a[l];ans+=a[now]-a[l];l+=m;}
	cout<<ans<<endl;
	return 0;
}

