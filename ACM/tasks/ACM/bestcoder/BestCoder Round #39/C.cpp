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
const int MOD = 10007;
vector<int>vec[10010];
int dp[10010];
int num[10010];
int a[10010];
int gao[10010];
int main()
{
	ios::sync_with_stdio(false);
	for(int i=1;i<10001;i++){
        for(int j=1;j*j<=i;j++){
            if(i%j==0){
                vec[i].PB(j);
                if(j*j==i)continue;
                vec[i].PB(i/j);
            }
        }
        sort(vec[i].begin(),vec[i].end());
	}
    int n;
    while(cin>>n){
        CLR(dp,0);
        int ans=0;
        CLR(num,0);
        CLR(gao,0);
        for(int i=0;i<n;i++){
            cin>>a[i];
            for(int j=0;j<vec[a[i]].size();j++){
                int v=vec[a[i]][j];
                num[v]++;
            }
        }
        for(int i=10000;i>1;i--){
            if(!num[i])continue;
            gao[i]%=MOD;
            num[i]%=MOD;
            dp[i]=(num[i]*num[i]%MOD+2*num[i]*gao[i]%MOD)%MOD;
            //if(dp[i])cout<<i<<" "<<dp[i]<<endl;
            dp[i]=(dp[i]+MOD)%MOD;
            dp[i]=dp[i]*i%MOD;
            dp[i]=dp[i]*(i-1)%MOD;
            for(int j=0;j<vec[i].size();j++){
                int v=vec[i][j];
                num[v]-=num[i];
                gao[v]+=num[i];
            }
        }
        dp[1]=0;
        for(int i=1;i<=10000;i++){
            ans=(ans+dp[i])%MOD;
        }
        cout<<ans<<endl;
    }
	return 0;
}



