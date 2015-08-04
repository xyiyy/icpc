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
char kk[20]="8()[]<";

int main()
{
	ios::sync_with_stdio(false);
	char a[100],b[100];
//	cout<<kk;
	while(cin>>a>>b)
	{
		int n=strlen(a);//,m=strlen(b);
		int key=0;
		//cout<<
		for(int i=0;i<n;i++)
		{
			if(a[i]=='8'&&b[i]=='['||(a[i]=='<'&&b[i]==']'))key++;
			if(a[i]=='['&&b[i]=='8'||(a[i]==']'&&b[i]=='<'))key--;
			if(a[i]=='['&&b[i]=='('||(a[i]==']'&&b[i]==')'))key++;
			if(a[i]==')'&&b[i]==']'||(a[i]=='('&&b[i]=='['))key--;
			if(a[i]=='8'&&b[i]=='('||(a[i]=='<'&&b[i]==')'))key--;
			if(a[i]=='('&&b[i]=='8'||(a[i]==')'&&b[i]=='<'))key++;
			////if(a[i]=='8')key--;
			//else if(a[i]>b[i])key++;
		}
		memset(a,'\0',sizeof(a));
		memset(b,'\0',sizeof(b));
		
		if(key==0)
		cout<<"TIE"<<endl;
		else if(key<0)
		cout<<"TEAM 2 WINS"<<endl;
		else if(key>0)
		cout<<"TEAM 1 WINS"<<endl;
	}
	return 0;
}
		

