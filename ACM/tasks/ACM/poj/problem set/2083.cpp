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
char  a[729][729];
int num[7];
int main()
{
	ios::sync_with_stdio(false);
	int n;
	num[0]=1;
	for(int i=1;i<7;i++)num[i]=num[i-1]*3;
	a[0][0]='X';
	for(int wid=1;wid<700;wid*=3)
	{
		for(int i=0;i<wid;i++)
		{
			for(int j=0;j<wid;j++)
			{
				a[i+wid*2][j]=a[i][j];
				a[i+wid][j+wid]=a[i][j];
				a[i][j+wid*2]=a[i][j];
				a[i+wid*2][j+wid*2]=a[i][j];
			}
		}
	}
	for(int i=0;i<729;i++)
	{
		for(int j=0;j<729;j++)
		{
			if(a[i][j]!='X')a[i][j]=' ';
		}
	}
	while(cin>>n&&n!=-1)
	{
		for(int i=0;i<num[n-1];i++)
		{
			for(int j=0;j<num[n-1];j++)
			{
				cout<<a[i][j];
			}
			cout<<endl;
		}
		cout<<'-'<<endl;
	}
	return 0;
}


