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

int main()
{
	ios::sync_with_stdio(false);
    ll n=1000000-1;
    ll k=20;
    ll m = 1000000000-1;
    //ll n,m,k;
    //cin>>n>>k>>m;
    ll num=(1LL<<k)-1;
    ll ans=0;
    ll temp;
    ll ret;
    for(ll i=1;i<=n;i++){
        k=num;
        ret=1;
        temp =i;
        while(k){
            if(k&1)ret=ret*temp%m;
            temp=temp*temp%m;
            k>>=1;
        }
        ans=ans+ret;
        ans%=m;
    }
    cout<<ans<<endl;
	return 0;
}



