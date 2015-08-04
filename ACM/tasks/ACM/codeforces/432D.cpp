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
#define MAXN 100010
char s[MAXN];
int p[MAXN];
int dp[MAXN];
int vis[MAXN];
void getp()
{
	p[1]=0;
	int len=strlen(s+1);
	for(int i=2,j=0;i<=len;i++)
	{
		while(j>0&&s[j+1]!=s[i])j=p[j];
		if(s[j+1]==s[i])j+=1;
		p[i]=j;
	}
}


int main()
{
	ios::sync_with_stdio(false);
	while(cin>>s+1)
	{
		int len=strlen(s+1);
		getp();
		for(int i=1;i<=len;i++)
		{
			cout<<p[i]<<" ";
		}
		cout<<endl;
		for(int i=1;i<=len;i++)
		{
			dp[i]=1;
		}
		int i=len;
		int k=0;
		while(i)
		{
			vis[k]=i;
			k++;
			i=p[i];
		}
		for(i=len;i>0;i--)
		{
			dp[p[i]]+=dp[i];
		}
		cout<<k<<endl;
		for(i=k-1;i>=0;i--)
		{
			cout<<vis[i]<<" "<<dp[vis[i]]<<endl;
		}
	}
	return 0;
}



