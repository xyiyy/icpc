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

int GCD(int x, int y)
{ int t;
     while(y > 0) {t = x % y;x = y;y = t;}
     return x;}
     
int extended_euclid(int a, int b, int &x, int &y)
{  int d;
     if(b == 0) {x = 1;     y = 0;     return a;}
     d = extended_euclid(b, a % b, y, x);y -= a / b * x;
     return d;}


void modular_linear_equation(int a, int b, int n)
{  int d, x, y, x0, gcd;
gcd = GCD(a, n);
		if (b%gcd != 0) {
			cout << "no solutions!" << endl;return ;}
	a /= gcd; b /= gcd; n /= gcd;d = extended_euclid(a, n, x, y); 
     if( b%d == 0) {  x0 = ( x*(b/d) ) % n; 
          int ans = n;
          for(int i=0; i < d ;i++) {
               ans = (( x0 + i*(n/d) )+n) % n; cout << ans << endl;}     }
     else     cout << "no solutions!" << endl; }


int main()
{
	ios::sync_with_stdio(false);
	int a,b,m;
	while(cin>>a>>b>>m)
	{
		 modular_linear_equation(a,b,m);
	}
	
	
	return 0;
}


