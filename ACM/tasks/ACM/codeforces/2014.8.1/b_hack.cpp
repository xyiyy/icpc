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
const int N=110000;
int a[N];
int sum[N],temp[N];
int main()
{
	ios::sync_with_stdio(false);
	int n;
	while(cin>>n)
	{
		CLR(sum,0);
		a[0]=-1;
		int m=1;
		for(int i=1;i<=n;i++)
		{
			cin>>a[m];
			if(a[m]!=a[m-1])
			{
				sum[m]=1;
				m++;
			}
			else sum[m-1]++;
		}
		m=m-1;
		int minn=100010;
		int pos;
		for(int i=m;i>=1;i--)
		{
			if(a[i]<minn)
			{
				minn=a[i];
				pos=i;
			}
		}
		int ans=0;
		for(int i=pos;i<=m;i++)
		{
			ans+=sum[i];
		}
		if(pos==1)
		{
			ans=0;
		}
		int pt;
		for(int i=pos,j=1;i<=m;i++,j++)
		{
			temp[j]=a[i];
			pt=j;
		}
		for(int i=1,j=pt+1;i<=pos;i++,j++)
		{
			temp[j]=a[i];
		}
		bool ch=1;
		temp[0]=-1;
		for(int i=1;i<=m;i++)
		{
			if(temp[i]<temp[i-1])
			{
				ch=0;
				break;
			}
		}
		if(ch)cout<<ans<<endl;
		else cout<<-1<<endl;
	}
	return 0;
}


