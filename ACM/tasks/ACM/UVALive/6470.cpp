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
const int maxn=110;
int d[maxn][maxn][maxn];
int col,row;
int dfs(int p,int q,int r)
{
	if(d[p][q][r]==1)return 1;
	else 
	{
		int i,j,k;
		for(i=p;i>=2;i--)
		{
			j=min(i-1,q);
			k=min(j,r);
			if(dfs(i-1,j,k)==0)
			{
				col=i,row=1;
				return d[p][q][r]=1;
			}
		}
		for(j=q;j>=1;j--)
		{
			i=p;
			k=min(j-1,r);
			if(dfs(i,j-1,k)==0)
			{
				col=j;
				row=2;
				return d[p][q][r]=1;
			}
		}
		for(k=r;k>=1;k--)
		{
			i=p;j=q;
			if(dfs(i,j,k-1)==0)
			{
				col=k;
				row=3;
				return d[p][q][r]=1;
			}
		}
		return d[p][q][r]=0;
	}
}
			
		
		 
int main()
{
	ios::sync_with_stdio(false);
	int t,cas;
	cin>>t;
	int p,q,r;
	CLR(d,-1);
	d[1][0][0]=0;
	d[1][1][0]=d[2][0][0]=1;
	while(t--)
	{
		cin>>cas>>p>>q>>r;
		d[p][q][r]=-1;
		int ans=dfs(p,q,r);
		if(ans)
		{
			cout<<cas<<" W "<<col<<" "<<row<<endl;
		}
		else cout<<cas<<" L"<<endl;
	}
	return 0;
}


