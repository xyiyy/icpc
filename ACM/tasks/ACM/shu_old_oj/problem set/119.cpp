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
int a[60][60];
int main()
{
	ios::sync_with_stdio(false);
	int n,k=1;
	int x,y;
	while(cin>>n)
	{
		a[0][n/2]=1;
		x=-1;y=n/2+1;
		for(int i=2;i<n*n+1;i++)
		{
			x=(x+n)%n;y=(y+n)%n;
			a[x][y]=i;
			if(i%n!=0)
			{
				x--;y++;
			}
			else
			{
				x++;
			}
		}
		cout<<"Case "<<k++<<": "<<endl;
		for(int i=0;i<n;i++)
		{
			for(int j=0;j<n;j++)
			{
				cout<<setw(5)<<a[i][j];
			}
			cout<<endl;
		}
	}
	
	return 0;
}

