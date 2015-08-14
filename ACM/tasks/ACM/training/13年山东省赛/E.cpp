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
#define MAXN 100010
int dp[1010];
int a[MAXN];
int dp1[MAXN],dp2[MAXN];
int main()
{
	ios::sync_with_stdio(false);
	int n;
	char s;
	while(cin>>n){
        for(int i=0;i<n;i++){
            cin>>s;
            a[i]=s-'a';
        }
        CLR(dp,0);
        CLR(dp1,0);
        for(int i=0;i<n;i++){
            for(int j=0;j<a[i];j++) dp1[i]+=dp[j];
            while(dp1[i]>=2012)dp1[i]-=2012;
            dp[a[i]]+=dp1[i]+1;
            while(dp[a[i]]>=2012)dp[a[i]]-=2012;
        }
        CLR(dp,0);
        CLR(dp2,0);
        for(int i=n-1;i>=0;i--){
            for(int j=0;j<a[i];j++) dp2[i]+=dp[j];
            while(dp2[i]>=2012)dp2[i]-=2012;
            dp[a[i]]+=dp2[i]+1;
            while(dp[a[i]]>=2012)dp[a[i]]-=2012;
        }
        int ans=0;
        for(int i=0;i<n;i++){
            ans=(ans+dp1[i]*dp2[i])%2012;
        }
        cout<<ans<<endl;
	}
	return 0;
}


