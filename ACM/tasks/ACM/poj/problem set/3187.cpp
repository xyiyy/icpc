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
int n,sum;
int a[11];
int b[11][2];
bool check()
{
//	queue<int >q;
	int t=n;
	for(int i=0;i<n;i++)
	{
		b[i][0]=a[i];
	}
	int cur=0;
	while(t--)
	{
		for(int i=0;i<t;i++)
		{
			b[i][1-cur]=b[i][cur]+b[i+1][cur];
		}
		cur=1-cur;
	}
	if(b[0][1-cur]==sum)return true;
	return false;
}

int main()
{
	ios::sync_with_stdio(false);
	while(cin>>n>>sum)
	{
		for(int i=0;i<n;i++)
		{
			a[i]=i+1;
		}
		do{
			if(check())break;
		}while(next_permutation(a,a+n));
		for(int i=0;i<n;i++)
		{
			if(i!=0)cout<<" ";
			cout<<a[i];
		}
		cout<<endl;
	}
		
		
	return 0;
}


