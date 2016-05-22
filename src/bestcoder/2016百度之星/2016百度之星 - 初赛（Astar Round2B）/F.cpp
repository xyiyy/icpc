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
#define mp(X,Y) make_pair(X,Y)
#define pb(X) push_back(X)
#define rep(X,N) for(int X=0;X<N;X++)
#define rep2(X,L,R) for(int X=L;X<=R;X++)
#define dep(X,R,L) for(int X=R;X>=L;X--)
#define clr(A,X) memset(A,X,sizeof(A))
#define IT iterator
typedef long long ll;
typedef pair<int,int> PII;
typedef vector<PII> vii;
typedef vector<int> vi;
int dp[10010];
int a[10010];
int dp2[10010];
int L[20010];
int R[20010];
int main()
{
    ios::sync_with_stdio(false);
    int n;
    while(scanf("%d",&n)!=EOF){
        rep(i,n){
            scanf("%d",&a[i]);
        }
        int m = n + 1;
        rep(i,n){
            int ans = 0;
            int minn = INF;
            rep(j,n){
                if(a[i] > a[j])dp[j] = -1;
                else if(a[i] < a[j])dp[j] = 1;
                else dp[j] = 0;
            }
            minn = min(dp[0],0);
            for(int j = 1; j < n ; j ++){
                dp[j] += dp[j - 1];
                minn = min(dp[j],minn);
            }
            rep(j,n)dp[j] -= minn;
            rep(j,n+1)dp2[j] = 0;
            rep(j,i)dp2[dp[j]]++;
            dp2[0 - minn]++;
            for(int j = i;j<n;j++){
                ans += dp2[dp[j]];
            }
            if(i)printf(" ");
            printf("%d",ans);

            /*
            rep2(j,0,m)L[j] = R[j] = 0;
            int now = n;
            rep(j,i){
                if(a[i] > a[j])now++;
                else if(a[i] < a[j])now --;
                L[now]++;
            }
            now = n;
            for(int j = i + 1; j < n ; j ++){
                if(a[j] > a[i])now++;
                else if(a[j] < a[i])now--;
                R[now]++;
            }
            rep2(j,0,m){
                ans += L[j] * R[j];
            }
            ans += L[n] + R[n];
            if(i)cout << " " ;
            cout  << ans ;*/
        }
        puts("");


    }
    return 0;
}
