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
const int maxn = 10000100;
int tot;
int is_prime[maxn];
int mu[maxn];
int prime[maxn];
//const int Maxn = 15000010;
int f[maxn];
//int F[maxn]; //f[]的前缀和
int g(int x){
    if (x == 1)return 1;
    else return 0;
}
int G(int x){
    return 1;
}
void init(int n){ //n<=1000000直接算
    for(int i = 1; i <= n; i++){
        f[i] = mu[i] + f[i-1];
    }
    /*for(int i=1;i<=n;i++){ //f[i]存除了i之外因子的贡献值
        f[i]=(g(i)-f[i]); //获得真正的f[i],g(i)=sigma[d|i](f[d])
        //if(f[i]<0) f[i]+=mod;
        for(int j=i+i;j<=n;j+=i) //对除了自身的倍数做贡献
            f[j]=(f[j]+f[i]);
        F[i]=(F[i-1]+f[i]);
    }*/
}
map<ll,int> mp;
ll cal(ll n){
    if(n<=10000000) return f[n];
    if(mp[n]) return mp[n];
    ll tmp=0; //G(n)=sigma[1…n]g(i)
    for(ll L=2,R;L<=n;L=R+1){ //x属于[L,R],n/x均相同
        R=n/(n/L);
        tmp+=(R-L+1)*cal(n/L);
    }
    //if(tmp<0) tmp+=mod;
    mp[n]=1-tmp;
    return 1-tmp;
}

void Moblus()
{
    tot = 0;
    mu[1] = 1;
    for(int i = 2; i < maxn; i++){
        if(!is_prime[i])
        {
            prime[tot++] = i;
            mu[i] = -1;
        }

        for(int j = 0; j < tot && i*prime[j] < maxn; j++)
        {
            is_prime[i*prime[j]] = 1;
            if(i % prime[j])
            {
                mu[i*prime[j]] = -mu[i];
            }
            else
            {
                mu[i*prime[j]] = 0;
                break;
            }
        }
    }

}

ll get_(ll mid)
{
    ll num = 0;
    for(ll i = 1; i*i <= mid; i++){
        num += (ll)mu[i]*(mid/(i*i));
    }
    //cout << num << " ok" << endl;
    return num;
}
int main()
{
    ios::sync_with_stdio(false);
    int T;
  //  freopen("in.txt","r",stdin);
    Moblus();
    init(10000000);
    ll maxr = 10000000000LL;
    cin >> T;
    scanf("%d",&T);
    while(T--){
        ll k,d;
        cin >> d >> k;
        ll numl = 0,numr;
        if(d == 0){
            ll l = 1;
            ll r = min(5 * k,maxr);
            numr = r - get_(r);
            while(l <= r){
                ll mid = (double)(k - numl) / (numr - numl) * (r - l) + l;
                mid = max(l,mid);
                mid = min(mid,r);
                //ll mid = (l + r) >> 1;
                ll num = mid - get_(mid);
                if(num < k){
                    l = mid + 1;
                    numl = num;
                }else{
                    r = mid - 1;
                    numr = num;
                }
            }
            cout << l << endl;
        }else{
            ll l = 1;
            ll r = min(5 * k,maxr);
            ll p = cal(r);
            ll num = get_(r);
            ll gao;
            if(d == -1){
                gao = (num - p) / 2;
            }else gao = (num + p) / 2;
            numr = gao;
            while(l <= r){
                ll mid = (double)(k - numl) / (numr - numl) * (r - l) + l;;
                mid = max(l,mid);
                mid = min(mid,r);
                num = get_(mid);
                //cout << mid << endl;
                p = cal(mid);
                if(d == -1){
                    gao = (num - p) / 2;
                }else gao = (num + p) / 2;
                if(gao < k){
                    l = mid + 1;
                    numl = gao;
                }else{
                    r = mid - 1;
                    numr = gao;
                }
                //cout<<l <<  " " << r << endl;
            }
            cout << l << endl;
        }
        //cout << l << endl;
        //scanf("%lld",&k);
        /*ll l = 1;
        ll r = 2*k+1;
        while(l <= r){
            ll mid = (l+r)>>1;
            ll num = get_(mid);
            if(num < k)
                l = mid + 1;
            else
                r = mid - 1;
        }
        printf("%lld\n",l);*/
    }
    return 0;
}

