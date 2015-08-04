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
	int t;
	cin>>t;
	while(t--)
	{
		int n,m;
		cin>>n>>m;
		int a;
		int sum1=0,sum2=0;
		for(int i=0;i<n-1;i++)
		{
			cin>>a;
			sum1+=a;
		}
		for(int i=0;i<m;i++)
		{
			cin>>a;
			sum2+=a;
		}
		int temp=sum1/(n-1);
		if(temp*(n-1)==sum1)temp--;
		int temp2=sum2/m;
		if(temp2*m<=sum2)temp2++;
		cout<<temp2<<" "<<temp<<endl;
	}
		
	return 0;
}



