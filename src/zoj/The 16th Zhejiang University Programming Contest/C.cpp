
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
int a[100010];
const int MOD = 1e9+7;
struct BIT{
    int sz,dir,bit[100010];
    void init(int n,int d){
        sz = n;
        dir = d;
        clr(bit,0);
    }
    void add(int i,int x){
        while(i && i <= sz){
            bit[i] += x;
            if(bit[i] >= MOD)bit[i] -= MOD;
            i += dir * (i & -i);
        }
    }
    int query(int i){
        int ret = 0;
        while(i && i <= sz){
            ret = (ret + bit[i]);
            if(ret >= MOD)ret -= MOD;
            i -= dir * (i & -i);
        }
        return ret;
    }
}dp[2];
int gao[100010];
int main()
{
    ios::sync_with_stdio(false);
    int t;
    cin >> t;
    gao[0] = 1;
    rep2(i,1,100009)gao[i] = (gao[i-1] << 1) %MOD;
    while(t--){
        int n;
        cin >> n;
        rep(i,n)cin >> a[i+1];
        ll ans = 0;
        dp[0].init(n,1);
        dp[1].init(n,-1);
        rep(i,2)dp[i].add(a[1],1);
        rep2(i,2,n){
            ans = (ans + 1LL * gao[n - i] * dp[0].query(a[i] - 1)) % MOD;//left
            ans = (ans + 1LL * gao[n - i] * dp[1].query(a[i] + 1)) % MOD;//right
            rep(j,2)dp[j].add(a[i],gao[i - 2]);
        }
        ans <<= 1;
        ans %= MOD;
        cout << ans <<endl;

    }
    return 0;
}
