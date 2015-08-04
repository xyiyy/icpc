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
int n;
const int maxn=5010;
int dir[5010],f[5010];
int fun(int k)
{
	//cout<<"ok"<<endl;
	CLR(f,0);
	int res=0;
	int sum=0;
	for(int i=0;i+k<=n;i++)
	{
		if((dir[i]+sum)%2!=0)
		{
			res++;
			f[i]=1;
			//cout<<res<<endl;
		}
		sum+=f[i];
		if(i-k+1>=0)
		{
			sum-=f[i-k+1];
		}
	}
	for(int i=n-k+1;i<n;i++)
	{
		if((dir[i]+sum)%2!=0)
		{
			return -1;
		}
		if(i-k+1>=0)
		{
			sum-=f[i-k+1];
		}
	}
	return res;
}
	
int main()
{
	ios::sync_with_stdio(false);
//	int n;
	char a[10];
	while(cin>>n)
	{
		for(int i=0;i<n;i++)
		{
			cin>>a;
			if(a[0]=='F')
			{
				dir[i]=0;
			}
			else 
			{
				dir[i]=1;
			}
			//cout<<dir[i]<<endl;	
		}
		int ans=1,m=n;
		for(int i=1;i<=n;i++)
		{
			int ret=fun(i);
			if(ret>=0&&m>ret)
			{
				m=ret;
				ans=i;
			}
		}
		cout<<ans<<" "<<m<<endl;
	}
		
		
	return 0;
}


