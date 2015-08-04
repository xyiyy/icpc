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
using namespace std;
#define XINF INT_MAX
#define INF 0x3FFFFFFF
#define MP(X,Y) make_pair(X,Y)
#define PB(X) push_back(X)
#define REP(X,N) for(int X=0;X<N;X++)
typedef pair<int,int> PII;
typedef vector<int> VI;
typedef long long ll;
int m,n,k;

int main()
{
	ios::sync_with_stdio(false);
	char a[110];
//	freopen("A.in","r",stdin);
	while(cin>>a)
	{
		m=0;n=0;k=0;
		int len=strlen(a);
		if(len>=5)
		for(int i=0;i<len;i++)
		{
			
			if(a[i]>='a'&&a[i]<='z')m++;
			if(a[i]>='A'&&a[i]<='Z')n++;
			if(a[i]>='0'&&a[i]<='9')k++;
		}
	//	cout<<len<<m<<n<<k<<endl;
		if(m&&n&&k&&len>=5)cout<<"Correct"<<endl;
		else cout<<"Too weak"<<endl;
		memset(a,'\0',sizeof(a));
	}
	return 0;
}

