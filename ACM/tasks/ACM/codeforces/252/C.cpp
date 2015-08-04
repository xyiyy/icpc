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
int a[310*310];
int b[310*310];


int main()
{
	ios::sync_with_stdio(false);
	int n,m,k;
	while(cin>>n>>m>>k)
	{
		memset(a,0,sizeof(a));
		memset(b,0,sizeof(b));
		for(int i=0;i<n;i++)
		{
			for(int j=0;j<m;j++)
			{
				a[i*m+j]=i+1;
				if(i%2==0)b[i*m+j]=j+1;
				else b[i*m+j]=m-j;
			}
		}
		int i,j;
		for(i=0;i<k-1;i++)
		{
			cout<<2<<" ";
			for(j=0;j<2;j++)
			{
				cout<<a[i*2+j]<<" "<<b[i*2+j]<<" ";
			}
			cout<<endl;
		}
		int mm=i*2;
		cout<<m*n-2*(k-1)<<" ";
		for(;mm<n*m;mm++)
		{
			cout<<a[mm]<<" "<<b[mm]<<" ";
		}
		cout<<endl;
	}
			
	return 0;
}

