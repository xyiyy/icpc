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
		int a;
		priority_queue<int ,vector<int >,greater<int> >q;
		for(int i=0;i<n;i++)
		{
			cin>>a;
			q.push(a);
		}
		int l1,l2;
		ll ans=0;
		while(q.size()>1)
		{
			l1=q.top();
			q.pop();
			l2=q.top();
			q.pop();
			ans+=l1+l2;
			q.push(l1+l2);
		}
		cout<<ans<<endl;
	}
	return 0;
}


