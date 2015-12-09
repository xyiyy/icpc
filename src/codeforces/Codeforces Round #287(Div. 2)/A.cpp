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
int a[110];
int id[110];
bool cmp(int x,int y)
{
	return a[x]<a[y];
}
int main()
{
	ios::sync_with_stdio(false);
	int n,m;
	while(cin>>n>>m)
	{
		vector<int>ans;
		for(int i=0;i<n;i++)cin>>a[i];
		for(int i=0;i<n;i++)id[i]=i;
		sort(id,id+n,cmp);
		int i=0;
		for(i=0;i<n;i++)
		{
			if(m>=a[id[i]])
			{
				m-=a[id[i]];
				ans.PB(id[i]+1);
			}
			else break;
		}
		cout<<i<<endl;
		for(int j=0;j<i;j++)
		{
			cout<<ans[j]<<" ";
		}
		if(i)
		cout<<endl;
	}
	return 0;
}



