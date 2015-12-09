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
int a[20][20];
int main()
{
	ios::sync_with_stdio(false);
	int T;
	int n;
	int maxx=0;
	int idmax=0;
	bool flag,mark;
	cin>>T;
	while(T--)
	{
		flag=0;
		CLR(a,0);
		cin>>n;
		REP(i,n)
			REP(j,n)
				cin>>a[i][j];
		
		REP(i,n)
		{	
			maxx=-1;
			idmax=0;
			REP(j,n)
			{
				if(maxx<a[i][j])
				{
					idmax=j;
					maxx=a[i][j];
				}	
			}
			mark=0;
			REP(j,n)
			{
				if(a[j][idmax]<maxx)
				{
					mark=1;
				}
			}
			if(!mark)flag=1;
		}
		if(flag)cout<<"YES"<<endl;
		else cout<<"NO"<<endl;
	}
	return 0;
}


