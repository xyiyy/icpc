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
int gao(int n,int m,int x,int y){
	/*if(n%2==1){
		if(x==(n+1)/2&&x==y&&n===m){
			 return n/2;
		}else{
			if(x==(n+1)/2&&y==(m+1)/2){
				return (n+1)/2;
			}else if(x==(n+1)/2){
				return ()*/
	int l = min(x,min(y-1,n+1-x));
	int r = min(x,min(m-y,n+1-x));
	int u = min(x-1,min(y,m+1-y));
	int d = min(n-x,min(y,m+1-y));
	int tmp = 0;
	if(x!=(n+1)/2)tmp = (n+1)/2;
	//-cout<<l<<" "<<r<<" "<<u<<" "<<d<<endl;
	return max(max(l,r),max(u,max(d,tmp)));
}
int main()
{
	ios::sync_with_stdio(false);
	int n,m,x,y;
	while(cin>>n>>m>>x>>y){
		int ans;
		if(n<m)ans = gao(n,m,x,y);
		else ans = gao(m,n,y,x);
		cout<<ans<<endl;
	}
	return 0;
}



