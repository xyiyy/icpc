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
const  int MAXN = 100010;
int vis[MAXN],prime[MAXN],n_prime,phi[MAXN];
void Eular(){
    n_prime = 0;
    phi[1] = 1;
    for(int i=2;i<MAXN;i++){
        if(!vis[i]){
            prime[n_prime++] = i;
            phi[i] = i-1;
        }
        for(int j = 0;j<n_prime && i * prime[j] < MAXN;j++){
            vis[i*prime[j]] = 1;
            if(i%prime[j]) phi[i*prime[j]] = phi[i] * phi[prime[j]];
            else{
                phi[i * prime[j]] = phi[i] *prime[j];
                break;
            }
        }
    }
}
typedef unsigned long long ull;

int main()
{
    ios::sync_with_stdio(false);
    #ifdef LOCAL
        freopen("in.txt","r",stdin);
    #endif // LOCAL
    Eular();
    int t;
    scanf("%d",&t);
    while(t--){
        int n;
        scanf("%d",&n);
        ull mm = 1;
        ull hm = 1;
        ull tmp = n;
        for(int i=0;prime[i]*prime[i]<=tmp&&i<n_prime;i++){
            if(tmp%prime[i]==0){
                ull num = 0;
                while(tmp%prime[i]==0){
                    tmp/=prime[i];
                    num++;
                }
                ull sum = 1;
                ull p = 1;
                rep(j,num){
                    p *=prime[i];
                    sum += p * p;
                }
                mm *= sum;
                hm *= p * (num+1);
            }
        }
        if(tmp!=1){
            mm *= tmp * tmp + 1ULL;
            hm *= tmp * 2ULL;
        }
        cout << mm - hm <<endl;

    }
    return 0;
}

