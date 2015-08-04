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


int main()
{
	ios::sync_with_stdio(false);
	int n,k;
	while(cin>>n>>k)
	{
		//if(2*k>n)flag=0;
		if(2*k<=n-1)
		{
			int t=1;
			int num=0;
			cout<<k*n<<endl;
			for(int j=1;j<=k;j++)
			{
				for(int i=1;i<=n;i++)
				{
					if(i+j<=n)
					cout<<i<<" "<<i+j<<endl;
					else if(i+j>n)
					cout<<i<<" "<<i+j-n<<endl;
				}
			}
				
		}
		else cout<<"-1"<<endl;
	}
			
			
			
	return 0;
}

