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


int main()
{
//	ios::sync_with_stdio(false);
	char s[1100];
	while(~scanf("%s",&s))
	{
		int len=strlen(s);
		int sum=0;
		for(int i=0;i<len;i++)
		{
			if(s[i]>='0'&&s[i]<='9')
			sum+=s[i]-48;
		}
		cout<<sum<<endl;
		memset(s,'\0',sizeof(s));
	}

	return 0;
}

