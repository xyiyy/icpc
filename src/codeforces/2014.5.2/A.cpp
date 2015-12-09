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

//int a[10010],b[10010]; 
int main()
{
	ios::sync_with_stdio(false);
	int n;
	while(cin>>n)
	{
		int n1=0,n2=0;
		int a;
		int sum=0;
		for(int i=0;i<n;i++)
		{
			cin>>a;
			if(a>0)
			{
				n1+=a;
			}
			if(a<0)
			{
				a=-a;
				if(n1==0)
				{
					sum+=a;
				}
				else if(n1<a&&n1>0)
				{
					sum+=a-n1;
					n1=0;
				}
				else 
				{
					n1-=a;
				}
			}
		}
		cout<<sum<<endl;
	}
	return 0;
}

