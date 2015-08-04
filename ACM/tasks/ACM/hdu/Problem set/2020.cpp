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

int a[10000];
bool cmp(int a,int b)
{
	return fabs(a)>fabs(b);
	//if()
}
int main()
{
	ios::sync_with_stdio(false);
	int n;
	while(cin>>n&&n)
	{
		for(int i=0;i<n;i++)
		{
			cin>>a[i];
		}
		sort(a,a+n,cmp);
		for(int i=0;i<n-1;i++)
		{
			cout<<a[i] <<" ";
		}
		cout<<a[n-1]<<endl;
	}
	return 0;
}

