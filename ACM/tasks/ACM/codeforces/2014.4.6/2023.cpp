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
double a[110][110];
double avr[3][2000];
int main()
{
	ios::sync_with_stdio(false);
	int m,n;
	while(cin>>m>>n)
	{
		memset(a,0,sizeof(a));
		memset(avr,0,sizeof(avr));
		for(int i=0;i<m;i++)
		{
			for(int j=0;j<n;j++)
			{
				cin>>a[i][j];
			}
		}
		double  sum=0;
		int num=0;
		for(int i=0;i<m;i++)
		{
			sum=0;
			for(int j=0;j<n;j++)
			{
				sum+=a[i][j];
			}
			avr[1][i]=1.0*sum/(n*1.0);
			
		}
		for(int j=0;j<n;j++)
		{
			sum=0;
			for(int i=0;i<m;i++)
			{
				sum+=a[i][j];
			}
			avr[2][j]=1.0*sum/(m*1.0);
			
		}
		for(int i=0;i<m;i++)
		{
			int flag=1;
			for(int j=0;j<n;j++)
			{
				if(a[i][j]<avr[2][j])flag=0;
			}
			if(flag)num++;
		}
		for(int i=0;i<m-1;i++)
		{
			printf("%.2lf ",avr[1][i]);
		}
		printf("%.2lf\n",avr[1][m-1]);
		for(int i=0;i<n-1;i++)
		{
			printf("%.2lf ",avr[2][i]);
		}
		printf("%.2lf\n",avr[2][n-1]);
		cout<<num<<endl;
		cout<<endl;
	}
	return 0;
}

