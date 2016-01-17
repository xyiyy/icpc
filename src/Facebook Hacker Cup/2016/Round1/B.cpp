//#####################
//Author:fraud
//Blog: http://www.cnblogs.com/fraud/
//#####################
//#pragma comment(linker, "/STACK:102400000,102400000")
#include <bits/stdc++.h>
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
typedef vector<PII> VII;
typedef vector<int> VI;
typedef pair<ll,int>PLI;
int w[100010];
ll dp[1000010];
priority_queue<PLI,vector<PLI>,greater<PLI> > q1;
priority_queue<ll,vector<ll>,greater<ll> > q2;
int main()
{
    ios::sync_with_stdio(false);
    #ifdef LOCAL
        freopen("in2.txt","r",stdin);
        freopen("out2.txt","w",stdout);

    #endif // LOCAL
    int t,cas = 1;
    scanf("%d",&t);
    while(t--){
        while(!q1.empty())q1.pop();
        while(!q2.empty())q2.pop();
        int l,n,m,d;
        scanf("%d%d%d%d",&l,&n,&m,&d);
        rep(i,n){
            scanf("%d",&w[i]);
        }
        rep(i,n)q1.push(mp(w[i],i));
        rep(i,l){
            PLI top = q1.top();
            dp[i] = top.first;
            q1.pop();
            q1.push(mp(top.first + w[top.second],top.second));
        }
        ll ans = 0;
        rep(i,l){
            if(q2.size()<m){
                ans = max(ans, dp[i] + d);
                q2.push(ans);
            }else{
                ll top = q2.top();
                q2.pop();
                ans = max(dp[i] + d,top+d);
                q2.push(ans);
            }
        }
        cout << "Case #" << cas++ << ": " << ans << endl;
    }
    return 0;
}

