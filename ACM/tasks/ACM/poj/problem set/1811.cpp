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
#include <time.h>  
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
#define MAXN 100
#define C 16381  
ll minn;

ll multi(ll a, ll b, ll n){
	ll tmp = a % n, s = 0;
	while(b){
		if(b & 1) s = (s + tmp) % n;
		tmp = (tmp + tmp) % n;
		b >>= 1;
	}
	return s;
}

ll Pow(ll a, ll b, ll n){
	ll tmp = a % n, s = 1;
	while(b){
		if(b & 1) s = multi(s, tmp, n);
		tmp = multi(tmp, tmp, n);
		b >>= 1;
	}
	return s;
}

int witness(ll a, ll n){
	ll u = n - 1, t = 0, i, x, y;
	while(!(u & 1))	u >>= 1, t ++;
	x = Pow(a, u, n);
	for(i = 1; i <= t; i ++){
		y = multi(x, x, n);
		if(y == 1 && x != 1 && x != n -1) return 1;
		x = y;
	}
	if(x != 1) return 1;
	return 0;
}

int test(ll n){
	ll a;
	int i;
	if(n == 2) return 1;
	if(n < 2 || !(n & 1)) return 0;
	srand((ll)time(0));
	for(i = 0; i < MAXN; i ++){
		a = ((ll) rand()) % (n - 2) + 2;
		if(witness(a, n)) return 0;
	}
	return 1;
}

ll gcd(ll a, ll b){
	return b ? gcd(b, a % b) : a;
}

ll pollard_rho(ll n, ll c){
	ll x, y, d, i = 1, k = 2;
	srand((ll)time(0));
	x = ((ll) rand()) % (n - 1) + 1;
	y = x;
	while(1){
		i ++;
		x = (multi(x, x, n) + c) % n;
		d = gcd(y - x + n, n);
		if(d != 1 && d != n) return d;
		if(y == x) return n;
		if(i == k) y = x, k <<= 1;
	}
}

void find(ll n, ll c){
	ll r;
	if(n <= 1) return;
	if(test(n)){
		if(minn > n) minn = n;
		return;
	}
	r = pollard_rho(n, c--);
	find(n / r, c);
	find(r, c);
}

ll MaxPrimeFactor(ll n)
{
	if(test(n))
	return n;
	
	ll k=-1,g;
	minn=n;
	find(n,C);
	
	g=MaxPrimeFactor(minn);
	k=g>k?g:k;
	
	g=MaxPrimeFactor(n/minn);
	k=g>k?g:k;
	return k;
}
int main()
{
	ios::sync_with_stdio(false);
	int t;
	cin>>t;
	ll n;
	while(t--)
	{
		cin>>n;
		if(test(n))cout<<"Prime"<<endl;
		else 
		{
			minn=n;
			find(n,C);
			cout<<minn<<endl;
		}
	}
	return 0;
}


