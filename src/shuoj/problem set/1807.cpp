//gaoshenbaoyou  ------ pass system test
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

bool is_leapyear(int y)  
{  
    if(y%4==0&&y%100!=0||y%400==0)  
    return 1;  
    else return 0;  
}  
int main()
{
	ios::sync_with_stdio(false);
	int t;
	cin>>t;
	while(t--)
	{
		int y,m,d;
		char a;
		ll sum=0;
		cin>>y>>a>>m>>a>>d;
		if(m==2&&d==29)cout<<-1<<endl;
		else 
		{
			if(m>=3)
			{
				for(int i=1;i<=18;i++)
				{
					if(is_leapyear(y+i))sum+=366;
					else sum+=365;
				}
			}
			else 
			{
				for(int i=0;i<18;i++)
				{
					if(is_leapyear(y+i))sum+=366;
					else sum+=365;
				}
			}
			cout<<sum<<endl;
		}
	}
	return 0;
}



