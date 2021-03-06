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
	int n,m,k=1;
	int num=0;
	queue <int > q;
	while(cin>>n>>m)
	{
		for(int i=1;i<=n;i++)
		{
			q.push(i);
		}
		num=0;
		while(q.size()!=1)
		{
			num++;
			if(num%m!=0)
			q.push(q.front());
			q.pop();
		}
		cout<<"Case "<<k++<<": "<<n<<", "<<m<<", "<<q.front()<<endl;
		while(!q.empty())
		{
			q.pop();
		}
	}
	return 0;
}

