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

int a[110][110];
int main()
{
	//ios::sync_with_stdio(false);
	int n,m;
	while(scanf("%d%d",&n,&m)!=EOF)
	{
		CLR(a,0);
		for(int i=0;i<n;i++)
		{
			for(int j=0;j<m;j++)
			{
				scanf("%d",&a[i][j]);
				a[i][m]+=a[i][j];
			}
			//cout<<a[i][m]<<endl;
		}
		for(int j=0;j<m;j++)
		{
			for(int i=0;i<n;i++)
			{
				a[n][j]+=a[i][j];
			}
		}
		for(int i=0;i<n;i++)
		{
			if(i)printf(" ");
			printf("%.2lf",1.0*a[i][m]/(m*1.0));
		}
		printf("\n");
		for(int j=0;j<m;j++)
		{
			if(j)printf(" ");
			printf("%.2lf",1.0*a[n][j]/(n*1.0));
		}
		printf("\n");
		int num=0;
		bool flag=1;
		for(int i=0;i<n;i++)
		{
			flag=1;
			for(int j=0;j<m;j++)
			{
				if(a[i][j]*n<a[n][j])
				flag=0;
			}
			if(flag)num++;
		}
		printf("%d\n\n",num);
	}
			
			
	return 0;
}


