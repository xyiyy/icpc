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
char a[100010];
int vis[26];
ll dp[100010];
int b[100010];
ll MOD = 1000000007;
ll dp1[100010];
ll dp2[100010];
int p[100010];
int main()
{
	ios::sync_with_stdio(false);
	int t;
	int cas=1;
	dp[0]=1;
	for(int i=1;i<100010;i++){
        dp[i]=dp[i-1]*26%MOD;
	}
	scanf("%d",&t);
	while(t--){
        scanf("%s",a);
        int len =strlen(a);
        CLR(vis,0);
        int num=0;
        int cnt=0;
        for(int i=0;i<len;i++){
            a[i]-='a';
            b[i+1]=a[i];
        }
        for(int i=0;i<len;i++){
            if(vis[a[i]]==num){
                vis[a[i]]++;
                cnt++;
            }
            if(cnt==26){
                num++;
                cnt=0;
            }
        }
        int minn =INF;
        cnt=26-cnt;
        for(int i=0;i<=len;i++)dp1[i]=INF;
        for(int i=0;i<=len;i++)dp2[i]=0;
        for(int i=0;i<26;i++)p[i]=len+1;
        dp2[len+1]=1;
        dp1[len+1]=1;
        for(int i=len;i>=0;i--){
            for(int j=0;j<26;j++){
                if(dp1[p[j]]+1<dp1[i]){
                    dp1[i]=dp1[p[j]]+1;
                    dp2[i]=0;
                }
                if(dp1[i]==dp1[p[j]]+1){
                    dp2[i]=dp2[i]+dp2[p[j]];
                    while(dp2[i]>=MOD)dp2[i]-=MOD;
                }
            }
            if(i)
            p[b[i]]=i;
        }
       // cout<<cnt<<endl;
        //int ans = dp[num]*cnt%MOD;
        printf("Case #%d:\n",cas++);
        printf("%d %d\n",num+1,dp2[0]);
	}
	return 0;
}


