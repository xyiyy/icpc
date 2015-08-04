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
ll n,m,v,k;

int main()
{
	ios::sync_with_stdio(false);
	int T;
	cin>>T;
	while(T--)
	{
		cin>>n>>m>>v>>k;
		int times=0;
		int flag=0;
		if(m>=n)flag=2;
		else if(v>m||k<=0||(m-v)*k<=m)
		{
			flag=1;
		}
		else while(n>m)
		{
			m-=v;
			m*=k;
			times++;
		}
		if(n>m)flag=1;
		if(flag==1)cout<<"-1"<<endl;
		else if(flag==2)cout<<"0"<<endl;
		else cout<<times<<endl;
	}
			
	return 0;
}

