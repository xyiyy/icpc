//gaoshenbaoyou  ------ pass system test
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
int a[3010],id[3010];
bool cmp(int x,int y)
{
	return a[x]<=a[y];
}
map<int,int>ms;
vector<pair<int,int> >v;
int main()
{
	ios::sync_with_stdio(false);
	int n;
	while(cin>>n)
	{
		ms.clear();
		v.clear();
		for(int i=0;i<n;i++)
		{
			cin>>a[i];
			id[i]=i;
			ms[i]=a[i];
		}
		sort(id,id+n,cmp);
		for(int i=0;i<n;i++)
		{
			if(ms[i]==a[id[i]])continue;
			else 
			{
				v.PB(MP(i,id[i]));
				ms[id[i]]=a[i];
			}
		}
		cout<<v.size()<<endl;
		for(int i=0;i<v.size();i++)
		{
			cout<<v[i].first<<" "<<v[i].second<<endl;
		}
	}
	return 0;
}



