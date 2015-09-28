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
typedef vector<PII> VII;
typedef vector<int> VI;
int l[110],r[110],p[110];
bool cmp(int x,int y){
    return l[x]<l[y];
}
int main(){
    ios::sync_with_stdio(false);
    int t;
    int cas = 1;
    cin>>t;
    while(t--){
        int n;
        int a,b,len;
        cin>>n>>a>>b>>len;
        rep2(i,1,n)cin>>l[i]>>r[i];
        //rep(i,n)p[i] = i;
        //sort(p,p+n,cmp);
        int tot = 0;
        int ans = 0;
        rep2(i,1,n){
            tot += (l[i] - r[i-1])*b;
            tot -= (r[i]-l[i])*a;
            ans = max(-tot,ans);
        }
        cout<<"Case #"<<cas++<<": "<<ans<<endl;
    }

    return 0;
}
