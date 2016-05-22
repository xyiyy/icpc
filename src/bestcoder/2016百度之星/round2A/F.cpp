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
vector<int>G[100020];
int deg[100010];

int main()
{
    ios::sync_with_stdio(false);
    #ifdef LOCAL
       // freopen("in.txt","r",stdin);
    #endif // LOCAL
    int t;
    scanf("%d",&t);
    while(t--){
        int n,m;
        scanf("%d%d",&n,&m);
        rep2(i,1,n)deg[i] = 0;
        rep2(i,1,n)G[i].clear();
        int u,v;
        rep(i,m){
            scanf("%d%d",&u,&v);
            deg[v]++;
            G[u].pb(v);
        }
        priority_queue<int> q;
        rep2(i,1,n){
            if(!deg[i])q.push(i);
        }
        ll tot = 0;
        int minn = INF;
        while(!q.empty()){
            int p = q.top();
            q.pop();
            minn = min(p,minn);
            tot += minn;
            int sz = G[p].size();
            rep(i,sz){
                v = G[p][i];
                deg[v]--;
                if(!deg[v])q.push(v);
            }
        }
        cout << tot << endl;;
    }

    return 0;
}


