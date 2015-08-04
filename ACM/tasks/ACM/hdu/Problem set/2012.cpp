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

int f(int x)
{
	return x*x+x+41;
}
bool is_primenum(int x)
{
	double temp=sqrt((double)x);
	for(int i=2;i<=temp+1;i++)
	{
		if(x%i==0)return false;
	}
	return true;
}

int main()
{
	ios::sync_with_stdio(false);
	int x,y;
	while(cin>>x>>y&&(x||y))
	{
		int flag=0;
		for(int i=x;i<=y;i++)
		{
			//cout<<f(i)<<"   "<<is_primenum(f(i))<<endl;
			if(!is_primenum(f(i)))
			{
				flag=1;
				break;
			}
		}
		if(flag)cout<<"Sorry"<<endl;
		else cout<<"OK"<<endl;
	}
	
	return 0;
}

