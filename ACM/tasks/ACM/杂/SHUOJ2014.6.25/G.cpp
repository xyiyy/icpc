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
char a[1010],b[1010];
int p[1010],q[1010];
int ans[1010];
int main()
{
	ios::sync_with_stdio(false);
	CLR(a,'\0');
	CLR(b,'\0');
	CLR(ans,0);
	CLR(q,0);
	CLR(p,0);
	int i,j,c,s;
	while(cin>>a>>b)
	{
		j=0;
		int len=strlen(a);
		for(i=len-1;i>=0;i--)
		{
			p[j]=a[i]-'0';
			j++;
		}
		len=strlen(b);
		j=0;
		for(i=len-1;i>=0;i--)
		{
			q[j]=b[i]-'0';
			j++;
		}
		c=0;
		for(i=0;i<1010;i++)
		{
			s=p[i]+q[i]+c;
			ans[i]=s%8;
			c=s/8;
		}
		cout<<a<<"+"<<b<<"=";
		for(i=1000;i>0;i--)
		{
			if(ans[i])break;
		}
		for(j=i;j>=0;j--)
		{
			cout<<ans[j];
		}
		cout<<endl;
		CLR(a,'\0');
		CLR(b,'\0');
		CLR(ans,0);
		CLR(q,0);
		CLR(p,0);
	}

	return 0;
}


