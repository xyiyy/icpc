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
char a[100100],b[100100];
int main()
{
	ios::sync_with_stdio(false);
	int len1,len2;
	int i,j,flag=0;
	while(cin>>a>>b)
	{
		j=0;
		flag=0;
		len1=strlen(a);
		len2=strlen(b);
		for(i=0;i<len1;i++)
		{
			while(1)
			{
				if(j==len2)
				{
					flag=1;
					break;
				}
				else if(a[i]==b[j])
				{
					j++;
					break;
				}
				j++;
			}
		}
		if(flag)cout<<"No"<<endl;
		else cout<<"Yes"<<endl;
	}
		
	return 0;
}


