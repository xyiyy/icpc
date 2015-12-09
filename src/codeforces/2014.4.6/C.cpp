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

int gcd(int m,int n)
{
	int temp;
	while(n)
	{
		temp=m%n;
		m=n;n=temp;
	}
	return m;
}
void fun()
{
	int n,k;
	cin>>n>>k;
	if(n/2>k)
	{
		cout<<"-1"<<endl;
		return ;
	}
	if(n==1)
	{
		cout<<"-1"<<endl;
		return ;
	}
	int num=k;
	int fla;
	if(n%2==1)
	for(int i=0;i<n-3;i++)
	{
		cout<<i<<" ";
		k--;
		fla=i;
	}
	else for(int i=0;i<n-2;i++){cout<<i<<" ";k--;fla=i;}
	int fou=0;
	int i,j;
	for(i=fla+1;fou==0;i++)
	{
		for(j=fla+2;fou==0;j++)
		{
			if(gcd(i,j)==k)fou=1;
		}
	}
	cout<<i<<" "<<j<<" ";
	if(n%2==1)
	{
		fla++;
		while(fla==i||fla==j)
		fla++;
		cout<<fla;
	}
	cout<<endl;
	return ;
}
	
	


int main()
{
	ios::sync_with_stdio(false);
	fun();
	return 0;
}

