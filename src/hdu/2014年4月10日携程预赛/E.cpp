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

int a[100][100];
unsigned long long aa[100];
int main()
{
	ios::sync_with_stdio(false);
	int N;
	cin>>N;
	unsigned long long  m;
	int n;
	unsigned long long maxx=0;
	while(N--)
	{
		maxx=0;
		memset(a,0,sizeof(a));
		int temp=0;
		cin>>m>>n;
		for(int i=0;i<n;i++)
		{
			a[0][i]=m%2;
			m/=2;
		}
		for(int i=1;i<n;i++)
		{
			temp=a[i-1][0];
			for(int j=0;j<n;j++)
			{
				a[i][j]=a[i-1][j+1];
			}
			a[i][n-1]=temp;
		}
	//	for(int i=0;i<n;i++)
	//	{
	//		for(int j=0;j<n;j++)
	//		{
	//			cout<<a[i][j]<<"  ";
	//		}
	//		cout<<endl;
	//	}
	//	memset(vis,0,sizeof(vis));
	//	for(int i=0;i<n;i++)
	//	{
			//for(int j=0)
		unsigned long long mm,nn;
		int ff=0;
		for(int i=0;i<n;i++)
		{
			nn=0;
			for(int j=0;j<n;j++)
			{
				mm=a[i][j];
				for(int k=0;k<j;k++)
				{
					mm*=2;	
				}
				nn+=mm;
			}
			aa[i]=nn;
		}
		sort(aa,aa+n);
		for(int i=0;i<n;i++)
		cout<<aa[i]%2;

	cout<<endl;
	//cout<<maxx<<endl;
	
				
	}
	return 0;
}

