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
#define x first
#define y second
PII  a[2510],b[2510];
int main()
{
	ios::sync_with_stdio(false);
	int c,l;
	while(cin>>c>>l)
	{
		REP(i,c)cin>>a[i].x>>a[i].y;
		REP(i,l)cin>>b[i].x>>b[i].y;
		sort(a,a+c);
		sort(b,b+l);
		priority_queue <int,vector<int>,greater<int> >q; 
		int j=0,ans=0;
		int spf=0;
		REP(i,l)
		{
			while(j<c&&a[j].x<=b[i].x)
			{
				q.push(a[j].y);
				j++;
			}
			while(b[i].y&&!q.empty())
			{
				spf=q.top();
				q.pop();
				if(spf<b[i].x)continue;
				ans++;
				b[i].y--;
			}
		//	if(j==c)break;
		}
		cout<<ans<<endl;
	}
		
			
		
	return 0;
}


