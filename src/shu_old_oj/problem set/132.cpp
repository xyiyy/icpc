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
char a[10010];
int i;
int n;
int num[10010];
int k=1;
int main()
{
	ios::sync_with_stdio(false);
	while(cin.getline(a,10010,'\n'))
	{
		memset(num,0,sizeof(num));
		n=0;
		for(i=0;i<strlen(a);i++)
		{
			if(a[i]>='0'&&a[i]<='9')
			{
				num[n]*=10;
				num[n]+=a[i]-'0';
				if(!(a[i+1]>='0'&&a[i+1]<='9'))
				{
					n++;
				}
			}
		}
		cout<<"Case "<<k++<<": ("<<n<<")";
		for(i=0;i<n;i++)
		{
			cout<<" "<<num[i];
		}
		cout<<endl;
	}
				
				
				
		memset(a,'\0',sizeof(a));		
	return 0;
}

