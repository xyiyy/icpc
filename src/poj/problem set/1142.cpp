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
int sum(int n)
{
	int ret=0;
	while(n)
	{
		ret+=n%10;
		n/=10;
	}
	return ret;
}

bool isprime(int n)
{
	for(int i=2;i*i<=n;i++)
	{
		if(n%i==0)return false;
	}
	return true;
}

bool check(int n)
{
	int number=n;
	int x=sum(n); 
	int y=0;
	for(int i=2;i*i<=n;i++)
	{
		 if(n%i==0)
		 {
		 	
		 		while(n%i==0)
		 		{
		 			y+=sum(i);
		 			n/=i;
		 		}
		 	
		 }
	}
	if(!isprime(n)&&n>1)return false;
	if(n>1)
	y+=sum(n);
	if(x==y&&number!=n)
	{
//		cout<<x<<endl;
		return true;
	}
	else return false;
}

int main()
{
	ios::sync_with_stdio(false);
	int n;
	while(cin>>n&&n)
	{
		int i;
		for(i=n+1;;i++)
		{
			if(isprime(i))continue;
		//	cout<<i<<endl;
			if(check(i))
			break;
		}
		cout<<i<<endl;
	}
	
	return 0;
}

