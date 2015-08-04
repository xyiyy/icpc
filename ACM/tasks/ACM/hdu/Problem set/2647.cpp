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
#define CLEAN(A,N) for(int i=0;i<N;i++)A[i].clear()
typedef long long ll;
typedef pair<int,int> PII;
typedef vector<PII> VII;
typedef vector<int> VI;
vector<int>G[10010];
int deg[10010];
int dis[10010];
bool toposort(int n){
    queue<int>q;
    for(int i=1;i<=n;i++)if(!deg[i])q.push(i);
    int num = 0;
    while(!q.empty()){
        int x = q.front();
        q.pop();
        //if(num)cout<<" ";
        //cout<<x;
        num++;
        for(int i=0;i<G[x].size();i++){
            int y =G[x][i];
            deg[y]--;
            if(!deg[y]){
                q.push(y);
                dis[y] = max(dis[y],dis[x] +1);
            }
        }
    }
    if(num!=n)return 0;
    return 1;
}
int main()
{
    ios::sync_with_stdio(false);
    int n,m;
    while(cin>>n>>m){
        CLR(deg,0);
        CLEAN(G,n+1);
        CLR(dis,0);
        int u,v;
        for(int i=0;i<m;i++){
            cin>>u>>v;
            deg[u]++;
            G[v].PB(u);
        }
        bool ok = toposort(n);
        if(!ok){
            cout<<-1<<endl;
            continue;
        }
        int ans = 0;
        for(int i=1;i<=n;i++)ans+=dis[i];
        ans +=888*n;
        cout<<ans<<endl;
        //cout<<endl;
    }
    return 0;
}
