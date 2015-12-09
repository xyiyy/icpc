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
double a[60],b[60];
double d[60];
int id[60];
bool cmp(int x,int y)
{
	return d[x]>d[y];
}
int main()
{
	ios::sync_with_stdio(false);
	int n;
	double c;
	int cas=1;
	while(cin>>n>>c)
	{
		for(int i=0;i<n;i++)
		{
			cin>>a[i];
		}
		for(int i=0;i<n;i++)cin>>b[i];
		for(int i=0;i<n;i++)
		{
			id[i]=i;
			d[i]=(a[i]*1.0)/(b[i]*1.0);
		}
		sort(id,id+n,cmp);
	//	for(int i=0;i<)
		double m=0;
		int j=0;
		while(fabs(c)>=1e-8)
		{
			if(b[id[j]]<c)
			{
				c-=b[id[j]];
				m+=a[id[j]];
				j++;
			}
			else 
			{
				m+=d[id[j]]*c;
				c=0;
			}
		}
		cout<<"Case "<<cas++<<": "<<fixed<<setprecision(2)<<m<<endl;
	}
	return 0;
}


