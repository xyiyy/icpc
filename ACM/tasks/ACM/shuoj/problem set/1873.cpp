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
ll fac[100010];
int main()
{
	ios::sync_with_stdio(false);
    fac[0]=1;
    for(int i=1;i<100010;i++){
        fac[i]=fac[i-1]*i%MOD;
    }
    for(int i=1;i<100010;i++)fac[i]=fac[i-1]*fac[i]%MOD;
    int n,m;
    while(cin>>n>>m){
        if(n==0)cout<<fac[m]<<endl;
        else cout<<fac[m]*inv(fac[n-1])%MOD<<endl;
    }
	return 0;
}



