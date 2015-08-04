//#####################
//Author:fraud
//Blog: http://www.cnblogs.com/fraud/
//#####################
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
int dp[2][1010][2];
int last[1010][1010][2];
int main()
{
	ios::sync_with_stdio(false);
	int n;
	scanf("%d",&n);
	int ci=0,cj=0;
	int a;
	bool flag=0;
	int x,y,b,c,tmp;
	for(int i=1;i<n;i++){
		last[0][i][0]=last[0][i][1]=1;
	}
	x=0,y=x^1;
	for(int j=0;j<n;j++){
		b=c=0;
		scanf("%d",&a);
		if(a){
			while(a%2==0)b++,a/=2;
			while(a%5==0)c++,a/=5;
		}else	flag=1,ci=0,cj=j;
		if(j){
			dp[x][j][0]=dp[x][j-1][0]+b;
			dp[x][j][1]=dp[x][j-1][1]+c;
		}else{
			dp[x][j][0]=b;
			dp[x][j][1]=c;
		}
	}
	for(int i=1;i<n;i++){
		x=i&1,y=x^1;
		for(int j=0;j<n;j++){
			b=c=0;
			scanf("%d",&a);
			if(a){
				while(a%2==0)b++,a/=2;
				while(a%5==0)c++,a/=5;
			}else	flag=1,ci=i,cj=j;
			dp[x][j][0]=dp[y][j][0]+b;
			dp[x][j][1]=dp[y][j][1]+c;
			if(j){
				tmp=dp[x][j-1][0]+b;
				if(tmp<dp[x][j][0])dp[x][j][0]=tmp,last[i][j][0]=1;
				tmp=dp[x][j-1][1]+c;
				if(tmp<dp[x][j][1])dp[x][j][1]=tmp,last[i][j][1]=1;
			}
		}
	/*	cout<<"=============="<<endl;
		for(int j=0;j<n;j++)cout<<dp[x][j][0]<<" ";
		cout<<endl;
		for(int j=0;j<n;j++)cout<<dp[x][j][1]<<" ";
		cout<<endl;
		for(int j=0;j<n;j++)cout<<last[i][j][0]<<" ";
		cout<<endl;
		for(int j=0;j<n;j++)cout<<last[i][j][1]<<" ";
		cout<<endl;*/
		
	}
	int f=0;
	if(dp[x][n-1][1]<dp[x][n-1][0])f=1;
	int ans=dp[x][n-1][f];
	if(ans&&flag){
		puts("1");
		for(int i=0;i<ci;i++)printf("D");
		for(int j=0;j<cj;j++)printf("R");
		for(int i=ci+1;i<n;i++)printf("D");
		for(int j=cj+1;j<n;j++)printf("R");
	}else{
		printf("%d\n",ans);
		stack<char>s;
		for(int i=n-1,j=n-1;i||j;){
			if(last[i][j][f]){
				s.push('R');
				j--;
			}else{
				s.push('D');
				i--;
			}
		}
		while(!s.empty()){
			printf("%c",s.top());
			s.pop();
		}
	}
	puts("");
	return 0;
}



