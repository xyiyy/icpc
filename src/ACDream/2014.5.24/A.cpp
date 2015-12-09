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
bool vis[64];

int main()
{
	ios::sync_with_stdio(false);
	int T;
	cin>>T;
	ll n;
	ll a[64];
	ll m=1;
	for(int i=0;i<64;i++)
	{
		a[i]=m;
		m*=2;
	}
	while(T--)
	{
		cin>>n;
		memset(vis,0,sizeof(vis));
		m=0;
		int j=0;
		for(j=0;n!=0;j++)
		{
			if(n%2==1)vis[j]=1;
			n/=2;
		}
		for(int i=0;j>=0;i++)
		{
			m+=a[i]*vis[--j];
		}
		cout<<m<<endl;
	}
	
		
	return 0;
}

