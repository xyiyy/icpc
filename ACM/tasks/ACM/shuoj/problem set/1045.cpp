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
bool a[1100];


int main()
{
	ios::sync_with_stdio(false);
	int n;
	while(cin>>n)
	{
		int num=0,sum=0;
		memset(a,false,sizeof(a));
		for(int i=0;i<n;i++)
		{
			cin>>num;
			if(a[num]!=true)
			{
				a[num]=true;
				sum++;
			}
		}
		cout<<sum<<endl;
		num=1;
		for(int i=0;i<1010;i++)
		{
			if(a[i]&&num<=sum-1)
			{
				cout<<i<<" ";
			//	cout<<num<<endl;
				num++;
			}
			else if(a[i]&&num==sum)
			{
				cout<<i<<endl;
				break;
			}
		}
		
				
				 
	}
	return 0;
}

