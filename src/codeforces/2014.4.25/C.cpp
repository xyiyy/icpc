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
long long  p[1000010];
long long dp[1000010];


int main()
{
	ios::sync_with_stdio(false);
	int n;
//	cout<<(3^3)<<endl;
	while(cin>>n)
	{
	int q=0;
	int x;
	memset(dp,0,sizeof(dp));
		for(int i=0;i<n;i++)
		{
		//	cin>>x;
		//	p[i]=x;
		cout<<endl;
			for(int j=0;j<n;j++)
			{
		//		p[i]=p[i]^((i+1)%(j+1));
				dp[i]=dp[i]^((i+1)%(j+1));
			}
	//		cout<<p[i]<<endl;
			cout<<dp[i]<<"  ";
			q=q^dp[i];
		}
		cout<<q<<endl;
		
	/*	int q=0;
		for(int i=0;i<n;i++)
		{
			cin>>p[i];
			p[i]=p[i]^dp[i];
			q=q^p[i];
		}*/
		
		//cout<<q<<endl;
	//	cout<<num<<endl;
	}
			
		
	return 0;
}

