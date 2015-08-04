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
#define MP(X,Y) make_pair(X,Y)
#define PB(X) push_back(X)
#define REP(X,N) for(int X=0;X<N;X++)
#define REP2(X,L,R) for(int X=L;X<=R;X++)
#define DEP(X,R,L) for(int X=R;X>=L;X--)
#define CLR(A,X) memset(A,X,sizeof(A))
#define IT iterator
typedef long long ll;
typedef pair<int,int> PII;
typedef vector<PII> VII;
typedef vector<int> VI;
ll C[1000010];
ll MOD = 1000000007;
void gcd(ll a,ll b,ll &d,ll &x,ll &y){
    if(!b){
        d=a;x=1;y=0;
    }else{
        gcd(b,a%b,d,y,x);
        y-=x*(a/b);
    }
}
ll inv(ll a){
    ll d,x,y;
    gcd(a,MOD,d,x,y);
    return d==1?(x+MOD)%MOD:-1;
}
bool check(int x,int a,int b){
    int r;
    while(x){
        r=x%10;
        x/=10;
        if(r!=a&&r!=b)return 0;
    }
    return 1;
}
int gao[1000010];
int main()
{
	ios::sync_with_stdio(false);
    int t;
    for(int i=1;i<=1000000;i++){
        gao[i]=inv(i);
    }
    cin>>t;
    while(t--){
        int a,b,n;
        cin>>a>>b>>n;
        C[0]=1;
        C[n]=1;
        for(int i=1;i<(n+1)/2;i++){
            C[n-i]=C[i]=C[i-1]*(n+1-i)%MOD*gao[i]%MOD;
            //cout<<C[i]<<endl;
        }
        if(a>b)swap(a,b);
        ll ans=0;
        int sum=a*n;
        for(int i=0;i<=n;i++){
            if(check(sum,a,b)){
                ans+=C[i];
                if(ans>MOD)ans-=MOD;
            }
            sum+=b-a;
        }
        cout<<ans<<endl;
    }
	return 0;
}


