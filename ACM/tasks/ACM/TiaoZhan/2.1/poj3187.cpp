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
int a[10];
int b[10];
int main()
{
	ios::sync_with_stdio(false);
	int n,sum;
	while(cin>>n>>sum)
	{
		for(int i=0;i<n;i++)
		{
			a[i]=i+1;
		}
		do{
			for(int i=0;i<n;i++)
			{
				b[i]=a[i];
			}
			int m=n;
			while(m--)
			{
				for(int i=0;i<m;i++)
				{
					b[i]=b[i]+b[i+1];
				}
			}
			if(b[0]==sum)break;
		}while(next_permutation(a,a+n));
		for(int i=0;i<n;i++)
		{
			if(i)cout<<" ";
			cout<<a[i];
		}
		cout<<endl;
	}
	return 0;
}


