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
const int N=100010;
char a[N];
int b[4];
int main()
{
	ios::sync_with_stdio(false);
	int len;
	while(cin.getline(a,N,'\n'))
	{
		len=strlen(a);
		for(int i=0;i<len;i++)
		{
			if(a[i]==' ')
			b[2]++;
			else if(a[i]>='0'&&a[i]<='9')b[1]++;
			else if((a[i]>='a'&&a[i]<='z')||(a[i]>='A'&&a[i]<='Z'))b[0]++;
			else b[3]++;
		}
		cout<<b[0]<<" "<<b[1]<<" "<<b[2]<<" "<<b[3]<<endl;
		CLR(a,0);
		CLR(b,0);
	}
		
	return 0;
}


