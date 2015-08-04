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
const int MAXN=1000010;
int p[MAXN];
char a[MAXN]; 
void get_next()
{
	int j=0;
	p[1]==0;
	int len=strlen(a+1);
	for(int i=2;i<=len;i++)
	{
		while(j&&a[j+1]!=a[i])j=p[j];
		if(a[j+1]==a[i])j++;
		p[i]=j;
	}
}
int ans[MAXN];
int main()
{
	ios::sync_with_stdio(false);
	while(scanf("%s",a+1)!=EOF)
	{
		int len=strlen(a+1);
		get_next();
		int tot=0;
		int tmp=p[len];
		while(tmp)
		{
			ans[tot++]=tmp;
			tmp=p[tmp];
		}
		for(int i=tot-1;i>=0;i--)
		{
			printf("%d ",ans[i]);
		}
		printf("%d\n",len);
	}
	return 0; 
}



