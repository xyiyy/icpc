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
double a[10019];
int p[10010];
bool cmp(int x,int y){
    return a[x] < a[y];
 }
int main()
{
    ios::sync_with_stdio(false);
    #ifdef LOCAL
        freopen("in.txt","r",stdin);
    #endif // LOCAL
    int n;
    while(cin>>n){
        rep(i,n)cin>>a[i];
        rep(i,n)p[i] = i;
        sort(p,p+n,cmp);
        vector<int> ans;
        int num  = 0;
        double last = 0;
        rep(i,n){
            if(a[p[i]] < 0){
                if(num&1){
                    num = 0;
                    if(a[p[i]] * a[p[i-1]] > 1.0){
                        ans.pb(p[i]);
                        ans.pb(p[i-1]);
                    }
                }else{
                    last = a[p[i]];
                    num = 1;
                }
            }
            else if(a[p[i]] > 1){
                ans.pb(p[i]);
            }
        }
        int sz = ans.size();
        if(sz == 0){
            double tmp1 = a[p[n-1]];
            double tmp2 = a[p[0]] * a[p[1]];
            if(tmp1 >= tmp2){
                ans.pb(p[n-1]);
            }else {
                ans.pb(p[0]);
                ans.pb(p[1]);
            }
        }
        sz = ans.size();
        cout << sz <<endl;
        sort(ans.begin(),ans.end());
        rep(i,sz)cout << ans[i] + 1<<" ";
        cout << endl;
    }
    return 0;
}
