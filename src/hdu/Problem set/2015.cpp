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
void init()
{
	for(int i=0;i<10000;i++)
	{
		a[i]=2*(i+1);
	}
	return ;
}
int main()
{
	ios::sync_with_stdio(false);
	int aa,b,sum;
	init();
	while(cin>>aa>>b)
	{
		sum=0;
		for(int i=0;i<aa;i++)
		{
			sum+=a[i];
			if((i+1)%b==0)
			{
				if(i+1!=aa)
				cout<<sum/b<<" ";
				else cout<<sum/b<<endl;
				sum=0;
			}
			else if(i+1==aa)
			{
				cout<<sum/(aa%b)<<endl;
				sum=0;
			}
		}
	}
	return 0;
}

