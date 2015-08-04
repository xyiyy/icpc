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
int q[110];
int w[110];
int vis[110];
int e[110];
int main()
{
	ios::sync_with_stdio(false);
	int n,m;
	while(cin>>n>>m)
	{
		memset(q,0,sizeof(q));
		memset(vis,0,sizeof(vis));
		memset(e,0,sizeof(e));
		for(int i=0;i<n;i++)
		{
			cin>>q[i];
		}
		for(int i=0;i<m;i++)
		{
			cin>>w[i];
			vis[w[i]-1]=1;
		}
	//	int minn=0x7ffffff;
		long long tot=0;
		int num=0;
		for(int i=0;i<n;i++)
		{
			if(!vis[i])
			{
				tot+=q[i];
			}
			else
			{
				e[num++]=q[i];
			}
		}
		sort(e,e+m);
	//	for(int i=0;i<m;i++)
	//	cout<<e[i]<<" ";
	//	cout<<endl;
		for(int i=m-1;i>=0;i--)
		{
			if(tot<e[i])
			{
				tot+=e[i];
				//e[m-1]=e[i];
				
			}
			else
			{
				tot*=2;
			}
		}
		cout<<tot<<endl;
	}
				
			
		
			
			
	return 0;
}

