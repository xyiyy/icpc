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
double X[100010];
const double R=0.5;
const double eps = 10e-6;
int main()
{
	ios::sync_with_stdio(false);
	int n;
	while(cin>>n)
	{
		int ans=0;
		for(int i=0;i<n;i++)
		{
			cin>>X[i];
		}
		sort(X,X+n);
		int i=0;
		while(i<n)
		{
			double s=X[i++];
			while(i<n&&s+R-X[i]>0 )i++;
			double p=s+R;
			while(i<n&&X[i]<p+R)i++;
			ans++;
		}
		cout<<ans<<endl;
	}
	return 0;
}

