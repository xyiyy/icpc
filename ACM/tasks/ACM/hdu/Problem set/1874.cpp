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
const int MAXN = 310;
int G[MAXN][MAXN];
void init(int n){
    for(int i = 0;i<n;i++)
    for(int j = 0;j<n;j++)
        G[i][j] = (i == j ? 0: INF);
}
void Floyd(int n){
    for(int k = 0;k<n;k++){
        for(int i = 0;i<n;i++){
            for(int j = 0;j<n;j++){
                G[i][j] = min(G[i][j],G[i][k] + G[k][j]);
            }
        }
    }
}
int main()
{
    ios::sync_with_stdio(false);
    int n,m;
    while(cin>>n>>m){
        init(n);
        int u,v,d;
        for(int i=0;i<m;i++){
            cin>>u>>v>>d;
            G[u][v] = G[v][u] = min(G[u][v],d);
        }
        Floyd(n);
        cin>>u>>v;
        int ans = G[u][v];
        if(ans == INF) ans  = -1;
        cout<<ans<<endl;
    }
    return 0;
}
