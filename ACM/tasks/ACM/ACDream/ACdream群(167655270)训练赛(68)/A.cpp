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

long long a[3];

int main()
{
	ios::sync_with_stdio(false);
	int n;
	cin>>n;
	int k=1;
	while(n--)
	{
		cin>>a[0]>>a[1]>>a[2];
		sort(a,a+3);
		cout<<"Case "<<k++<<": ";
		if(a[1]*a[1]+a[0]*a[0]==a[2]*a[2])
		cout<<"yes"<<endl;
		else cout<<"no"<<endl;
	}
		
		
	 
	
	return 0;
}

