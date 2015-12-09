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
int a[19];
bool fun(int x,int y)
{
	int minn=INF; 
	for(int i=x;i<=y;i++)
	{
		minn=min(a[i],minn);
	}
	if(minn>a[x-1]&&minn>a[y-1])return 1;
	else return 0;
}
int main()
{
	ios::sync_with_stdio(false);
	int t,cas,ans=0;
	cin>>t;
	while(t--)
	{
		ans=0;
		cin>>cas;
		for(int i=0;i<15;i++)
		{
			cin>>a[i];
		}
		for(int i=1;i<15;i++)
		{
			for(int j=i;j<15-1;j++)
			{
				if(fun(i,j))ans++;
			}
		}
		cout<<cas<<" "<<ans<<endl;
	}
	return 0;
}


