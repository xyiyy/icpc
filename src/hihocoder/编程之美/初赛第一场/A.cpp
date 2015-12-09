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
int a[100010];
vector<int>G[100010];
map<int>ms[100010];
void add_edge(int u,int v){
    G[u].PB(v);
    G[v].PB(u);
}
int main()
{
	ios::sync_with_stdio(false);
    int t;
    int cas=1;
    scanf("%d",&t);
    while(t--){
        CLR(a,0);
        int n,q;
        int u,v;
        scanf("%d",&n);
        for(int i=0;i<n;i++)G[i].clear();
        for(int i=0;i<n;i++)ms[i].clear();
        for(int i=0;i<n-1;i++){
            scanf("%d%d",&u,&v);
            u--;v--;
            add_edge(u,v);
        }
        int ch,x,y;
        scanf("%d",&q);
        int ans=1;
        printf("Case #%d:\n",cas++);
        for(int i=0;i<q;i++){
            scanf("%d",&ch);
            if(ch==1){
                printf("%d\n",ans);
            }else{
                scanf("%d%d",&x,&y);
                x--;
                if(y==a[x])continue;

                /*for(int j=0;j<G[x].size();j++){
                    v= G[x][j];
                    if(a[x]==a[v])ans++;
                    else if(a[v]==y)ans--;
                }
                a[x]=y;*/
            }
            //printf("%dasfsadsa\n",ans);
        }

    }
	return 0;
}



