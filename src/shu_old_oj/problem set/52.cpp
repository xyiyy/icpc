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
int a[100][100];
int main()
{
	ios::sync_with_stdio(false);
	int n,k=1;
	while(cin>>n)
	{
		for(int i=0;i<n;i++)
		{
			for(int j=0;j<n;j++)
			{
				a[i][j]=min(min(i+1,n-i),min(j+1,n-j));
			}
		}
		cout<<"Case "<<k++<<": n="<<n<<endl;
		for(int i=0;i<n;i++)
		{
			for(int j=0;j<n;j++)
			{
				if(j)cout<<" ";
				cout<<a[i][j];
			}
			cout<<endl;
		}
		cout<<endl;
	}
	return 0;
}

