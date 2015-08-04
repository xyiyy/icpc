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
set<long long>s;
ll a[6000];
int main()
{
	//ios::sync_with_stdio(false);
	s.insert(1);
	long long d;
	set<long long >::IT it=s.find(1);
	//cout<<*it<<endl;
	for(int i=0;i<6000;i++)
	{
		d=*it;
		s.insert(d*2);
		s.insert(d*3);
		s.insert(d*5);
		s.insert(d*7);
		it++;
	}
	it=s.find(1);
	for(int i=1;i<5900;i++)
	{
		a[i]=*it;
		it++;
	}
	int n;
	while(scanf("%d",&n)==1&&n)
	{
		if(n==0)break;
		//it=s.begin();
		printf("The %d",n);
		if(n%10==1&&n%100!=11)printf("st");
		else if(n%10==2&&n%100!=12)printf("nd");
		else if(n%10==3&&n%100!=13)printf("rd");
		else printf("th");
		printf(" humble number is ");
		printf("%I64d.\n",a[n]);
	}
	return 0;
}


