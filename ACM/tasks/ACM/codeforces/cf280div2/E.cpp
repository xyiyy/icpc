//gaoshenbaoyou  ------ pass system test
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
const int maxn=1000010;
int num[maxn];
int d[maxn];
int main()
{
	ios::sync_with_stdio(false);
	int n,m,dx,dy;
	cin>>n>>m>>dx>>dy;
	int y=0;
	for(int i=0;i<n;i++)
	{
		d[y]=i;
		y+=dy;
		y%=n;
	}
	long long tx,ty;
	int ansx,ans=0;
	for(int i=0;i<m;i++)
	{
		cin>>tx>>ty;
		long long t=d[ty];
		t=(tx+(n-t)*dx)%n;
		num[t]++; 
		if(num[t]>ans)
		{
			ans=num[t];
			ansx=t;
		}
	}
	cout<<ansx<<" "<<0<<endl;
	return 0;
}



