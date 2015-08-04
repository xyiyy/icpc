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

int a[110];
int b[110];
int id[110];

bool cmp(int x,int y)
{
	if(b[x]==b[y])
	{
		return a[x]<a[y];
	}
	return b[x]<b[y];
}
int main()
{
	ios::sync_with_stdio(false);
	int n;
	cin>>n;
	int temp;
	memset(b,0,sizeof(b));
	for(int i=0;i<n;i++)
	{
		cin>>a[i];
		temp=a[i];
		while(temp)
		{
			b[i]+=temp%10;
			temp/=10;
		}
		id[i]=i;
	}
	sort(id,id+n,cmp);
	for(int i=0;i<n;i++)
	{
		cout<<a[id[i]]<<endl;
	}
	return 0;
}

