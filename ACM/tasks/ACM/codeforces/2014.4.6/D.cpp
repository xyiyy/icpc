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
int a[3000][3000];
int n,k,num;
/*
void dfs(int i)
{
	int flag=0;
	for(int j=k-1;j>0;j--)
	{
		if(a[j]%a[j-1]!=0)flag=1;
		if(flag)break;
	}
	if(!flag){num++;for(int p=0;p<k;p++)cout<<a[p]<<" ";cout<<endl;}
//	cout<<flag<<endl;
	cout<<num<<" "<<i<<endl;
//	if(i==0&&a[i]==a[k-1]&&a[k-1]!=1){return;}
	//if(i==0)
	if(a[0]==n)return;
	if(a[0]==a[k-1]&&i==0)
	{//return;
	//a[k-1];
	for(int x=0;x<k-1;x++)
	{
		a[x]=1;
	}
	dfs(k-1);
	//dfs()
}
		//a[k-1]++;
		
	while(a[k-1]<=n&&a[0]<=a[k-1])
	{
		a[i]++;
		if(i==0)dfs(i);
		//dfs(i)
		if(i>0)
		dfs(i-1);
		if(a[i]>a[k-1])
		{
		//if(i==0)i++;
		for(int m=0;m<i-1;m++)
		{
			a[m]=1;
		}
		}
		
		//a[i]--;
	}
	return;
}*/
int main()
{
	ios::sync_with_stdio(false);
	int flag=0;
	while(cin>>n>>k)
	{
		memset(a,0,sizeof(a));
		for(int i=1;i<=n+1;i++)
		{
			a[0][i]=1;
		}
		num=0;
		for(int i=1;i<k;i++)
		{
			for(int j=1;j<=n;j++)
			{
				for(int q=1;q*j<=n;q++)
				{
					a[i][q*j] =(a[i][q*j]+a[i-1][j])% 1000000007;
				}
			}
		}
		for(int i=0;i<=n;i++)
		{
		//	cout<<a[k-1][i]<<" ";
			num=(num+a[k-1][i])% 1000000007;
		}
	//	int num=0;
	
		cout<<num<<endl;
		//for(int i=1;)
	}
	return 0;
}

