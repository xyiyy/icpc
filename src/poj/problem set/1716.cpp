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
int l[10010],r[10010];
int id[10010];
bool cmp(int x,int y)
{
	if(r[x]==r[y])return l[x]<l[y];
	return r[x]<r[y];
}
	
int main()
{
	ios::sync_with_stdio(false);
	int n,a,b;
	int num;
	while(cin>>n)
	{
		for(int i=0;i<n;i++)
		{
			cin>>l[i]>>r[i];
			id[i]=i;
		}
		sort(id, id+n,cmp);
		a=r[id[0]]-1;b=r[id[0]];
		int i=0;
		num=2;
		i++;
		while(i<n)
		{
			if(a>=l[id[i]]&&b<=r[id[i]])
			{
				i++;
				continue;
			}
			else if(b<=r[id[i]]&&a<l[id[i]]&&b>=l[id[i]])
			{
				num++;
				a=b;
				b=r[id[i]];
				i++;
				continue;
			}
			else if(b<l[id[i]])
			{
				num+=2;
				a=r[id[i]]-1;
				b=r[id[i]];
				i++;
				continue;
			}
		}
		cout<<num<<endl;
				
	}
		
	return 0;
}


