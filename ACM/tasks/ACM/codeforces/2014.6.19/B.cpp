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
char a[1010];
int main()
{
	ios::sync_with_stdio(false);
	int k,ans,flag,minn;
	while(cin>>a>>k)
	{
		ans=0;
		int len=strlen(a);
		if(k>=strlen(a))
		{
			ans=(strlen(a)+k)/2;
			ans=ans*2;
		}
		else 
		{
			for(int j=(strlen(a)+k)/2;j>=k;j--)
			{
				for(int p=0;p+2*j<=len+k;p++)
				{
					flag=1;
					minn=min(len,p+2*j);
					for(int i=p;(i+j)<minn;i++)
					{
						if(a[i+j]!=a[i])
						{
							flag=0;
						}
					}
					if(flag)
					{
						ans=2*j;
						break;
					}
				}
				if(flag)
				{
					ans=2*j;
					break;
				}
			}
		}
		cout<<ans<<endl;
		CLR(a,'\0');
	}
	return 0;
}

