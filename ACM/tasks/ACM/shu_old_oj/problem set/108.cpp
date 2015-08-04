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
	int n,m;
	int sum1,sum2,i,k=1;
	while(cin>>n>>m)
	{
		cout<<"Case "<<k++<<": "<<n<<", "<<m<<", ";
		sum1=sum2=0;
		for(i=1;i<n;i++)
		{
			if(n%i==0)sum1+=i;
		}
		for(i=1;i<m;i++)
		{
			if(m%i==0)sum2+=i;
		}
		if(sum1==m&&sum2==n)cout<<"Yes"<<endl;
		else cout<<"No"<<endl;
	}
	return 0;
}

