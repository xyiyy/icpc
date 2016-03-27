
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
ll dp[1010][510];
int a[1010];
 class EllysSocks{
 public:
    int getDifference(vector <int> S, int P){
        ll ans = 1LL <<50;
        rep(i,1010){
            rep(j,510)dp[i][j] = ans;
        }
        int n = S.size();
        rep(i,n)a[i+1] = S[i];
        sort(a+1,a+1+n);
        dp[0][0] = 0;
        rep2(i,1,n){
            rep2(j,0,P)dp[i][j] = dp[i-1][j];
            if(i>1)
            dep(j,P,1){
                dp[i][j] = min(max(dp[i-2][j-1],(ll)a[i] - a[i-1]),dp[i][j]);
                //cout << i << " " << j  << " " << dp[i][j] << endl;
            }
        }
        rep2(i,1,n)ans = min(ans,dp[i][P]);
        return ans;
    }
};


int main()
{
    ios::sync_with_stdio(false);
    EllysSocks *p = new EllysSocks();
    vector<int>vs;
    int n,m;
    cin >> n >> m;
    rep(i,n){
        int p;
        cin >> p;
        vs.pb(p);
    }
    cout << p->getDifference(vs,m);
    return 0;
}
/*
14 7
5 2 8 8 6 7 3 7 4 2 4 5 3 6


6 3
42 37 84 36 41 42

*/

