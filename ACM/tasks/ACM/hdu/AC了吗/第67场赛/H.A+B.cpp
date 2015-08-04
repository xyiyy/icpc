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

long long a,b,maxx,minn;
/*bool dfs(int s)
{
	
	//while(s>a*b)s-=a*b;
	if(s<a&&s<b)return false;
	if(s%b==0||s%a==0)return true;
//	if(s==a||s==b)return true;
	if(dfs(s-a))return true;
//	if(dfs(s-b))return true;
	return false;
}
*/
long long gcd(long long x,long long y)
{
//	long long temp=x;
//	temp=x%y;
	if(!x%y) return y;
	return gcd(y,x%y);
}
bool dfs();

int main()
{
	ios::sync_with_stdio(false);
	long long s;
	
	//cout<<gcd(9,6);
	//cin>>s;
	while(cin>>a>>b>>s)
	{
		maxx=(a,b);
		minn=min(a,b);
		cout<<gcd(maxx,minn);
		//cout<<gcd()
		//c=a*b;
	//	if(dfs(s))cout<<"YES"<<endl;
	//	else cout<<"NO"<<endl;
	}
	
	return 0;
}

