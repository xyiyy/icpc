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

int a,b,c;
bool gan,xi;
string name;
int m;
int main()
{
	ios::sync_with_stdio(false);
	freopen("1.in","r",stdin);
	freopen("1.out","w",stdout);
	int n;
	cin>>n;
	
		char f;
		string ansname;
		int maxx=0;
		int tot=0;
		for(int i=0;i<n;i++)
		{
			m=0;
			cin>>name;
			cin>>a>>b;
			if(a>85&&b>80)m+=4000;
			if(a>90)m+=2000;			
			cin>>f;
			if(f=='N')
				gan=0;
			else gan=1;
			cin>>f;
			if(f=='N')xi=0;
			else xi=1;
			if(gan&&b>80)m+=850;
			if(xi&&a>85)m+=1000;
			cin>>c;
			if(a>80&&c)m+=8000;
			tot+=m;
			if(m>maxx)
			{
				maxx=m;
				ansname=name;
			}
		}
		cout<<ansname<<endl;
		cout<<maxx<<endl;
		cout<<tot<<endl;
	
	return 0;
}



