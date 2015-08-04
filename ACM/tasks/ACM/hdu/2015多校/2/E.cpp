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
#define zero(x)((x>0? x:-x)<1e-15)
int const MAXN = 100;
double a[MAXN][MAXN];
double b[MAXN][MAXN];
int g[53][53];
       int N, M;
double det(double a[MAXN][MAXN], int n) {
    int i, j,k, sign = 0;
    double ret = 1, t;
    for (i =0; i < n; i++)
        for(j = 0; j < n; j++)
           b[i][j] = a[i][j];
    for (i =0; i < n; i++) {
        if(zero(b[i][i])) {
           for (j = i + 1; j < n; j++)
               if (!zero(b[j][i]))
                   break;
           if (j == n)
               return 0;
           for (k = i; k < n; k++)
               t = b[i][k], b[i][k] = b[j][k], b[j][k] = t;
           sign++;
        }
        ret*= b[i][i];
        for(k = i + 1; k < n; k++)
           b[i][k] /= b[i][i];
        for(j = i + 1; j < n; j++)
           for (k = i + 1; k < n; k++)
               b[j][k] -= b[j][i] * b[i][k];
    }
    if (sign& 1)
        ret =-ret;
    return ret;
}
double gao(){
	
	for(int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) a[i][j] = 0;
    }
    for(int i = 0; i < N; i++) {
       int d = 0;
       for (int j = 0; j < N; j++) if (g[i][j]) d++;
    	a[i][i] = d;
    }
    for(int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            if (g[i][j]) a[i][j] = -1;
        }
    }
    double ans = det(a, N - 1);
    return ans;
}
int From[1010];
int To[1010];
int main() {
    int cas;
    while (scanf("%d%d",&N,&M)!=EOF) {
        for (int i = 0;i < N; i++) {
           for (int j = 0; j < N; j++) {
               g[i][j] = 0;
            }
        }
        for(int i=0;i<M;i++){
           scanf("%d%d", &From[i], &To[i]);
           From[i]--;To[i]--;
           g[From[i] ][To[i]] = g[To[i]][From[i]] = 1;
        }
        double ans = 0;
        for(int i=0;i<M;i++){
        	g[From[i]][To[i]] = g[To[i]][From[i]] = 0;
        	ans += gao();
        }
        ans/= 2;
        
        
       printf("%0.0lf\n", ans);
    }
    return 0;
}
/*ll C[1010][110];
const ll MOD = 998244353;
vector<int>G[110];
ll dp[20][410];
vector<PII>state[21];
vector<int>g[21];
int main()
{
	ios::sync_with_stdio(false);
	int n;
	for(int i=0;i<1010;i++){
		C[i][0] = 1;
		for(int j=0;j<=i;j++){
			C[i][j] = C[i-1][j]+C[i-1][j-1];
			if(C[i][j]>=MOD)C[i][j] -= MOD;
		}
	}
	while(cin>>n>>m){
		int u,v;
		for(int i=0;i<n;i++)G[i].clear();
		for(int i=0;i<m;i++){
			cin>>u>>v;
			u--;v--;
			maxx = max(u,v);
			minn = min(u,v);
			G[maxx].PB(minn);
			g[maxx].PB((1<<minn)|(1<<maxx));
		}
		/*int tot = (1<<n);
		for(int i=0;i<n;i++){
			for(int j=0;j<n;j++){
				for(int k=0;k<)
		for(int i=0;i<n;i++){
			state[i].PB(MP(0,0));
			for(int j=0;j<G[i].size();j++){
				int sz = state[i].size();
				for(int k=0;k<sz;k++){
					state[i].PB(MP(state[i][k].first+1,state[i][k].second|g[i][j]));
					//state[i].PB(state[i][k]|(1<<G[i][j]));
				}
			}
			//state[i].PB(0);
		}
			for(int i=0;i<n;i++){
			int tot = (1<<(i+1));
			int d = (i+1)*i/2;
			for(int j=0;j<tot;j++){
				for(int k=0;)
		cout<<dp[n-1][m-n]<<endl; 
		
	}            	
	return 0;
}
*/


