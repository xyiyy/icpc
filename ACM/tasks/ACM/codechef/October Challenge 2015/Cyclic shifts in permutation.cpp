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

const int MAXN = 100010;
int a[MAXN],b[MAXN];
const ll mod = 1e9+7;
ll fac[MAXN];
int key[MAXN],size[MAXN],lson[MAXN],rson[MAXN];
int p[MAXN],del[MAXN];
int tot=0,tot1=0;
int n;
void init() {
    key[0] = size[0] = lson[0] = rson[0] = 0;
    tot = tot1 = 0;
}
int newnode(int k) {
    int r ;
    if(tot1) {
        r = del[tot1--];
    } else r = ++tot;
    key[r] = k;
    //sum[r] = k;
    p[r] = rand();
    size[r] = 1;
    lson[r] = rson[r] = 0;
    return r;
}

int change(int t,int l,int r) {
    size[t] = size[l] + size[r] + 1;
    //sum[t] = sum[l] + sum[r] + key[t];
    lson[t] = l;
    rson[t] = r;
    return t;
}

void splitsize(int t,int s,int *ret) {
    if(s<=0) {
        ret[0] = 0;
        ret[1] = t;
    } else if(s<=size[lson[t]]) {
        splitsize(lson[t],s,ret);
        ret[1] = change(t,ret[1],rson[t]);
    } else {
        splitsize(rson[t],s-size[lson[t]]-1,ret);
        ret[0] = change(t,lson[t],ret[0]);
    }
}
void splitkey(int t,int k,int *ret) {
    if(!t) {
        ret[0] = ret[1] = 0;
    } else if(k<key[t]) {
        splitkey(lson[t],k,ret);
        ret[1] = change(t,ret[1],rson[t]);
    } else {
        splitkey(rson[t],k,ret);
        ret[0] = change(t,lson[t],ret[0]);
    }
}
int merge(int t1,int t2) {
    if(!t1)return t2;
    if(!t2)return t1;
    if(p[t1]<p[t2])return change(t1,lson[t1],merge(rson[t1],t2));
    return change(t2,merge(t1,lson[t2]),rson[t2]);
}
void extgcd(ll a,ll b,ll &d,ll &x,ll &y) {
    if(!b) {
        d = a;
        x=1;
        y=0;
    } else {
        extgcd(b,a%b,d,y,x);
        y-=x*(a/b);
    }
}

ll inv(ll a,ll mod) {
    ll x,y,d;
    extgcd(a,mod,d,x,y);
    return d == 1 ? (x % mod + mod) % mod : -1;
}
ll infac[MAXN];
int vec[MAXN];
int bit[MAXN];
void add(int i,int x) {
    while(i <= n) {
        bit[i] += x;
        i += i&-i;
    }
}
int query(int x) {
    int ret = 0;
    while(x > 0) {
        ret += bit[x];
        x -= x&-x;
    }
    return ret;
}
vector<int> vp,vq;
vector<int>gao;
void dfs(int u,int &f){
    if(!u)return;
    if(lson[u])dfs(lson[u],f);
    vp[f] = key[u];
    f++;
    //cout << " " << key[u] << endl;
    if(rson[u])dfs(rson[u],f);
}
void debug(int u){
    if(!u)return;
    if(lson[u])debug(lson[u]);
    cout << u << " " << key[u] << " " << lson[u] << " " << rson[u] << " " << size[u]<< endl;
    if(rson[u])debug(rson[u]);
}
int kth(int x,int sz){
    int num = size[lson[x]] + 1;
    if(sz == num)return x;
    if(sz > num)return kth(x,sz-num);
    else return kth(x,sz);
}
int main() {
    ios::sync_with_stdio(false);
#ifdef LOCAL
    freopen("in.txt","r",stdin);
#endif // LOCAL
    int t;
    fac[0] = 1;
    rep2(i,1,MAXN-1) {
        fac[i] = fac[i-1] * i % mod;
        infac[i] = inv(fac[i],mod);
    }
    //rep(i,10)cout << fac[i] << " ";
    //cout << endl;
    //rep(i,10)cout << infac[i] << " ";
    //cout << endl;
    scanf("%d",&t);
    while(t--) {
        init();
        int k;
        scanf("%d%d",&n,&k);
        rep(i,n)scanf("%d",&a[i]);
        rep(i,n)scanf("%d",&b[i]);
        ll ans = 1;
        int root = vec[a[0]] = newnode(a[0]);
        rep2(i,1,n-1) root = merge(root,vec[a[i]] = newnode(a[i]));
        //rep2(i,1,n)cout << vec[i] << endl;
        int num = n - k;
        int now = n;
        int tmp[10];
        rep2(i,1,n)add(i,1);
        //rep()
        cout << "ok" << endl;
        rep(i,num) {
            //cout << i << endl;
            //cout << "ok" << i << endl;
            //cout << now - size[rson[vec[b[i]]]] << endl;
            int x = query(b[i]);
            //cout << b[i] << endl;
            ans = (ans + fac[now - 1] * (x - 1) % mod * infac[k-1]) % mod;
            //cout << x << endl;
            add(b[i],-1);
            debug(root);
            cout << endl;
            int f = now - size[rson[vec[b[i]]]];
            now --;
            int ff = f - (f - 1) / (k-1) * (k - 1);
            if(ff == 1){
                if(f == now + 1){
                    splitsize(root,f - 1,tmp);
                    root = tmp[0];
                    continue;
                }
                splitsize(root,f,tmp);
                if(size[tmp[0]] == 1){
                    root = tmp[1];
                    continue;
                }else{
                    splitsize(tmp[0],f - 1,tmp + 2);
                    root = merge(tmp[1],tmp[2]);
                }
                continue;
            }
            //int fff = k - ff - 1;
            x = kth(root,ff);
            if(f > k - 1){
                splitsize(root,f,tmp);
                splitsize(tmp[0],f-1,tmp+2);
                root = merge(tmp[1],tmp[2]);
                ff = (f - 1) / (k - 1);
                ff = f - 1 - ff * (k - 1);
                splitsize(root,k-1,tmp);
                splitsize(tmp[0],ff,tmp + 2);
                tmp[2] = merge(tmp[3],tmp[2]);
                root = merge(tmp[2],tmp[1]);
            }else{
                splitsize(root,f,tmp);
                if(size[tmp[0]] == 1){
                    root = tmp[1];
                    continue;
                }
                splitsize(tmp[0],f-1,tmp+2);
                if(tmp[1])root = merge(tmp[1],tmp[2]);
                else root = tmp[2];
            }

            //cout << f << endl;
            //cout << vec[b[i]] << " " << b[i] << " " << rson[vec[b[i]]] << endl;
            //splitsize(root,f,tmp);
            //cout << key[tmp[0]] << endl;
            //if(size[tmp[0]] == 1){
             //   root = tmp[1];
             //   continue;
            //}
            //splitsize(tmp[0],f - 1,tmp + 2);
            //if(tmp[1])root = merge(tmp[1],tmp[2]);
            //else root = tmp[2];
        }
        //cout << "ok" << endl;
        //cout << endl;
        debug(root);
        cout << endl;
        vp.resize(2 * k);
        vq.resize(k);
        gao.resize(k);
        int f = 0;
        rep2(i,n-k,n-1){
            gao[f] = vq[f] = b[i];
            f++;
        }
        //cout << "ok" << endl;
        //cout << root << endl;
        f = 0;
        dfs(root,f);
        //cout << "ok" << endl;
        rep(i,k) vp[i + k] = vp[i];
        //rep(i,k+k)cout << vp[i] << " ";
        //cout <<endl;
        f = 1;
        int x = vq[0];
        sort(gao.begin(),gao.end());
        for(int i=0;i<k;i++){
            if(gao[i] == x){
                ans += i;
                break;
            }
        }
        x = 0;
        for(int i=0;i<k;i++){
            //cout << " " <<vp[i] << endl;
            if(vq[0] == vp[i]){
                x = i;
                break;
            }
        }
        //cout << x << endl;
        rep(i,k){
            if(vp[x+i]!=vq[i])f = 0;
        }
        if(!f)ans = -1;
        cout << ans << endl;

    }
    return 0;
}

