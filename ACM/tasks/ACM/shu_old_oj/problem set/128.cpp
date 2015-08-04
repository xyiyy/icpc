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
const int N=100010;
char a[100010];
char b[100010];
int main()
{
	ios::sync_with_stdio(false);
	int i,len,flag=0,j,k=1;
	while(cin.getline(b,N,'\n'))
	{
		cin.getline(a,N,'\n');
		len=strlen(b);
		for(i=0;i<strlen(a);i++)
		{
			if(a[i]==b[0])
			{
				for(j=0;j<len;j++)
				{
					if(a[i+j]!=b[j])break;
				}
				if(j==len)flag=1;
			}
			if(flag)break;
		}
		if(!flag)i=-1;
		cout<<"Case "<<k++<<": "<<i<<endl;
		memset(a,'\0',sizeof(a));
		memset(b,'\0',sizeof(b));
		flag=0;
	}
	return 0;
}

