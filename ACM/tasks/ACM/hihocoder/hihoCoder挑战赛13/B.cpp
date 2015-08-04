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
const int MAXN = 10010;
vector<int>G[MAXN];
int gao[110][110];
int tot;
void dfs(int u,int fa){
    for(int i=0;i<G[u].size();i++){
        int v = G[u][i];
        if(v==fa)continue;
        for(int i=0;i<tot;i++)gao[v][i] = gao[u][i];
        gao[v][tot++] = 1;
        dfs(v,u);
    }
}
int main()
{
    ios::sync_with_stdio(false);
    int n;
    while(cin>>n){
        for(int i=0;i<n;i++)G[i].clear();
        int u,v;
        CLR(gao,0);
        for(int i=0;i<n-1;i++){
            cin>>u>>v;
            G[u].PB(v);
            G[v].PB(u);
        }
        tot = 0;
        dfs(0,-1);
        cout<<tot<<endl;
        for(int i=0;i<n;i++){
            for(int j=0;j<tot;j++){
                if(j)cout<<" ";
                cout<<gao[i][j];
            }
            cout<<endl;
        }
    }
    return 0;
}
