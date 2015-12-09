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
ll a[80][4];
int main()
{
	ios::sync_with_stdio(false);
	memset(a,0,sizeof(a));
	for(int i=0;i<4;i++)
	{
		a[i][i]=1;
	}
	for(int i=4;i<80;i++)
	{
		a[i][0]=a[i-1][3];
		a[i][1]=a[i-1][0];
		a[i][2]=a[i-1][1];
		a[i][3]=a[i-1][3]+a[i-1][2];
	}
	int n,k=1;
	while(cin>>n)
	{
		cout<<"Case "<<k++<<": "<<n<<", "<<a[n-1][0]+a[n-1][1]+a[n-1][2]+a[n-1][3]<<endl;
	}
	return 0;
}

