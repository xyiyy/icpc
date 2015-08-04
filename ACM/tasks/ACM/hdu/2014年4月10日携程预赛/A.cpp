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

ll gcd(ll a,ll b)
{
	return (b>0)?gcd(b,a%b):a;
}

int main()
{
	ios::sync_with_stdio(false);
	int N;
	ll a,b;
	cin>>N;
	while(N--)
	{
		cin>>a>>b;
		ll ans=1,c=1;
		ll k=0;
		REP(i,b)
		{
			if(gcd(i+1,b)!=1)k++;
		}
		REP(i,a)
		{
			ans*=b;
			c*=k;
		}
		cout<<(ans-c)<<endl;
	}
	
	return 0;
}
