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
#define test cout<<"ok"<<endl
typedef long long ll;
typedef pair<int,int> PII;
typedef vector<PII> VII;
typedef vector<int> VI;
int a[10010];
int b[10010],id[10010];
int n,l,p;
bool cmp(int x,int y)
{
	return a[x]<a[y];
}
void solve()
{
	for(int i=n-1;i>=0;i--)
	{
		cin>>a[i]>>b[i];
		id[i]=i;
	}
	cin>>l>>p;
	a[n]=l;b[n]=0;
	id[n]=n;
	for(int i=0;i<n;i++)
	{
		a[i]=l-a[i];
	}
	sort(id,id+n,cmp);
	n++;
	priority_queue<int >q;
	int ans=0,pos=0,tank=p;
	for(int i=0;i<n;i++)
	{
		int d=a[id[i]]-pos;
		while(tank-d<0)
		{
			if(q.empty())
			{
				cout<<"-1"<<endl;
				return ;
			}
			tank+=q.top();
			q.pop();
			ans++;
		}
		tank-=d;
		pos=a[id[i]];
		q.push(b[id[i]]);
	}
	cout<<ans<<endl;
}
int main()
{
	ios::sync_with_stdio(false);
	
	while(cin>>n)
	{
		solve();
	}
				
		
	return 0;
}


