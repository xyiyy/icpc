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


int main()
{
	ios::sync_with_stdio(false);
	unsigned long long sum;
	unsigned long long n,m;
	while(cin>>n>>m&&(n||m))
	{
		if(m<n)
		{
			unsigned long long temp=m;
			m=n;
			n=temp;
		}
		sum=n*m*(n+m-2)+2*n*(n-1)*(3*m-n-1)/3;
		cout<<sum<<endl;
	}
	return 0;
}

