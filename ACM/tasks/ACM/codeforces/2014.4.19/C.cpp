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
char a[100010];
char b[100010];
bool v[100010];

int main()
{
	ios::sync_with_stdio(false);
	int n;
	int len;
	while(cin>>n)
	{
		memset(b,'\0',sizeof(b));
		memset(v,false,sizeof(v));
		for(int j=0;j<n;j++)
		{
			cin>>a;
			len =strlen(a);
			for(int i=0;i<len;i++)
			{
				if(a[i]=='?'&&b[i]>='a'&&b[i]<='z')
				{
					;
				}
				else if(b[i]=='?'&&a[i]>='a'&&a[i]<='z'&&!v[i])
				{
					b[i]=a[i];
				}
				else if(a[i]!=b[i]&&a[i]>='a'&&a[i]<='z'&&b[i]>='a'&&b[i]<='z')
				{
					b[i]='?';
					v[i]=true;
				}
				else if(!v[i])
				b[i]=a[i];
			}
		}
		for(int i=0;i<len;i++)
		{
			if(b[i]=='?'&&!v[i])
			cout<<'c';
			else cout<<b[i];
		}
		cout<<endl;
	}
			
		
		
	return 0;
}

