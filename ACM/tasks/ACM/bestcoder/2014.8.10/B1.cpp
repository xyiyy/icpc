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
double a[110];
double b[110];
int main()
{
	ios::sync_with_stdio(false);
	int t;
	cin>>t;
	while(t--)
	{
		int n;
		cin>>n;
		for(int i=0;i<n;i++)
		{
			cin>>a[i];
		}
		sort(a,a+n);
		double len;
		bool flag=1;
		double left=0,right=2000000000;
		for(int i=0;i<110;i++)
		{
			double len=(left+right)/2;
			double l=a[0];
			flag=1;
			for(int j=1;j<n-1;j++)
			{
				if(fabs(a[j-1]+len-a[j])<1e-8)continue;
				if(a[j]-len-l<=-1e-8||a[j]+len-a[j+1]>=1e-8)
				{
					flag=0;
					break;
				}
				if(a[j]-len-l>=-1e-8)
				{
					l=a[j];
				}
				else
				{
					l=a[j]+len;
				}
			}
			if(flag)
			{
				left=len;
			}
			else
			{
				right=len;
			}
		}
		cout<<fixed<<setprecision(3)<<left<<endl;
	}
			
				
	return 0;
}


