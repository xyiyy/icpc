//#####################
//Author:fraud
//Blog: http://www.cnblogs.com/fraud/
//#####################
//#pragma comment(linker, "/STACK:102400000,102400000")
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
bool vis[10][10];
ll dp[10][10];
int dirx[4]={-2,2,-2,2};
int diry[4]={-2,-2,2,2};
bool in(int x,int y){
	if(x<0||x>4||y<0||y>8)return 0;
	return 1;
}
int main()
{
	ios::sync_with_stdio(false);
	int a,b,c,d;
	while(cin>>a>>b>>c>>d){
		CLR(vis,0);
		vis[a][b]=1;
		for(int i=0;i<4;i++){
			int x = a + dirx[i];
			int y = b + diry[i];
			if(in(x,y))vis[x][y]=1;
		}
		CLR(dp,0);
		dp[0][0]=1;
		for(int i=0;i<=c;i++){
			for(int j=0;j<=d;j++){
				if(vis[i][j])continue;
				if(i)dp[i][j]+=dp[i-1][j];
				if(j)dp[i][j]+=dp[i][j-1];
			}
		}
		cout<<dp[c][d]<<endl;
		
	}
			
	return 0;
}



