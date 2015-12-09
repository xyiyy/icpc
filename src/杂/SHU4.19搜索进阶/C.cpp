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
int m,n;
int a[36][36];
int dy[8]={-2,-2,-1,-1,1,1,2,2};
int dx[8]={-1,1,-2,2,-2,2,-1,1};
int ret,size;
int que[1010][2];
void dfs(int x,int y,int num)
{
	if(ret==1)return;
	if(x<=0||y<=0||x>m||y>n)return;
	if(a[x][y]==1)return;
	a[x][y]=1;
	que[num][1]=x;
	que[num][0]=y;
	if(num==m*n)
	{
		ret=1;
		return ;
	}
	for(int i=0;i<8;i++)
	{
		dfs(x+dx[i],y+dy[i],num+1);
	}
	a[x][y]=0;

}
int main()
{
	int T;
	int k=1;
	cin>>T;
	while(T--)
	{
		ret=0;
		cin>>m>>n;
		memset(a,0,sizeof(a));
		dfs(1,1,1);
		cout<<"Scenario #"<<k++<<":"<<endl;
		if(ret)
		{
			for(int i=1;i<=n*m;i++)
			{
				cout<<char(que[i][0]+'A'-1)<<que[i][1];
			}
			cout<<endl;
		}
		else 
		{
			cout<<"impossible"<<endl;
		}
		cout<<endl;
	}
	return 0;
}
