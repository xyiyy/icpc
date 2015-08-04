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
const int maxn=100010;
int a[maxn];
int main()
{
	ios::sync_with_stdio(false);
	int n,m;
	while(cin>>n>>m)
	{
		for(int i=0;i<n;i++)
		{
			cin>>a[i];
		}
		int ans=INF;
		int l=0,r=INF;
		while(l<=r)
		{
			int mid=(l+r)/2;
			int maxx=0;
			int num=1,cnt=0;
			for(int i=0;i<n;i++)
			{
				if(cnt+a[i]<=mid)
				{
					cnt+=a[i];
				//	maxx=max(maxx,cnt);
				}
				else
				{
					cnt=a[i];
					//maxx=max(maxx,cnt);
					if(cnt>mid)
					{
						num=INF;
						break;
					}
					num++;
				}
			}
			if(num<=m)
			{
				r=mid-1;
				ans=min(ans,mid);
			}
			else
			{
				l=mid+1;
			}
			
		}
		cout<<ans<<endl;
	}
			
	return 0;
}
