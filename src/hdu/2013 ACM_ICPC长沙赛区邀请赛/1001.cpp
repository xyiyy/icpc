#include <iostream>     
#include <fstream>     
#include <algorithm>     
#include <string>     
#include <set>     
#include <map>     
#include <queue>     
#include <utility>     
#include <stack>     
#include <list>     
#include <vector>     
#include <cstdio>     
#include <cstdlib>     
#include <cstring>     
#include <cmath>     
#include <ctime>     
#include <ctype.h>
#include <iomanip>
#include <stdio.h>
using namespace std;


#define ll long long

ll dp[1000][1000];

ll C(int m, int n)
{
	if(m<1000&&n<1000&&dp[m][n]) return dp[m][n];
	if(m==n||n==0)return 1;
	if(n==1) return m;
	ll ret = C(m-1,n-1)*m/n;
	if(m<1000&&n<1000)dp[m][n]=ret;
	return ret;
}

int main()
{
	long long a,b,n,m;
	while(cin>>a>>b>>n>>m)
	{
		double temp=sqrt(b);
		double sum=0;
		for(int i=0;i<=n;i++)
		{
			sum+=C(n,i)*pow(a,i)*pow(temp,n-i);
		}
		cout<<((int)ceil(sum)%m)<<endl;
	}
	return 0;
}
