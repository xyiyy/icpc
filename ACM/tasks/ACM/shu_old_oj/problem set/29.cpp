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
char a[10010],b[10010];
int main()
{
	ios::sync_with_stdio(false);
	int cas=1;
	int T;
	cin>>T;
	cin.ignore();
	while(T--)
	{
		if(cas!=1)
		cin.getline(a,10010,'\n');
		CLR(a,0);
		CLR(b,0);
		cin.getline(a,10010,'\n');
		cin.getline(b,10010,'\n');
		cout<<"Case "<<cas++<<": "<<endl;
		cout<<b<<endl<<a<<endl;
	}
	return 0;
}


