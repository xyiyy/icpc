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
using namespace std;
#define XINF INT_MAX
#define INF 0x3FFFFFFF
#define MP(X,Y) make_pair(X,Y)
#define PB(X) push_back(X)
#define REP(X,N) for(int X=0;X<N;X++)
typedef pair<int,int> PII;
typedef vector<int> VI;
typedef long long ll;
int a[10];
int b[1010];
bool vis[1010];
int sum;
int main()
{
	ios::sync_with_stdio(false);
	int n;
	while(cin>>n)
	{
		sum=0;
		int exp=0;
		memset(b,0,sizeof(b));
		memset(vis,0,sizeof(vis));
		for(int i=0;i<4;i++)
		{
			cin>>a[i];
		}
		for(int i=0;i<n;i++)
		{
			cin>>b[i];
		}
		sort(b,b+n);
		for(int i=0;i<4;i++)
		{
			exp=0;
			while(exp<a[i])
			{
				if(b[n-1]==0)break;
				int index=n;
				int lb=-1,ub=n;
				while(ub-lb>1)
				{
					int mid=(lb+ub)/2;
					if(b[mid]>=a[i]-exp)
					ub=mid;
					else 
					lb=mid;
				}
				if(ub==n)
				{
					if(exp+b[n-1]<a[i])
					exp+=b[n-1];
					else 
					{
					//	sum+=exp+b[n-1]-a[i];
						exp=a[i];
					}
					b[n-1]=0;
				}
				else 
				{
					if(exp+b[ub]>=a[i])
					{
					//	sum+=exp+b[ub]-a[i];
						exp=a[i];
					}
					b[ub]=0;
				}
				sort(b,b+n);
			
			}
		}
		if(exp==a[3])
		{
			cout<<"YES ";
			for(int i=0;i<n;i++)
			{
				sum+=b[i];
			}
			cout<<sum<<endl;
		}
		else
		{
			cout<<"NO"<<endl;
		}
	}
					
	return 0;
}

