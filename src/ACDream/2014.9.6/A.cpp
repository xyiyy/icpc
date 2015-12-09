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
	int n,cur,d;
	int cas=1;
	while(cin>>n>>cur>>d)
	{
		cout<<"Case #"<<cas++<<": ";
		if(cur!=1)cout<<"(<<)";
		else cout<<"[<<]";
		int l=max(cur-d,1);
		int r=min(cur+d,n);
		if(cur==1)
		{
			cout<<"[1]";
		}
		else if(l==1)
		{
			for(int i=1;i<cur;i++)
			{
				cout<<"("<<i<<")";
			}
			cout<<"["<<cur<<"]";
		}
		else 
		{
			cout<<"[...]";
			for(int i=cur-d;i<cur;i++)
			{
				cout<<"("<<i<<")";
			}
			cout<<"["<<cur<<"]";
		}
		if(cur==n)
		{
			cout<<"[>>]";
		}
		else
		{
			for(int i=cur+1;i<=r;i++)
			{
				cout<<"("<<i<<")";
			}
			if(r!=n)cout<<"[...]";
			//if(cur+d>n)cout<<"[>>]";
			cout<<"(>>)";
		}
		cout<<endl;
	}
		
		
		
	
	return 0;
}



