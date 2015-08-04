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
int dpmin[100010][20];
int dpmax[100010][20];
int getmin(int l,int r){
	int k = log2(double(r-l+1));
	return min(dpmin[l][k],dpmin[r-(1<<k)+1][k]);
}
int getmax(int l,int r){
	int k = log2(double(r-l+1));
	return max(dpmax[l][k],dpmax[r-(1<<k)+1][k]);
}
int check(int l,int r){
	int k = log2(double(r-l+1));
	int maxx = getmax(l,r);
	int minn = getmin(l,r);
	return maxx - minn;
}

int main()
{
	ios::sync_with_stdio(false);
	int t;
	scanf("%d",&t);
	while(t--){
		int n;
		int m;
		scanf("%d %d",&n,&m);
		int tmp;
		for(int i=0;i<n;i++){
			scanf("%d",&tmp);
			dpmin[i][0] = tmp;
			dpmax[i][0] = tmp;
		}
		for(int j = 1;(1<<j)<=n;j++){
			int len = (1<<j)-1;
			for(int i=0;i+len<n;i++){
				int p = (1<<(j-1));
				dpmin[i][j] = min(dpmin[i][j-1],dpmin[i+p][j-1]);
				dpmax[i][j] = max(dpmax[i][j-1],dpmax[i+p][j-1]);
			}
		}
		ll ans = 0;
		for(int i=0;i<n;i++){
			ll l = i;
			ll r = n-1;
			ll p = i;
			while(l<=r){
				ll mid = (l+r)>>1;
				if(check(i,mid)<m){
					p = mid;
					l = mid + 1;
				}else{
					r = mid - 1;
				}
			}
			//cout<<p<<endl;
			ans = ans + p - i + 1;
		}
		printf("%I64d\n",ans);
	}
	return 0;
}



