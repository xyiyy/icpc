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
int num[3];
int a[1000];

int main()
{
	ios::sync_with_stdio(false);
	int m,n;
	while (cin>>m>>n)
	{
		int j=0;
		memset(a,0,sizeof(a));
		for(int i=m;i<=n;i++)
		{
			num[0]=i/100;
			num[1]=(i/10)%10;
			num[2]=i%10;
			if(i==num[0]*num[0]*num[0]+num[1]*num[1]*num[1]+num[2]*num[2]*num[2])
			a[j++]=i;
		}
		if(a[0]==0)
		cout<<"no"<<endl;
		else
		{
			for(int i=0;i<j-1;i++)
			{
				cout<<a[i]<<" ";
			}
			cout<<a[j-1]<<endl;
		}
	}
	return 0;
}

