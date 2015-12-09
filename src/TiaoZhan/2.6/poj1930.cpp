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
int gcd(int x,int y)
{
	if(!x)return y;
	return gcd(y%x,x);
}


int main()
{
	ios::sync_with_stdio(false);
	char s[1100];
	int x,y,z;
	int k,i;
	int tot,part,bef,de,fenz,fenm;
	while(scanf("%s",s)!=EOF&&strcmp(s,"0"))
	{
		fenz=fenm=1000000000;
		int l;
		for(i=2,tot=0,l=0;s[i]!='.';i++)
		{
			tot=tot*10+s[i]-'0';
			l++;
		}
		for(part=tot,k=1,i=1;i<=l;i++)
		{
			part/=10;
			k*=10;
			x=tot-part;
			y=(int)pow(10.0,l-i)*(k-1);
			z=gcd(x,y);
			if(y/z<fenm)
			{
				fenz=x/z;
				fenm=y/z;
			}
		}
		printf("%d/%d\n",fenz,fenm);
	}
	return 0;
}


