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
ll dp[1000][1000];

ll C(int m, int n)
{
	if(m<1000&&n<1000&&dp[m][n]) return dp[m][n];
	if(m==n||n==0)return 1;
	if(n==1) return m;
	ll ret = C(m-1,n-1)*m/n;
	if(m<1000&&n<1000)dp[m][n]=ret;
	return ret;
}

int main()
{
	ios::sync_with_stdio(false);
	ll a;
	int n;
	while(cin>>n)
	{
		a=C(2*n,n)/(n+1);
		cout<<a<<endl;
	}
	return 0;
}

