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


int main()
{
	ios::sync_with_stdio(false);
	int t;
	int m,n;
	cin>>t;
	while(t--)
	{
		cin>>m>>n;
		memset(a,0,sizeof(a));
		memset(b,0,sizeof(b));
		memset(vis,0,sizeof(vis));
		for(int i=0;i<m;i++)
		{
			for(int j=0;j<n;j++)
			{
				cin>>a[i][j];
				//if(i==0)b[j]=a[i][j];
			}
		}
		
	
		
			
	
	return 0;
}

