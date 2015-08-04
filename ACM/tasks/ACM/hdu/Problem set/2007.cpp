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


int main()
{
	ios::sync_with_stdio(false);
	int m,n;
	while(cin>>m>>n)
	{
		int minn=min(m,n);
		int maxx=max(m,n);//以防输入的数值不按小到大输入 
		long long sum1=0,sum2=0;//必须初始化 
		for(int i=minn;i<=maxx;i++)
		{
			if(i%2==1)sum2+=i*i*i;
			else if(i%2==0) sum1+=i*i;
		}
		cout<<sum1<<" "<<sum2<<endl;
	}
	return 0;
}

