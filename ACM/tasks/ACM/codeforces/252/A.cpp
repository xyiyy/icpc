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

bool a[60];
int main()
{
	ios::sync_with_stdio(false);
	int n,v;
	while(cin>>n>>v)
	{
		memset(a,0,sizeof(a));
		int num;
		for(int i=0;i<n;i++)
		{
			int k;
			cin>>k;
			for(int j=0;j<k;j++)
			{
				cin>>num;
				if(num<v)a[i]=1;
			}
			
		}
		int sum=0;
		for(int i=0;i<n;i++)
		{
			if(a[i])sum++;
		}
		if(sum)
		{
			cout<<sum<<endl;
			for(int i=0;i<n;i++)
			{
				if(a[i])cout<<i+1<<" ";
			}
		}
		else cout<<0<<endl;
		cout<<endl;
	}
	
	return 0;
}

