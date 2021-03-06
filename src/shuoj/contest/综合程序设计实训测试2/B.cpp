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
const int N=110;
int a[N];
int main()
{
	ios::sync_with_stdio(false);
	int n;
	while(cin>>n){
		stack<int > s;
		int A=1,B=1;
		for(int i=1;i<=n;i++)
		{
			cin>>a[i];
		}
		int ok=1;
		while(B<=n)
		{
			if(A==a[B]){A++;B++;}
			else if(!s.empty()&&s.top()==a[B]){s.pop();B++;}
			else if(A<=n)s.push(A++);
			else {ok=0;break;}
		}
		if(ok)cout<<"Yes"<<endl;
		else cout<<"No"<<endl;
	}
	return 0;
}


