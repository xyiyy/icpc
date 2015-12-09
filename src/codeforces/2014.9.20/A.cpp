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

int main()
{
	ios::sync_with_stdio(false);
	int n;
	while(cin>>n)
	{
		if(n==1||n==2||n==3)
		{
			cout<<"NO"<<endl;
		}
		else if(n==4)
		{
			cout<<"YES"<<endl;
			cout<<"1 * 2 = 2"<<endl;
			cout<<"2 * 3 = 6"<<endl;
			cout<<"6 * 4 = 24"<<endl;
		}
		else if(n==5)
		{
			cout<<"YES"<<endl;
			cout<<"5 * 4 = 20"<<endl;
			cout<<"20 + 2 = 22"<<endl;
			cout<<"22 + 3 = 25"<<endl;
			cout<<"25 - 1 = 24"<<endl;
		}
		else if(n==6)
		{
			cout<<"YES"<<endl;
			cout<<"4 * 6 = 24"<<endl;
			cout<<"1 * 2 = 2"<<endl;
			cout<<"2 + 3 = 5"<<endl;
			cout<<"5 - 5 = 0"<<endl;
			cout<<"24 + 0 = 24"<<endl;
		}
		else if(n&1)
		{
			cout<<"YES"<<endl;
			while(n>7)
			{
				cout<<n<<" - "<<n-1<<" = "<<1<<endl;
				cout<<"1 * 1 = 1"<<endl;
				n-=2;
			}
			cout<<"7 + 2 = 9"<<endl;
			cout<<"5 + 3 = 8"<<endl;
			cout<<"9 - 8 = 1"<<endl;
			cout<<"1 * 1 = 1"<<endl;
			cout<<"4 * 6 = 24"<<endl;
			cout<<"24 * 1 = 24"<<endl;
		}
		else 
		{
			cout<<"YES"<<endl;
			while(n>6)
			{
				cout<<n<<" - "<<n-1<<" = "<<1<<endl;
				cout<<"1 * 1 = 1"<<endl;
				n-=2;
			}
			cout<<"4 * 6 = 24"<<endl;
			cout<<"1 * 2 = 2"<<endl;
			cout<<"2 + 3 = 5"<<endl;
			cout<<"5 - 5 = 0"<<endl;
			cout<<"24 + 0 = 24"<<endl;
		}
	}
			
			
	return 0;
}



