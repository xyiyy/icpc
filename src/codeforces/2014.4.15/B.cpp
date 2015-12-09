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
int a[110][110];
int b[110];

int main()
{
	ios::sync_with_stdio(false);
//	freopen("B.in","r",stdin);
	int m,n,k;
	while(cin>>m>>n>>k)
	{
		memset(b,0,sizeof(b));
		for(int i=0;i<m;i++)
		{
			for(int j=0;j<n;j++)
			{
				cin>>a[i][j];
			}
		}
		int num=0,nn;
		for(int j=0;j<n;j++)
		{
			nn=0;
			for(int i=0;i<m;i++)
			{
				nn+=a[i][j];
				if(nn>k)continue;
				else
				{
					if(num+a[i][j]<=k)
					{
						num+=a[i][j];
						b[i]+=a[i][j];
					}
					else if(num<k&&num+a[i][j]>k)
					{
						
						b[i]+=k-num;
						num=k;
					}
					else continue;
				}
			}
		}
		for(int i=0;i<m;i++)
		{
			cout<<b[i]<<endl;
		}
	}
					
					
	return 0;
}

