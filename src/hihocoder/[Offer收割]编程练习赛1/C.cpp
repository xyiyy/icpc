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
priority_queue<int>pq;
PII p[110];
ll dp[10010];
int main()
{
    ios::sync_with_stdio(false);
    int T;
    cin >> T;
    while(T--){
        ll ans = 0;
        int n,m,k,t;
        cin >> n >> m >> k >> t;
        //for(int i = 0;i <= k;i++)dp[i] = 1LL << 59;
        rep(i,m){
            cin >> p[i].second;
        }
        rep(i,m)cin>>p[i].first;
        ll imp = 1LL << 59;
        bool ok = true;
        for(int now = 1;now <= n;now++){
            if(!ok)break;
            if(now == 1)dp[0] = 0;
            else dp[0] = dp[k];
            for(int i = 1 ; i <= k; i ++ )dp[i] = imp;
            sort(p,p+m);
            for(int i =0 ;i<m;i++){
                if(i!=0 && p[i].first == p[i-1].first)continue;
                int a = p[i].first;
                int b = p[i].second;
                for(int j = 0;j<k;j++){
                    int jj = min(k,j+a);
                    dp[jj] = min(dp[jj],dp[j] + b);
                }
            }
            rep(i,m){
                p[i].first /= t;
            }
            if(dp[k] == imp)ok = false;
        }
        if(!ok)cout << "No Answer" <<endl;
        else cout << dp[k] << endl;

    }



    return 0;
}

