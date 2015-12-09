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
int a[10010];
double b[10010];
double dp[10010];
int main()
{
	ios::sync_with_stdio(false);
	int n,m;
	while(cin>>n>>m&&(n||m))
	{
		for(int i=0;i<10010;i++)
		{
			dp[i]=1;
		}
		 for(int i=0;i<m;i++)
		 {
		 	cin>>a[i]>>b[i];
		 }
		 for(int i=0;i<m;i++)
		 {
		 	for(int j=n;j>=a[i];j--)
		 	{
		 		dp[j]=min(dp[j],dp[j-a[i]]*(1-b[i]));
		 	}
		 }
		 cout<<fixed<<setprecision(1)<<100-dp[n]*100<<"%"<<endl;
	}
	
	
	return 0;
}

