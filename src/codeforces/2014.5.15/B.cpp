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
int a[100010];
int b[100010];
int c[100010][2];
int main()
{
	ios::sync_with_stdio(false);
	int n;
	while(cin>>n)
	{
		int u,v;
		memset(a,0,sizeof(a));
		memset(b,0,sizeof(b));
		memset(c,0,sizeof(c));
		for(int i=0;i<n;i++)
		{
			cin>>u>>v;
			a[u]++;
			b[i]=v;
		}
		for(int i=0;i<n;i++)
		{
			c[i][0]=n-1+a[b[i]];
			c[i][1]=n-1-a[b[i]];
		}
		for(int i=0;i<n;i++)
		{
			cout<<c[i][0]<<" "<<c[i][1]<<endl;
		}
	}
	return 0;
}

