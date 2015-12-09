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
int main()
{
	ios::sync_with_stdio(false);
	int n;
//	int a[10000];
	while(cin>>n)
	{
		long long num=1;
		memset(a,0,sizeof(a));
		for(int i=0;i<n;i++)
		{
			cin>>a[i];
			if(a[i]%2==1)num*=a[i];
		}
		cout<<num<<endl;
	}
	return 0;
}

