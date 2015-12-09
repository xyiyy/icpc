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
ll ans = 0;
void dfs(ll l,ll r){
    if(l<0)return;
    if(r<l)return;
    if(l==0){
        if(ans==-1)ans = r;
        else ans = min(ans,r);
        return;
    }
    if(r>=ans&&ans!=-1)return;
    if((r-l+1)>(l))return;
    dfs(l-(r-l)-2,r);
    dfs(l,r+(r-l));
    dfs(l-(r-l)-1,r);
    dfs(l,r+(r-l)+1);
    return;
}
int main()
{
    ios::sync_with_stdio(false);
    ll l,r;
    while(cin>>l>>r){
        ans = -1;
        dfs(l,r);
        cout<<ans<<endl;
    }
    return 0;
}
