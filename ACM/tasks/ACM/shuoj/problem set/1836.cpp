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

int main()
{
	ios::sync_with_stdio(false);
	int a,b,c,m;
	while(cin>>m>>a>>b>>c)
	{
		ll ans=0;
		int temp;
		int temp1;
		int temp2;
		for(int i=1;i<=b&&i*2<=m;i+=2)
		{
			temp=m-i*2;
			if(temp>a+c*5)continue;
			temp1=max(temp-a,0);
			temp1=(temp1+4)/5;
			if(temp1&1)temp1++;
			temp2=min(c,temp/5);
			if(temp2&1)temp2--;
			ans+=(temp2-temp1)/2+1;
		}
		cout<<ans<<endl;
	}
			
		
	return 0;
}



