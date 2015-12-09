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
double a[5];
int main()
{
	ios::sync_with_stdio(false);
	double sum1=0,sum2;
	int num;
	while(cin>>a[0])
	{
		//a[0]=fabs(a[0]);
		for(int i=1;i<5;i++)
		{
			cin>>a[i];
			a[i]*=1.0;
			
		}
		sum1=0;
		num=0;
		for(int i=0;i<5;i++)
		{
			if(a[i]<0)num++;
			sum1+=a[i]*1.0;
		}
		sum1/=5.0;
		cout<<sum1<<", ";
		for(int i=0;i<5;i++)
		{
			a[i]=fabs(a[i]);
		}
		sum2=1.0;
		for(int i=0;i<5;i++)
		{
			sum2*=pow(a[i],0.2);
		}
		//if()
		if(num%2==1)sum2=-sum2;
		cout<<sum2<<endl;
	}
	return 0;
}

