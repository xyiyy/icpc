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
int a[510*510];
int vis[510*510];
vector<int> vec;
int num[510*510];
vector<int>ans;
int main()
{
    ios::sync_with_stdio(false);
    #ifdef LOCAL
        freopen("in.txt","r",stdin);
    #endif // LOCAL
    int n;
    cin>>n;
    rep(i,n*n)cin>>a[i];
    int m = n*n;
    sort(a,a+m);
    //reverse(a,a+m);
    vec.pb(a[0]);
    int sz = 1;
    num[0] = 1;
    rep2(i,1,m-1){
        if(a[i]==a[i-1]){
            num[sz-1] ++;
        }else{
            vec.pb(a[i]);
            sz++;
            num[sz-1] = 1;
        }
    }
    int now = sz-1;
    rep(i,n){
        while(!num[now]){
            now--;
        }
        int f = vec[now];
        num[now]--;
        rep(j,ans.size()){
            int x = __gcd(f,ans[j]);
            x = lower_bound(vec.begin(),vec.end(),x) - vec.begin();
            num[x]-=2;
        }
        ans.pb(f);
    }
    rep(i,ans.size())cout << ans[i] << " ";
    cout << endl;



    return 0;
}
