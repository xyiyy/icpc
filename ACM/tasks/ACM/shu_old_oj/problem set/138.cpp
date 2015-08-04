#include <iostream>
#include <sstream>
#include <strstream>
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
const int N=1050000;
char a[N];
int ans[70010];
int main()
{
	ios::sync_with_stdio(false);
	int k=1,i=0;
	while(cin.getline(a,N,'\n'))
	{
		istrstream ss(a,N);
		i=0;
		while(ss>>ans[i])i++;
		sort(ans,ans+i);
		cout<<"Case "<<k++<<":";
		for(int j=0;j<i;j++)
		{
			cout<<" "<<ans[j];
		}
		cout<<endl;
		CLR(a,'\0');
		CLR(ans,0);
	}
	return 0;
}

