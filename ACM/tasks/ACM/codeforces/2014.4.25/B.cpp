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
long long  a[1010];
int p[1010];
int index[1010];
bool cmp(int aa,int bb)
{
	return a[aa]<a[bb];
}
int main()
{
	ios::sync_with_stdio(false);
	int n,s;
	cin>>n>>s;
	int x,y;
	int sum=s;
	int num=0;
	for(int i=0;i<n;i++)
	{
		cin>>x>>y;
		a[i]=x*x+y*y;
		cin>>p[i];
		sum+=p[i];
		index[i]=i;
	}
		sort(index,index+n,cmp);
		
		if(sum<1000000)
		{
			cout<<"-1"<<endl;
		}
		else 
		{
			sum=s;
			for(int i=0;i<=1000;i++)
			{
				//num++;
				sum+=p[index[i]];
				if(sum>=1000000)
				{
					num=i;
					break;
				}
			}
			double r=a[index[num]];
			r=sqrt(r);
			cout<<fixed<<setprecision(7)<<r<<endl;
			
		}
		
	return 0;
}

