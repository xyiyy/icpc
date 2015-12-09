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
	int N,t=0;
	cin>>N;
	while(N--)
	{
		++t;
	//	cin>>t;
		int days=0;
		for(int i=1;i<=t;i++)
		{
			unsigned long long temp=1;
			for(int j=1;j<=t;j++)
			{
				temp=(temp*i)%7;
			}
			days=(days+temp)%7;
		}
		cout<<days<<endl;
	//	if(days==0)cout<<"Saturday"<<endl;
	//	else if(days==1)cout<<"Sunday"<<endl;
	//	else if(days==2)cout<<
	
}
	return 0;
}

