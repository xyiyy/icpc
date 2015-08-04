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
	long long n;
	while(cin>>n)
	{
		if(n<3)
		{
			cout<<"0"<<endl;
		}
		else if(n==3)
		{
			cout<<"1"<<endl;
		}
		else if(n&1)
		{
			cout<<(n/2)*(n/2+1)*n/6<<endl;
		}
		else 
		{
			cout<<(n/2-2)*(n/2-1)*n/6<<endl;	
		}
		
	}
		
	return 0;
}

