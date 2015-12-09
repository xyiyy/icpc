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
const int MAXN = 20000;
int vis[MAXN*2+10];
bool used[MAXN*2+10];
int pa[MAXN*2+10];
int ra[MAXN*2+10];
int find(int x){
    if(pa[x]!=x)pa[x]=find(pa[x]);
    return pa[x];
}
void unite(int x,int y){
    x = find(x);
    y = find(y);
    if(x==y)return;
    pa[y]=x;
    ra[x]+=ra[y];
}
void init(){
    CLR(ra,0);
    for(int i=0;i<=MAXN+MAXN;i++)pa[i]=i;
    CLR(used,0);
    CLR(vis,0);
}
int main()
{
	ios::sync_with_stdio(false);
	int t;
	cin>>t;
	int cas=1;
	while(t--){
        int n;
        cin>>n;
        int u,v;
        init();
        for(int i=0;i<n;i++){
            cin>>u>>v;
            if(!ra[u])ra[u]=1;
            if(!ra[v])ra[v]=1;
            used[u]=used[v]=1;
            unite(u,v+MAXN);
            unite(u+MAXN,v);
        }
        int ans=0;
        for(int i=1;i<=MAXN;i++){
            if(used[i]){
                int x = find(i);
                int y = find(i+MAXN);
                if(vis[x]||vis[y])continue;
                ans+=max(ra[x],ra[y]);
                vis[x]=vis[y]=1;
            }
        }
        cout<<"Case "<<cas++<<": "<<ans<<endl;
	}
	return 0;
}




