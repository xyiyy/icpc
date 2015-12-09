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
double dfs(ll temp1,ll temp2,int times)
{
	//cout<<times<<endl;
	if(temp2==0||times>=25)return times;
	ll temp=temp2;
	return (dfs(max(temp1-temp2,temp2*2),min(temp1-temp2,temp2*2),times+1)*0.5+dfs(temp1+temp,0,times+1)*0.5);
}
int main()
{
	ios::sync_with_stdio(false);
	int T;
	ll a,b,temp1,temp2;
	cin>>T;
	int times;
	int cas=1;
	double ans;
	while(T--)
	{
		cin>>a>>b;
		times=0;
		temp1=max(a,b);
		temp2=min(a,b);
		ans=dfs(temp1,temp2,times);
		cout<<"Case "<<cas++<<": "<<fixed<<setprecision(6)<<ans<<" "<<(1.0)*(a*1.0/(a+b))<<endl; 
	}
	return 0;
}


