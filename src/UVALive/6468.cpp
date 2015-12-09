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
int a[1000010];
int main()
{
	ios::sync_with_stdio(false);
	int t,cas,m,ans;
	cin>>t;
	while(t--)
	{
		cin>>cas>>m;
		a[1]=a[2]=1;
		for(int i=3;i<1000010;i++)
		{
			a[i]=(a[i-1]+a[i-2])%m;
			if(a[i]==a[2]&&a[i-1]==a[1])
			{
				ans=i-2;
				break;
			}
		}
		cout<<cas<<" "<<ans<<endl;
	}
	return 0;
}


