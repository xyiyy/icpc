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

int main()
{
//	ios::sync_with_stdio(false);
	double maxx,minn,n,sum;
	int num;
	int k=1;
	char str[32768];
	while(cin.getline(str,32768,'\n'))
	{
		cout<<"Case "<<k++<<": ";
		
		istrstream ss(str,32768);
		maxx=-99999999;minn=999999999;
		num=0;sum=0;
		while(ss>>n)
		{
			maxx=max(maxx,n);
			minn=min(minn,n);
			sum+=n;
			num++;
		}
		cout<<num<<", "<<minn<<", "<<maxx<<", "<<(sum-maxx-minn)/(num-2.0)<<endl;
	}
		
	return 0;
}

