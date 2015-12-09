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
char a[200010];
int main()
{
	ios::sync_with_stdio(false);
	int k=1;
	double num,sum=0;
	int r=0,c=0,c1=0;
	while(cin.getline(a,100010,'\n'))
	{
		if(strlen(a)>=1)
		{
			c1=0;
			r++;
			//sum=0;
			istrstream ss(a,100010);
			while(ss>>num)
			{
				sum+=num;
			//	if(r==1)
				c1++;
			}
			c=max(c1,c);
		}
		else 
		{
			cout<<"Case "<<k++<<": "<<r<<", "<<c<<", "<<sum<<endl;
			sum=0;
			r=0;c=0;
			c1=0;
		}
		memset(a,'\0',sizeof(a));
	}
	cout<<"Case "<<k++<<": "<<r<<", "<<c<<", "<<sum<<endl;

	return 0;
}

