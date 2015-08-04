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
int a;

int main()
{
	ios::sync_with_stdio(false);
	int n,t,c;
	int sum=0;
	int num=0;
	while(cin>>n>>t>>c)
	{
		sum=0;num=0;
		for(int i=0;i<n;i++)
		{
			cin>>a;
			if(a<=t)
			{
				num++;
			}
			if(a>t)
			{
				if(num>=c)
				sum+=num-c+1;
				num=0;
			}
		}
		if(num>=c)
		{
			sum+=num-c+1;
		}
		cout<<sum<<endl;
	}
		

	return 0;
}

