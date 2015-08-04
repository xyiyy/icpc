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
int dp[110][110];
int s[110][110];
int a[110];
int n;
void trace(int i,int j)
{
	if(i==j)
	{
		cout<<"A"<<i;
		return ;
	}
	else if(i==j-1&&(i!=1||j!=n))
	{
		cout<<"(A"<<i<<"A"<<j<<")";
		return ;
	}
	else if(i==1&&j==n)
	{
		trace(i,s[i][j]);
		trace(s[i][j]+1,j);
	}
	else 
	{
		cout<<"(";
		trace(i,s[i][j]);
		trace(s[i][j]+1,j);
		cout<<")";
	}
}

int main()
{
	ios::sync_with_stdio(false);
	int cas=1;
	while(cin>>n)
	{
		CLR(a,0);
		REP2(i,0,n)cin>>a[i];
		REP2(i,1,n)
		{
			REP2(j,1,n)
			{
				if(i==j)dp[i][j]=0;
				else dp[i][j]=INF;
			}
		}
		for(int len=2;len<=n;len++)
		{
			for(int i=1;i<=n-len+1;i++)
			{
				int j=i+len-1;
				for(int k=i;k<j;k++)
				{
					if(dp[i][j]>dp[i][k]+dp[k+1][j]+a[i-1]*a[k]*a[j])
					{
						dp[i][j]=dp[i][k]+dp[k+1][j]+a[i-1]*a[k]*a[j];
						s[i][j]=k;
					}
				}
			}
		}
		cout<<"Case "<<cas++<<endl;
		cout<<dp[1][n]<<" ";
		trace(1,n);
		cout<<endl;
	}
	return 0;
}


