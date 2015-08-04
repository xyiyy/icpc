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
char a[10010][20];
long long  b[10010];
long long num;
char c;
signed long long maxx=-0x7fffffff;long long minn=0x7fffffff;
int main()
{
	ios::sync_with_stdio(false);
	int t;
	cin>>t;
	memset(a,'\0',sizeof(a));
	for(int i=0;i<t;i++)
	{
		cin>>a[i]>>b[i]>>c;
		int len=strlen(a[i]);
		if(a[i][0]=='>'&&a[i][1]=='='&&c=='Y'||(a[i][0]=='<'&&a[i][1]!='='&&c=='N'))
		{
			if(b[i]>maxx)maxx=b[i];
		//	cout<<endl;
		}
		if(a[i][0]=='>'&&a[i][1]!='='&&c=='Y'||(a[i][0]=='<'&&a[i][1]=='='&&c=='N'))
		{
			if(b[i]>maxx)maxx=b[i]+1;
		}
		if(a[i][0]=='<'&&a[i][1]=='='&&c=='Y'||(a[i][0]=='>'&&a[i][1]!='='&&c=='N'))
		{
			if(b[i]<minn)minn=b[i];
		}
		if(a[i][0]=='<'&&a[i][1]!='='&&c=='Y'||(a[i][0]=='>'&&a[i][1]=='='&&c=='N'))
		{
			if(b[i]<minn)minn=b[i]-1;
		}
	}
//	for(int i=0;i<t;i++)cout<<b[i]<<endl;
//	cout<<maxx<<"  "<<minn<<endl;
		if(minn>=maxx)cout<<maxx<<endl;
	else{
		cout<<"Impossible"<<endl;
	}
	return 0;
}
