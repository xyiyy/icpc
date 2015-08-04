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
#include <cctype>
using namespace std;
#define XINF INT_MAX
#define INF 0x3FFFFFFF
#define MP(X,Y) make_pair(X,Y)
#define PB(X) push_back(X)
#define REP(X,N) for(int X=0;X<N;X++)
#define REP2(X,L,R) for(int X=L;X<=R;X++)
#define DEP(X,R,L) for(int X=R;X>=L;X--)
#define CLR(A,X) memset(A,X,sizeof(A))
#define IT iterator
typedef long long ll;
typedef pair<int,int> PII;
typedef vector<PII> VII;
typedef vector<int> VI;
int a[10][10];
int c[10][10];
bool vis[10];
int G[10][10];
bool flag;
int dfs(int x,int y,int miss)
{
	//cout<<x<<"  "<<y<<"  "<<miss<<"   "<<flag<<endl;
	if(y==5&&x==5)
	{
		flag=1;
		return 1;
	}
	if(y<5)
	{
		for(int i=0;i<9;i++)
		{
			if(vis[i])continue;
			vis[i]=1;
			for(int j=0;j<5;j++)
			{
				G[j][y]=a[i][j];
			}
			if(dfs(x,y+1,miss))
			{
				return 1;
			}
			vis[i]=0;
		}
	}
	else if(x==miss)
	{
		if(dfs(x+1,y,miss))return 1;
	}
	else 
	{
		int mark=0;
		for(int i=0;i<9;i++)
		{
			if(vis[i])continue;
			vis[i]=1;
			mark=0;
			for(int j=0;j<5;j++)
			{
				if(a[i][j]!=G[x][j])mark=1;
			}
			if(!mark)
			{
				if(dfs(x+1,y,miss))return 1;
			}
			vis[i]=0;
		}
		
		//return 0;
	}
	return 0;
}
		
					
				
			
			
int main()
{
	ios::sync_with_stdio(false);
	int	 cas=1;
	int x,y;
	while(cin>>a[0][0])
	{
		CLR(vis,0);
		CLR(G,0);
	
		flag=0;
		cout<<"Case "<<cas++<<":"<<endl;
		for(int i=1;i<5;i++)
		{
			cin>>a[0][i];
		}
		for(int i=1;i<9;i++)
		{
			for(int j=0;j<5;j++)
			{
				cin>>a[i][j];
			}
		}
		x=0;y=0;
		for(int i=1;i<5;i++)
		{
			if(dfs(x,y,i))break;
		}
		if(flag)
		{
			for(int i=0;i<5;i++)
			{
				cout<<G[i][0];
				for(int j=1;j<5;j++)
				{
					cout<<" "<<G[i][j];
				}
				cout<<endl;
			}
		}
		else 
			cout<<"Error."<<endl;
		cout<<endl;	
	}
		
	return 0;
}


