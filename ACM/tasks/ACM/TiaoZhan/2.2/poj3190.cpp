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
struct sta
{
	int l,r,num;
	bool operator<(const sta &a)const 
	{
		return a.r<r;
	}
}cow[50010];
int id[50010];
bool cmp(int x,int y)
{
	return cow[x].l<cow[y].l;
}
int main()
{
	ios::sync_with_stdio(false);
	int n;
	while(cin>>n){
		for(int i=0;i<n;i++)
		{
			cin>>cow[i].l>>cow[i].r;
			id[i]=i;
		}
		sort(id,id+n,cmp);
		priority_queue <sta>q;
		cow[id[0]].num=1;
		q.push(cow[id[0]]);
		int i=1;
		int k=1;
		while(i<n)
		{
			sta c=q.top();
			if(cow[id[i]].l>c.r)
			{
				q.pop();
				cow[id[i]].num=c.num;
				q.push(cow[id[i]]);
			}
			else 
			{
				k++;
				cow[id[i]].num=k;
				q.push(cow[id[i]]);
			}
			i++;
		}
		cout<<k<<endl;
		for(int i=0;i<n;i++)
		{
			cout<<cow[i].num<<endl;
		}
	}
		
	return 0;
}


