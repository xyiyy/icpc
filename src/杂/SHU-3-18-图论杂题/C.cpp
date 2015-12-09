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
//#include <map>
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
int mm,nn;
int m,n;
int field[200][200];
int dx[4]={-1,0,0,1};
int dy[4]={0,1,-1,0};
void dfs(int x,int y)
{
	if(x<0||x>=mm||y<0||y>=nn||field[x][y]==0)return ;
	field[x][y]=0;
	for(int i=0;i<4;i++)
	{
		dfs(x+dx[i],y+dy[i]);
	}
}
	
int main()
{
	ios::sync_with_stdio(false);
	int map[11][9]={0,1,0,1,1,0,0,0,0,
				0,1,0,0,1,1,0,0,0,
				0,0,0,1,1,0,0,1,0,
				0,0,0,0,1,1,0,1,0,
				0,1,0,0,1,0,0,1,0,
				0,0,0,1,1,1,0,0,0,
				0,1,0,1,1,1,0,0,0,
				0,1,0,1,1,0,0,1,0,
				0,0,0,1,1,1,0,1,0,
				0,1,0,0,1,1,0,1,0,
				0,1,0,1,1,1,0,1,0};
	while(cin>>m>>n&&m!=-1&&n!=-1)
	{
		mm=3*m;nn=3*n;
		char b,c;
		for(int i=0;i<m;i++)
		{
			for(int j=0;j<n;j++)
			{
				cin>>b;
				for(int k=0;k<9;k++)
				{
					field[3*i+k/3][3*j+k%3]=map[b-'A'][k];
				}
			}
		}
		int num=0;
		for(int i=0;i<mm;i++)
		{
			for(int j=0;j<nn;j++)
			{
				if(field[i][j]==1)
				{
					dfs(i,j);
					num++;
				}
				
			}
		}
		cout<<num<<endl;
	}
		
		
	
	
	return 0;
}

