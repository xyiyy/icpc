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

int a[10000];
int light[10000];
int num[10000]; 


int main()
{
	ios::sync_with_stdio(false);
	int m,n;
	while(cin>>m>>n)
	{
		for(int i=0;i<n;i++)
		{
			cin>>a[i];
		}
		for(int i=0;i<m;i++)
		{
			light[i]=m-i;
		}
		int i=0;
		for(int j=0;j<m;j++)
		{
			if(a[i]<=light[j])
			{
				num[m-1-j]=a[i];
				//cout<<a[i]<<" ";
			}
			else if(i<n)
			{
				i++;
				j--;
				continue;
			}
			else break;
		}
		for(i=0;i<m;i++)
		{
			cout<<num[i]<<" ";
		}
		cout<<endl;
		
	}
		
	return 0;
}

