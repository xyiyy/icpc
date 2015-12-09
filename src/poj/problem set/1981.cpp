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
double a[400],b[400];

int main()
{
	ios::sync_with_stdio(false);
	int N;
	while(cin>>N&&N)
	{
		int num=0;
		int maxx=0;
		//memset(a,0,sizeof(a));
		for(int i=0;i<N;i++)
		{
			cin>>a[i];
			cin>>b[i];
		}
		for(double i=0.7;i<=9.3;i+=0.01)
		{
			for(double j=0.7;i<=9.3;i+=0.01)
			{
				num=0;
				for(int k=0;k<N;k++)
				{
					if((a[k]-i)*(a[k]-i)+(b[k]-j)*(b[k]-j)<=1)
						num++;
					if(num>maxx)
					maxx=num;
				}
			}
		}
		cout<<maxx<<endl;
	}
			
	return 0;
}

