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
using namespace std;
#define XINF INT_MAX
#define INF 0x3FFFFFFF
#define MP(X,Y) make_pair(X,Y)
#define PB(X) push_back(X)
#define REP(X,N) for(int X=0;X<N;X++)
typedef pair<int,int> PII;
typedef vector<int> VI;
typedef long long ll;
ll b[100010];

int main()
{
	ios::sync_with_stdio(false);
	int T;
	ll n,p;
	int k=1;
	cin>>T;
	while(T--)
	{
		cin>>n>>p;
		memset(b,0,sizeof(b));
		cout<<"Case #"<<k++<<": ";
		ll a=0;
		if(p==1)cout<<n<<endl;
		else {
			b[0]=1;
			for(int i=1;i<n;i++)
				b[i]=(b[i-1]*p)%1000000007;	
			for(int i=0;i<n;i++)
				a=(a+b[i])%	1000000007;	
			a=(a*p)%1000000007;	
			cout<<a<<endl;
		}
		
		
	}
	return 0;
}

