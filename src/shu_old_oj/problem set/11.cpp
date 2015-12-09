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

int main()
{
	ios::sync_with_stdio(false);
	int n,i,sum,ans,d;
	while(cin>>n)
	{
		if(n<1||n>50)cout<<"invalid input!"<<endl;
		else if(n>4)
		{
			sum=0;ans=1;
			for(i=2;;i++)
			{
				sum+=i;
				d=sum-n;
				if(d>0)break;
			}
			if(d==1)
			{
				for(int j=3;j<i;j++)
				{
					cout<<j<<" ";ans*=j;
				}
				cout<<++i<<" ";
				ans*=i;
			}
			else
			{
				for(int j=2;j<=i;j++)
				{
					if(j!=d)
					{
						cout<<j<<" ";
						ans*=j;
					}
				}
			}
			cout<<"max="<<ans<<endl;
		}
		else 
		{
			cout<<n<<" max="<<n<<endl;
		}
	}
		
	return 0;
}


