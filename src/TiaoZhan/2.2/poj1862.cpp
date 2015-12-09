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

int main()
{
	ios::sync_with_stdio(false);
	int n;
	while(cin>>n)
	{
		priority_queue <double >q;
		double a;
		for(int i=0;i<n;i++)
		{
			cin>>a;
			q.push(a);
		}
		double b;
		while(q.size()>1)
		{
			a=q.top();
			q.pop();
			b=q.top();
			q.pop();
			a=2.0*sqrt(a*b);
			q.push(a);
		}
		a=q.top();
		cout<<fixed<<setprecision(3)<<a<<endl;
	}
	return 0;
}


