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
const int M=1000010;
bool prime[M];
void sieve_prime()
{
	memset(prime,true,sizeof(prime));
	prime[0]=prime[1]=false;
	for(int i=2;i<=sqrt((double)M);i++)
	{
		if(prime[i])
		{
			for(int j=i*i;j<M;j+=i)
			{
				prime[j]=false;
			}
		}
	}
}

int main()
{
	ios::sync_with_stdio(false);
	sieve_prime();
	int n;
	while(cin>>n)
	{
		for(int i=2;i<=n;i++)
		{
			if(prime[i])
			cout<<i<<endl;
		}
	}
	
	return 0;
}

