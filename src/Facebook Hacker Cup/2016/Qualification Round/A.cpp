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
int x[10010],y[10010];
map<int,int>ms;
int dis(int i,int j){
    return (x[i] - x[j]) *(x[i] - x[j]) +(y[i] - y[j]) * (y[i] - y[j]) ;
}
int main()
{
    ios::sync_with_stdio(false);
    #ifdef LOCAL
        freopen("boomerang_constellations.txt","r",stdin);
        freopen("in.txt","w",stdout);

    #endif // LOCAL
    int t;
    int cas = 1;
    cin>>t;
    while(t--){
        int n;
        cin>>n;
        rep(i,n){
            cin>>x[i]>>y[i];
        }
        ll ans = 0;
        rep(i,n){
            ms.clear();
            rep(j,n){
                ms[dis(i,j)]++;
            }
            for(auto it = ms.begin();it!=ms.end();it++){
                int tmp = it->second;
                ans = ans + (tmp - 1) * tmp / 2;
            }
        }
        cout << "Case #"<<cas++<<": "<<ans << endl;
    }
    return 0;
}
