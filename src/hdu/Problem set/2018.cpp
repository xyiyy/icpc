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

int a[4];
int main()
{
	ios::sync_with_stdio(false);
	int n;
	while(cin>>n&&n)
	{
		int temp,sum=0;
		memset(a,0,sizeof(a));
		a[3]=1;
		for(int i=1;i<n;i++)
		{
			temp=a[3];
			a[3]+=a[2];
			a[2]=a[1];
			a[1]=a[0];
			a[0]=a[3];
		}
		for(int i=0;i<4;i++)
		{
			sum+=a[i];
		}
		cout<<sum<<endl;
	}
			
	return 0;
}

