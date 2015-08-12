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
int dp[100010][20];
int gao(int l,int r){
	int y = log2(double(r-l+1));
	return min(dp[l][y],dp[r-(1<<y)+1][y]);
}
int main()
{
	ios::sync_with_stdio(false);
	int t;
	scanf("%d",&t);
	while(t--){
		int n,m;
		scanf("%d%d",&n,&m);
		int tmp;
		for(int i=0;i<n;i++){
			scanf("%d",&tmp);
			dp[i][0]=tmp;
		}
		for(int j =1;(1<<j)<=n;j++){
			int len = (1<<j)-1;
			for(int i=0;i+len<n;i++){
				int p = (1<<(j-1));
				dp[i][j] = min(dp[i][j-1],dp[i+p][j-1]);
			}
		}
		for(int i=0;i+m<=n;i++){
			if(i)printf(" ");
			printf("%d",gao(i,i+m-1));
		}
		puts("");
	}
			
	return 0;
}



