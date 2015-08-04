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
int a[3];
double b[3];
int main()
{
	ios::sync_with_stdio(false);
//	int a,b,c;
//	double i,j,k;
	double ave;
	while(cin>>a[0]>>a[1]>>a[2])
	{
		for(int i=0;i<3;i++)
		{
			if(a[i]>=90&&a[i]<=100)
			{
				b[i]=4.0;
			}else if(a[i]>=80&&a[i]<=89)b[i]=3.3;
			else if(a[i]>=70&&a[i]<=79)b[i]=2.7;
			else if(a[i]>=60&&a[i]<=69)b[i]=1.5;
			else b[i]=0;
		}
		ave=(b[0]*2.0+b[1]*4.0+b[2]*4.0)/10;
		cout<<fixed<<setprecision(2)<<ave<<endl;
	}

	return 0;
}


