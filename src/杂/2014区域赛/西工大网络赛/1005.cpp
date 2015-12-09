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
//map<int,int>m;
int main()
{
	ios::sync_with_stdio(false);
	int n;
	int cas=1;
	while(scanf("%d",&n)!=EOF)
	{
		int a;
	//	m.clear();
		int num1=0,num2=0,num3=0,num4=0,num5=0;
		for(int i=0;i<n;i++)
		{
			scanf("%d",&a);
			//if(!m.count(a))m[a]=1;
			//else m[a]++;
		//	if(a==1)num1++;
		//	else if(a==2)num2++;
		//	else num3++;
		//	else if(a==4)num4++;
		//	else num5++;
		}
	//	int sum=num1+3*num2+5*num3;//+15*num4+9*num5;
		int flag=0;
		if(n==1)flag=1;
		
	//	map<int,int>::IT it=m.begin();
	//	while(it!=m.end())
	//	{
	//		if((it->second)%2&&(it->second)>1)flag=1;
	//		it++;
	//	}
	//	if(sum%2)flag=1;
		if(flag)printf("Win\n");
		else printf("Lose\n");
		cas++;
	}
		
		
	return 0;
}



