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
//#include <ext/pb_ds/assoc_container.hpp> // Common file
//#include <ext/pb_ds/tree_policy.hpp> // Including tree_order_statistics_node_update
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
double x[1010],y[1010];
int id[1010];
double l[1010],r[1010];
bool cmp1(int a,int b)
{
	if(r[a]==r[b])return l[a]<l[b];
	return r[a]<r[b];
}

int main()
{
	ios::sync_with_stdio(false);
	double d,loc;
	int delta;
	int n,num,cas=1,flag;
	while(cin>>n>>d&&(n||d))
	{
		flag=0;
		for(int i=0;i<n;i++)
		{
			cin>>x[i]>>y[i];
			id[i]=i;
			if(fabs(y[i])>d)flag=1;
			
			if(!flag)
			{
				delta=d*d-y[i]*y[i];
				l[i]=x[i]-sqrt((double)delta);
				r[i]=x[i]+sqrt((double)delta);
			}
		}
		cout<<"Case "<<cas++<<": ";
		sort(id,id+n,cmp1);
		
		int i=0,j=0;
		num=0;
		if(flag)
		{
			cout<<-1<<endl;
		}
		else 
		{
			int i=0;
			while(i<n)
			{
				loc=r[id[i]];
				num++;
				i++;
				while(l[id[i]]<=loc&&i<n)
				{
					i++;
				}
			}
			cout<<num<<endl;
		}
		
	}
	return 0;
}


