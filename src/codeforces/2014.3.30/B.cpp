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

char a[1010],b[1010];
int vis[1010],v[1000];



int main()
{
	ios::sync_with_stdio(false);
	while(cin>>a>>b)
	{
	//	cout<<a<<endl;
	//	cout<<b<<endl;
		int n=strlen(a);
		int m=strlen(b);
		int area=0;
		sort(a,a+n);
		sort(b,b+m);
		int flag,found=1;
		memset(vis,0,sizeof(vis));
		memset(v,0,sizeof(v));
		for(int i=0;i<m;i++)
		{
			flag=1;
			
			for(int j=0;j<n;j++)
			{
				if(flag&&a[j]==b[i]){v[i]=1;flag=0;}
				if(a[j]==b[i]&&vis[j]==0)
				{
					vis[j]=1;
					area++;break;
				}
			}
			
		}
		for(int i=0;i<m;i++)
		{
			if(!v[i]){found=0;
			break;
			}
		}
		if(found)
		cout<<area<<endl;
		else cout<<"-1"<<endl;
	}
				


	return 0;
}

