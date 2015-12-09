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
int a[5010];
int n;
int num;
int dfs(int l,int r,int w)
{
	if(w==0)return 0;
	for(int i=l;i<=r;i++)
	{
		if(a[i]>=w)
		{
			a[i]=-1;
			num++;
			w--;
			i=l;
		}
		if(w==0)break;
	}
	if(w==0)return 0;
	int flag=0;
	for(int i=l;i<=r;i++)
	{
		if(a[i]>0)flag=1;
	}
	if(!flag)return 0;
	else 
	{
		int last=l;
		int t=0;
		num++;
		for(int i=l;i<=r;i++)
		{
			a[i]--;
			if(a[i]>0)t++;
			if(a[i]==0)
			{
				dfs(last,i,t);
				t=0;
				last=i+1;
			}	
		}
		dfs(last,r,t);
	}
	return 0;
}
		
		
	
	
int main()
{
	ios::sync_with_stdio(false);
	while(cin>>n)
	{
		num=0;
		CLR(a,0);
		for(int i=1;i<=n;i++)
		{
			cin>>a[i];
		}
		dfs(1,n,n);
		cout<<num<<endl;
	}
	return 0;
}


