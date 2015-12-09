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
ll a[maxn];
PII p[maxn];
int m,k;

void solve(int goal)
{
	int s=0,t=1;
	int temp;
	int ans;
	int l,r;
	int minn=INF;
	while(s<=m&&t<=m)
	{
		temp=p[t].first-p[s].first;
		if(abs(temp-goal)<minn)	
		{
			minn=abs(temp-goal);
			l=p[s].second;
			r=p[t].second;
			ans=temp;
		}
		if(temp>goal)s++;
		else if(temp<goal)t++;
		else break;
		if(s==t)t++;
	}
	if(l>r)swap(l,r);
	cout<<ans<<" "<<l+1<<" "<<r<<endl;
}
	
int main()
{
	ios::sync_with_stdio(false);
	while(cin>>m>>k&&(m||k))
	{	
		p[0]=MP(0,0);
		int sum=0;
		for(int i=1;i<=m;i++)
		{
			cin>>a[i];
			sum+=a[i];
			p[i]=MP(sum,i);
		}
		sort(p,p+m+1);
		int goal;
		for(int i=0;i<k;i++)
		{
			cin>>goal;
			solve(goal);
		}
	}
	return 0;
}


