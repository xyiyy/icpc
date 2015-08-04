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
bool field[510][510];

int main()
{
	ios::sync_with_stdio(false);
	int N,K;
	while(cin>>N>>K)
	{
		memset(field,0,sizeof(field));
		int  x,y;
		REP(i,K)
		{
			cin>>x>>y;
			field[x][y]=1;
		}
		
	return 0;
}

