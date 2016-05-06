
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
char s[1000010];
int dp[20][1000010];
const int maxn = 1000010;
void init(){
    rep2(i,1,19){
        rep(j,1000010){
            int p = j + (1 << (i - 1));
            p = min(maxn - 1 , p);
            dp[i][j] = min(dp[i-1][j],dp[i-1][p]);
        }
    }
}
int query(int l,int r){
    int k = log2(r - l + 1);
    return min(dp[k][l],dp[k][r - (1<<k) + 1]);
}
int last[maxn+maxn];
int num[maxn+maxn];

int main()
{
    ios::sync_with_stdio(false);
    cin >> s + 1;
    int n = strlen(s + 1);
    rep2(i,1,n){
        if(s[i] == '(')dp[0][i] = dp[0][i - 1] + 1;
        else dp[0][i] = dp[0][i - 1] - 1;
    }
    init();
    ll ans = 0;
    num[maxn] = 0;
    clr(last,-1);
    last[maxn] = 0;
    rep2(i,1,n){
        int px = dp[0][i] + maxn;
        int p = last[px];
        if(p == -1){
            last[px] = i;
            num[px] = 0;
            continue;
        }
        bool ok = (query(p,i) >= dp[0][i]);
        if(ok){
            num[px]++;
            ans += num[px];
        }else{
            num[px] = 0;
            last[px] = i;
        }
    }
    cout << ans << endl;
    return 0;
}
