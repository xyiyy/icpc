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

char a[110][110];
int M,N;

void dfs(int x,int y)
{
	if(x<0||x>=M||y<0||y>=N||a[x][y]=='.')return ;
	a[x][y]='.';
	for(int dx=-1;dx<2;dx++)
	{
		for(int dy=-1;dy<2;dy++)
		{

			dfs(x+dx,y+dy);
		}
	}
}

int main()
{
	ios::sync_with_stdio(false);
	cin>>M>>N;
	int num=0;
	for(int i=0;i<M;i++)
		for(int j=0;j<N;j++)
			cin>>a[i][j];
	for(int i=0;i<M;i++)
		for(int j=0;j<N;j++)
			if(a[i][j]=='W'){
				dfs(i,j);
				num++;
			}
	cout<<num<<endl;
	return 0;
}


