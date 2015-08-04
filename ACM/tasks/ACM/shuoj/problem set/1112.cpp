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
ll a[21];

int main()
{
	ios::sync_with_stdio(false);
	a[0]=1;
	for(int i=1;i<21;i++)
	{
		a[i]=a[i-1]*i;
	}
	int n;
	while(cin>>n)
	{
		ll sum=0;
		for(int i=1;i<=n;i++)
		{
			sum+=a[i];
		}
		cout<<sum<<endl;
	}
	return 0;
}

