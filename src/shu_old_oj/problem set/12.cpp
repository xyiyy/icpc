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

int a[300][300];
int main()
{
	ios::sync_with_stdio(false);
	int m;
	int cas=1; 
	while(cin>>m&&m)
	{
		CLR(a,0);
		if(cas!=1)cout<<endl;
		cout<<"Case "<<cas++<<":"<<endl;
		for(int i=1;i<=m;i++)
		{
			for(int j=i-1;j>=0;j--)
			{
				cin>>a[i][m-j];
			}
		}
		for(int i=0;i<m;i++)
		{
			for(int j=0;j<=i;j++)
			{
				cout<<a[m-(i-j)][m-j];
				if(i-j!=0)cout<<" ";
			}
			cout<<endl;
		}
	//	cout<<endl;
	}
	return 0;
}


