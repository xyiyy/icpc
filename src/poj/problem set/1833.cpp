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
int a[2100];

int main()
{
	ios::sync_with_stdio(false);
	int T,n,k,t;
	cin>>T;
	while(T--)
	{
		scanf("%d%d",&n,&k);
		t=0;
		for(int i=0;i<n;i++)
		{
			scanf("%d",&a[i]);
		}
		while(t<k)
		{
			next_permutation(a,a+n);
			t++;
		}
		for(int i=0;i<n;i++)
		{
			printf("%d",a[i]);
			if(i<n-1)
			printf(" ");
			else printf("\n");
			
		}
	}
	
		
		
		
		
		
	
	return 0;
}

