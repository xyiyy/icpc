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

bool check(int n){
    ll tmp = (ll) n * n;
    if(tmp % 4 == 3)return 0;
    int f = tmp % 8;
    if(f == 3 || f == 6 || f == 7)return 0;
    f = tmp % 16;
    if(f == 3 || f == 6 || f == 7 || f == 11 || f == 11 || f == 12 || f == 14 || f == 15) return 0;
    ll a = 1, b = n - 1;
    ll t;
    t = tmp - b * b;
    a = sqrt(t) + 1e-8;
    if(a * a == t)return 1;
    b--;
    t = tmp - b * b;
    a = sqrt(t) + 1e-8;
    if(a * a == t)return 1;
    return 0;
    /*while (a <= b){

        a = sqrt(tmp - b * b) + 1e-8;
        t = a * a + b * b;
        if(t == tmp)return 1;
        //if(t > tmp)b = floor(sqrt(tmp - a * a));
        //else a = ceil(sqrt(tmp - b * b));
        //cout << a << " " << b << endl;
        b--;
    }*/
    return 0;

}
bool vis[10000010];
int main()
{
    ios::sync_with_stdio(false);
    #ifdef LOCAL
        freopen("in.txt","r",stdin);
    #endif // LOCAL
    int t;
    int maxn = 6001000;
    int m  = sqrt(maxn) + 1;
    rep2(i,1,m){
        rep2(j,i+1,m){
            int f = 0;
            if(i & 1)f++;
            if(j & 1)f++;
            if(f==2)continue;
            if(__gcd(i,j)==1){
                t = i * i + j * j;
                if(t>maxn)continue;
                vis[t] = 1;
            }
        }
    }
    //int maxn = 5000000;
    rep2(i,1,maxn){
        if(vis[i])
        for(int j = i + i;j<maxn;j+=i){
            vis[j] = 1;
        }
    }
   /* ans = 0;
    rep2(i,1,60){
        rep2(j,1,i-1){
            t = i * i - j * j;
            int tmp = sqrt(t) + 1e-8;
            if(tmp * tmp == t){
                ans++;
                cout << i << " " << j << " " << tmp << endl;
                break;
            }
        }
    }
    cout << ans << endl;*/
    scanf("%d",&t);
    while(t--){
        int n;
        scanf("%d",&n);
        if(vis[n]){
            puts("YES");
        }else puts("NO");
    }
    return 0;
}

