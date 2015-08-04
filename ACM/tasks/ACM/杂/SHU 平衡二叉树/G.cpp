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
bool scan_d(int &ret){
	char c;int sgn;
	if(c=getchar(),c==EOF)return 0;
	while(c!='-'&&(c<'0'||c>'9'))c=getchar();
	sgn=(c=='-')?-1:1;
	ret=(c=='-')?0:(c-'0');
	while(c=getchar(),c>='0'&&c<='9')
	{
		ret=ret*10+(c-'0');
	}
	ret*=sgn;
	return 1;
}
void out(int x)
{
	if(x>9)out(x/10);
	putchar(x%10+'0');
}
int main()
{
	int n,k,p,z=0;
	map<int,int >m;
	while(scan_d(n)&&n)
	{
		if(n==1)
		{
			scan_d(k);
			scan_d(p);
			m[p]=k;
		}
		if(n==2)
		{
			if(m.empty())
			{
				out(z);
				putchar('\n');
			}
			else 
			{
				out(m.rbegin()->second);
				putchar('\n');
				m.erase(m.rbegin()->first);
			}
		}
		else if(n==3)
		{
			if(m.empty())
			{
				out(z);
				putchar('\n');
			}
			else 
			{
				out(m.begin()->second);
				putchar('\n');
				m.erase(m.begin()->first);
			}
		}
		
	}
		
	return 0;
}


