#include<iostream>
#include<vector>
#include <queue>
using namespace std;
#define PB(X) push_back(X)
#define MP(X,Y) make_pair(X,Y)
#define INF 0x3fffffff
#define clr(A,N,B) for(int i=0;i<N;i++)A[i] = B;
typedef pair<int,int> PII;
const int   MAXN = 110;
vector<PII> G[MAXN];
void init(int n){
    for(int i=0;i<n;i++){
        G[i].clear();
    }
}
void add_edge(int u,int v,int d){
    G[u].PB(MP(v,d));
}
int vis[MAXN];
int dis[MAXN];
void spfa(int s,int n){
    clr(vis,n,0);
    clr(dis,n,INF);
    queue<int>q;
    q.push(s);
    dis[s] = 0;
    while(!q.empty()){
        int x = q.front();
        q.pop();
        vis[x] = 0;
        for(int i=0;i<G[x].size();i++){
            int y = G[x][i].first;
            int d = G[x][i].second;
            if(dis[x] + d < dis[y]){
                dis[y] = dis[x] + d;
                if(!vis[y]){
                    q.push(y);
                    vis[y] = 1;
                }
            }
        }
    }
}
int a[1110];
int b[1110];
int c[1110];
int gao(int x,int n,int m){
    init(n);
    for(int i=0;i<m;i++){
        if(a[i] == x||b[i] == x)continue;
        add_edge(a[i],b[i],c[i]);
        add_edge(b[i],a[i],c[i]);
    }
    spfa(0,n);
    return dis[n-1];
}
int main(){
    ios::sync_with_stdio(0);
    int n,m;
    while(cin>>n>>m&&(n||m)){
        int u,v,d;
        for(int i=0;i<m;i++){
            cin>>a[i]>>b[i]>>c[i];
            a[i]--;b[i]--;
        }
        int ans = gao(-1,n,m);
        for(int i=1;i<n-1;i++){
            ans = max(ans,gao(i,n,m));
        }
        if(ans==INF)cout<<"Inf"<<endl;
        else cout<<ans<<endl;

    }
}
