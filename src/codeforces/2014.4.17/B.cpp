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
int a[100010][2];
int b[100010];
int main()
{
	ios::sync_with_stdio(false);
	int n;
	while(cin>>n)
	{
		memset(b,0,sizeof(b));
		for(int i=0;i<n;i++)
		{
			cin>>a[i][0]>>a[i][1];
		}
		int flag=1;
		for(int i=0;i<n;i++)
		{
			if(a[i][0]==b[a[i][1]])b[a[i][1]]++;
			else if(a[i][0]>b[a[i][1]])
			{flag=0;break;}
		}
		if(flag)cout<<"YES"<<endl;
		else cout<<"NO"<<endl;
	}
			
		
	return 0;
}

