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
int l[110];
int r[110];
int p[110];
int h[110];
int dp[110][110];
int dpl[110];
int dpr[110];
/*int dfs(int lx,int rx,int len){
    if(rx-lx<len)return dp[lx][rx];
    if(rx>r[lx])
    dp[lx][rx]=min(dp[lx][rx],dp[lx][r[lx]]+dfs(r[lx]+1,rx,len));
    if(lx<l[rx])
    dp[lx][rx]=min(dp[lx][rx],dp[l[rx]][rx]+dfs(lx,l[rx]-1,len));
}*/
int main()
{
	ios::sync_with_stdio(false);
    int n;
    while(cin>>n){
        for(int i=0;i<n;i++){
            for(int j=0;j<n;j++){
                dp[i][j]=INF;
            }
        }
        for(int i=0;i<n;i++){
            cin>>p[i]>>h[i];
            dpl[i]=i;
            dpr[i]=i;
        }
        for(int i=0;i<n;i++){
            int maxx = p[i]+h[i];
            r[i]=i;
            //int maxid =i;
            for(int j=i+1;j<n;j++){
                if(maxx>p[j]){
                    r[i]=j;
                }
                else break;
                maxx = max(maxx , p[j]+h[j]);
            }
        }
        for(int i=n-1;i>=0;i--){
            int minn  = p[i]-h[i];
            l[i]=i;
            for(int j= i-1;j>=0;j--){
                if(minn < p[j]){
                    l[i]=j;
                }else break;
                minn =min(minn ,p[j]-h[j]);
            }
        }
        for(int i=0;i<n;i++){
            for(int j=i;j<=r[i];j++){
                dp[i][j]=1;
            }
        }
        for(int i=n-1;i>=0;i--){
            for(int j=i;j>=l[i];j--){
                dp[j][i]=1;
            }
        }
        int minn=INF;
        for(int len=1;len<n;len++){
            for(int i=0;i<n&&i+len<n;i++){
                if(dp[i][i+len]==1)continue;
                if(l[i+len]<=i)dpl[i]=i+len;
                if(r[i]>=i+len)dpr[i+len]=i;
                if(dpl[i]<i+len)dp[i][i+len]=min(dp[i][i+len],dp[dpl[i]+1][i+len]+1);
                if(dpr[i+len]>i)dp[i][i+len]=min(dp[i][i+len],dp[i][dpr[i+len]-1]+1);
               // cout<<i<<" "<<i+len<<endl;
                //dp[i][i+len]=min(dfs(i,i+len,len),dp[i][i+len]);
            }
        }
        cout<<dp[0][n-1]<<endl;
        /*dp[0]=1;
        for(int i=0;i<n;i++){
        	for(int j=i;j>=l[i];j--){
        		if(j){
        			dp[i]=min(dp[j-1]+1,dp[i]);
        		}else{
        			dp[i]=1;
        		}
        	}
        	if(i){
        		for(int j=i;j<=r[i];j++){
        			dp[j]=min(dp[i-1]+1,dp[j]);
        		}
        	}else{
        		for(int j=i;j<=r[i];j++){
        			dp[j]=1;
        		}
        	}
        }
        cout<<dp[n-1]<<endl;*/
    }

	return 0;
}


