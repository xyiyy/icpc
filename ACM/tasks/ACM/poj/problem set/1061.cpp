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
ll x,y,m,n,l;
ll xx,yy;
ll extgcd(ll a,ll b)
{
	ll d=a;
	ll t;
	if(b!=0)
	{
		d=extgcd(b,a%b);
		t=xx;
		xx=yy;
		yy=t-(a/b)*yy;
	}
	else{
		xx=1;yy=0;
	}
	return d;
}
ll mod(ll a,ll b)
{
	if(a>=0)return a%b;
	else return a%b+b;
}


int main()
{
	ios::sync_with_stdio(false);
	cin>>x>>y>>m>>n>>l;
	ll d,c;
	if(m>n)
	{	
		d=extgcd(m-n,l);
		c=y-x;
	}
	else 
	{
		d=extgcd(n-m,l);
		c=x-y;
	}
	if(c%d!=0)
	{
		cout<<"Impossible"<<endl;
	}
	else 
	{
		l/=d;
		ll times=mod(xx*c/d,l);
		cout<<times<<endl;
	}
	return 0;
}

