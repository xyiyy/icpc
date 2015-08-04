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
double a[110];
double sum=0;
int main()
{
	ios::sync_with_stdio(false);
	int n;
	double m;
	while(cin>>n)
	{
		sum=0;
		for(int i=0;i<n;i++)
		{
			cin>>a[i];
			sum+=1/a[i];
		}
		cin>>m;
		m=m/sum;
		cout<<fixed<<setprecision(2)<<m<<endl;
	}
	return 0;
}

