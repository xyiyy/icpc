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
int Map[110][110];
int main()
{
	ios::sync_with_stdio(false);
	int n,x,y,l;
	char a[100];
	while(scanf("%d",&n)!=EOF)
	{
		for(int i=0;i<n;i++)
		{
			scanf("%s",a);
			scanf("%d%d%d",&x,&y,&l);
			if(a[0]=='B')
			{
				for(int i=x;i<x+l;i++)
				{
					for(int j=y;j<y+l;j++)
					{
						Map[i][j]=1;
					}
				}
			}
			else if(a[0]=='W')
			{
				for(int i=x;i<x+l;i++)
				{
					for(int j=y;j<y+l;j++)
					{
						Map[i][j]=0;
						//cout<<"ok"<<endl;
					}
				}
			}
			else 
			{
				int count=0;
				for(int i=x;i<x+l;i++)
				{
					for(int j=y;j<y+l;j++)
					{
						if(Map[i][j])count++;
					}
				}
				printf("%d\n",count);
			}
		}
	}
					 
	return 0;
}


