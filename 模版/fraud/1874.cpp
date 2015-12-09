
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
const ll MOD = 1000000007;
ll fast_mod(ll n,ll m){
    ll ret=1;
    while(m){
        if(m&1)ret = ret*n%MOD;
        n=n*n%MOD;
        m>>=1;
    }
    return ret;
}
void extgcd(ll a,ll b,ll &d,ll &x,ll &y){
    if(!b){
        d=a;x=1;y=0;
    }else{
        extgcd(b,a%b,d,y,x);
        y-=x*(a/b);
    }
}
ll inv(ll a){
    ll d,x,y;
    extgcd(a,MOD,d,x,y);
    return d==1?(x+MOD)%MOD:-1;
}

int main()
{
	ios::sync_with_stdio(false);
	int a,b,c;
	while(cin>>a>>b>>c){
        if(a<b){
            cout<<0<<endl;
            continue;
        }
        ll ans=fast_mod(c,b);
        for(int i=1;i<=b;i++){
            ans=ans*(a-i+1)%MOD*inv(i)%MOD;
        }
        cout<<ans<<endl;
	}
	return 0;
}


