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
char a[60];
char b[60];
int dp[60][60];
int main()
{
	ios::sync_with_stdio(false);
	int T,m,n;
	cin>>T;
	int len1,len2;
	int cas=1;
	while(T--)
	{
		cin>>m>>n;
		CLR(a,0);
		CLR(b,0);
		REP(i,m)
			cin>>a[i];
		REP(i,n)
			cin>>b[i];
		CLR(dp,0);	
		len1=strlen(a);
		len2=strlen(b);
		int flag=0;
		for(int i=0;i<len1;i++)
		{
			if(a[i]==b[0])flag=1;
			dp[i][0]=flag;
		}
		flag=0;
		for(int j=0;j<len2;j++)
		{
			if(b[j]==a[0])flag=1;
			dp[0][j]=flag;
		}
		for(int i=1;i<len1;i++)
		{
			for(int j=1;j<len2;j++)	
			{
				if(a[i]==b[j])dp[i][j]=dp[i-1][j-1]+1;
				else if(a[i]!=b[j])dp[i][j]=max(dp[i-1][j],dp[i][j-1]);
			}
		}
		cout<<"Case "<<cas++<<endl;
		cout<<dp[len1-1][len2-1]<<endl;
	}
	return 0;
}


