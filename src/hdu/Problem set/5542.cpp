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
int a[1010];
int p[1010];
int b[1010];
const int MOD = 1000000007;
struct BIT{
    int bit[1010];
    int sz;
    void init(int n){
        sz = n;
        rep(i,n+10)bit[i] = 0;
    }
    void add(int i,int x){
        while(i<=sz){
            bit[i]+=x;
            while(bit[i]>=MOD)bit[i]-=MOD;
            i += i & -i;
        }
    }
    int sum(int i){
        ll ret = 0;
        while(i > 0){
            ret += bit[i];
            i -= i & -i;
        }
        return ret % MOD;
    }
}T[1010];

int main()
{
    ios::sync_with_stdio(false);
    #ifdef LOCAL
       // freopen("in.txt","r",stdin);
    #endif // LOCAL
    int t,cas = 1;
    scanf("%d",&t);
    while(t--){
        int n,m;
        scanf("%d%d",&n,&m);
        //rep(i,m+1)T[i].init(n);
        rep(i,n)scanf("%d",&a[i]);
        rep(i,n)b[i] = a[i];
        sort(b,b+n);
        int sz = unique(b,b+n) - b;
        rep(i,n){
            int idx = lower_bound(b,b+sz,a[i]) - b;
            p[i] = idx + 1;
        }
        rep(i,m+1)T[i].init(sz);
        rep(i,n){
            rep2(j,1,min(i+1,m)){
                if(j==1)T[j].add(p[i],1);
                else{
                    int temp = T[j-1].sum(p[i]-1);
                    T[j].add(p[i],temp);
                }
            }
        }
        int ans = T[m].sum(sz);
        cout << "Case #"<< cas++ << ": " << ans << endl;
    }

    return 0;
}

