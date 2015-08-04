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
string a[6]={ "jolteon", "flareon", "umbreon", "leafeon", "glaceon", "sylveon"};

int main()
{
	ios::sync_with_stdio(false);
	string temp;
	string b;
	int c,maxn,id;
	int n;
	while(cin>>n>>b)
	{
		maxn=0;
		temp=b.substr(0,4);
		for(int i=0;i<6;i++)
		{
			c=0;
			for(int j=0;j<4;j++)
			{
				if(a[i][j]==temp[j])
				c++;
			}
			if(c>maxn)
			{
				maxn=c;
				id=i;
			}
		}
		cout<<a[id]<<endl;
	}
	return 0;
}


