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
char a[110][110];
char b[110][110];
int vis[1100];


int main()
{
	ios::sync_with_stdio(false);
	int t,m,k=1;
	bool flag;
//	freopen("A-small-practice-2.in","r",stdin);
//	freopen("A2.out","w",stdout);
	cin>>t;
	while(t--)
	{
		flag=true;
		memset(a,'\0',sizeof(a));
		memset(b,'\0',sizeof(b));
		cin>>m;
		for(int i=0;i<m;i++)
		{
			cin>>a[i]>>b[i];
		}
		for(int i=0;i<n;i++)
		{
			
		cout<<"Case #"<<k++<<":";
		if(!flag) cout<<" No";
		else cout<<" Yes";
		cout<<endl;
	}
		
	
	
	return 0;
}

