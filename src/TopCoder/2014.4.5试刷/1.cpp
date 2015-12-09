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

int a[2000];
int main()
{
	ios::sync_with_stdio(false);
	int n;
	while(cin>>n)
	{
	for(int i=0;i<n;i++)
	{
	cin>>a[i];
	}
	sort(a,a+n);
//	int sum=0;
	int maxx=0,minn=0x7fffff;
	for(int i=0;i<n/2;i++)
	{
	//sum+=a[i]+a[n-1-i];
	if(a[i]+a[n-1-i]>maxx)maxx=a[i]+a[n-1-i];
	if(a[i]+a[n-1-i]<minn)minn=a[i]+a[n-1-i];
	}
	cout<<maxx-minn<<endl;
	//cout<<maxx*n/2-sum<<endl;
	}
	
	
	return 0;
}

