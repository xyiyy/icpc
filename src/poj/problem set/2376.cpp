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
int a[30000][2];
int id[30000];
bool cmp(int x,int y)
{
	if(a[x][0]==a[y][0])return a[x][1]<a[y][1];
	return a[x][0]<a[y][0];
}	
int main()
{
	ios::sync_with_stdio(false);
	int n,t;
	int e;
	int num;
	int mark;
	while(cin>>n>>t)
	{
		CLR(a,0);
		CLR(id,0);
		for(int i=0;i<n;i++)
		{
			cin>>a[i][0]>>a[i][1];
			id[i]=i;
		}
		sort(id,id+n,cmp);
		int i=0;
		e=-1;
		int flag=0;
		if(a[id[i]][0]!=1)flag=1;
		if(!flag)
		{
			while(a[id[i]][0]==1&&i<n)
			{
				e=max(a[id[i]][1],e);
				i++;
			}
			num=1;
			int j=i;
			while(j<n&&e<t)
			{
				mark=1;
				int ne=e;
				while(a[id[j]][0]<=e+1&&j<n)
				{
					if(a[id[j]][1]>ne)
					{
						mark=0;
						ne=a[id[j]][1];
					}
					j++;
					if(ne>=t)break;
				}
				e=ne;	
				num++;
				if(e>=t)break;
				if(mark)break;
			
			}
		}
		if(e<t)cout<<-1<<endl;
		else cout<<num<<endl;
	}
			
	return 0;
}


