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
ll p;
ll a[100010];

int main()
{
    ios::sync_with_stdio(false);
    #ifdef LOCAL
        freopen("the_price_is_correct (1).txt","r",stdin);
        freopen("out.txt","w",stdout);
    #endif // LOCAL
    int t;
    scanf("%d",&t);
    //cin>>t;
    int cas = 1;
    while(t--){
        int n;
        //cin>>n;
        scanf("%d",&n);
        int temp = 0;
        scanf("%d",&temp);
        p = temp;
        rep(i,n){
            scanf("%d",&temp);
            a[i+1]=temp;
        }
        rep2(i,1,n){
            a[i] += a[i - 1];
        }
        ll ans = 0;
        int num = 0;
        a[n + 1] = 1LL << 60;
        rep2(i,1,n){
            num = upper_bound(a, a + n + 2, p + a[i-1]) - a - i;
            ans += num;
        }
        cout << "Case #" <<cas++ << ": " << ans << endl;

    }
    return 0;
}



