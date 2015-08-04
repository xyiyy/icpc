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

int main()
{
	ios::sync_with_stdio(false);
	int T;
	int n,m;
	ll sum1,sum2;
	ll num;
	cin>>T;
	while(T--)
	{
		sum1=sum2=0;
		cin>>n>>m;
		REP(i,n)
		{
			cin>>num;
			sum1+=num;
		}
		REP(i,m)
		{
			cin>>num;
			sum2+=num;
		}
		if(sum1>sum2)
		{
			cout<<"Calem"<<endl;
		}
		else if(sum1<sum2)
		{
			cout<<"Serena"<<endl;
		}
		else 
		{
			cout<<"Draw"<<endl;
		}
	}
	return 0;
}


