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
int a[3010];
int b[3010];
int id[3010];
int c[3010];

int main()
{
	ios::sync_with_stdio(false);
	int n,v;
	while(cin>>n>>v)
	{
		memset(a,0,sizeof(a));
		memset(b,0,sizeof(b));
		memset(c,0,sizeof(c));
		for(int i=0;i<n;i++)
		{
			cin>>a[i]>>b[i];
			c[a[i]]=c[a[i]]+b[i];
		}
		int sum=0;
		for(int i=1;i<3005;i++)
		{
			if(c[i]+c[i-1]<v)
			{
				sum+=c[i]+c[i-1];
				c[i]=c[i-1]=0;
			}
			if(c[i-1]+c[i]>=v)
			{
				sum+=v;
				if(c[i-1]>v)
				{
					c[i-1]-=v;
				}
				else 
				{
					c[i]=c[i]-(v-c[i-1]);
				}
			}
			
		}
		cout<<sum<<endl;
	}
	
			
			
			
	return 0;
}

