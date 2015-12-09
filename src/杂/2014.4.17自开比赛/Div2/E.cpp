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
int w[21],b[21];
int dp[21][5000];

int main()
{
	ios::sync_with_stdio(false);
	int c,g;
	while(cin>>c>>g)
	{
		memset(dp,0,sizeof(dp));
		REP(i,c)cin>>b[i];
		REP(i,g)cin>>w[i];
		REP(i,c)dp[0][1000+w[0]*b[i]]++;
		for(int i=1;i<g;i++)
		{
			for(int j=0;j<c;j++)
			{
				for(int k=1;k<5000;k++)
				{
					dp[i][k+w[i]*b[j]]+=dp[i-1][k];
				}
			}
		}
		cout<<dp[g-1][1000]<<endl;
	}
					
	
	return 0;
}

