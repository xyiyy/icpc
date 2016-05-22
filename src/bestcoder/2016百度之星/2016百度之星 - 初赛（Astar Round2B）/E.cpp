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
ll dp[100010];
PII seg[100010];
priority_queue<int,vector<int>,greater<int> >q;
int main()
{
    ios::sync_with_stdio(false);
    int n,m,k;
    while(cin >> n >> k >> m){
        rep2(i,1,n){
            cin >> a[i];
            dp[i] = dp[i - 1] + a[i];
        }
        int u,v;
        rep(i,m){
            cin >> u >> v;
            seg[i].first = u;
            seg[i].second = v;
        }
        sort(seg,seg+m);
        ll ans = 0;
        int j = 0;
        while(!q.empty())q.pop();
        rep2(i,1,n){
            while(j < m && seg[j].first <= i){
                q.push(seg[j].second);
                j++;
            }
            while(q.size() > k)q.pop();
            if(q.size() == k){
                ans = max(ans , dp[q.top()] - dp[i-1]);
            }
        }
        cout << ans << endl;

    }
    return 0;
}
