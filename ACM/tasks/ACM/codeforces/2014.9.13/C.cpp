//gaoshenbaoyou  ------ pass system test
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
ll a[500010];
ll b[500010];
ll c[500010];
ll d[500010];
int main()
{
	ios::sync_with_stdio(false);
	int n;
	while(cin>>n) 
	{
		ll sum=0;
		for(int i=0;i<n;i++)
		{
			cin>>a[i];
			sum+=a[i];
			b[i]=sum;
		}
		ll key=sum/3;
		if(key*3!=sum)
		{
			cout<<0<<endl;
			return 0;
		}
		ll ans=0,num=0;
		for(int i=0;i<n;i++)
		{
			c[i+1]=sum-b[i];
			if(b[i]==key)
			{
				num++;
				d[i]=num;
			}
		}
		if(b[n-1]==key)num--;
		for(int i=n-1;i>1;i--)
		{
			if(b[i-1]==key)
			{
				num--;
			}
			if(c[i]==key)
			{
				ans+=num;
			}
		}
		cout<<ans<<endl;
				
		
	}
	return 0;
}



