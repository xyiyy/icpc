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
char a[1000][1000];
string b;
int main()
{
	ios::sync_with_stdio(false);
	int n;
	while(cin>>n)
	{
		memset(a,'\0',sizeof(a));
		int i=0;
		cin.ignore();
		for(int j=0;j<n;j++)
		{
			cin.getline(a[j],1000,'\n');
		//	cout<<j<<endl;
			cout<<a[j]<<endl;
			cout<<endl;
		}
		while(cin>>b)
		{
			cout<<b<<endl;
			cout<<endl;
		}
	}
	
	return 0;
}

