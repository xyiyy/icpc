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
const int maxn=1248;
char a[maxn];
double gao(char *s)
{
	double ret,p,x,y;
	int i=0,j,k;
	if(s[0]!='(')
	{
		sscanf(s,"%lf",&ret);
		return ret;
	}
	sscanf(s+1,"%lf",&p);
	while(s[i++]!=' ');
	if(s[i]!='(')
	{
		sscanf(s+i,"%lf",&x);
		while(s[i++]!=' ');
		if(s[i]!='(')  
			sscanf(s+i,"%lf",&y);
		else  
			y=gao(s+i);
	}
	else
	{
    	k=1;
    	for(j=i+1;k;j++)
    	{
    		if(s[j]=='(')  ++k;
    		if(s[j]==')')  --k;
    	}
    	s[j]='\0';
    	x=gao(s+i);
    	if(s[j+1]=='(') 
			y=gao(s+j+1);
    	else           
	  		sscanf(s+j+1,"%lf",&y);
	}
	return p*(x+y)+(1-p)*(x-y);
}
int main()
{
   while(gets(a))
    {
    	if(strcmp(a,"()")==0)     break;
    	printf("%.2lf\n",gao(a));
    }
    return 0;
}

