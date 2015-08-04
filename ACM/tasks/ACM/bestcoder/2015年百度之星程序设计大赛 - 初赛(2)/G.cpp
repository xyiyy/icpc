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

#define MAXN 1000000

int pa[MAXN]; // parent
int ra[MAXN]; // rank

void init(int n)
{
    for(int i = 0; i < n; i++)
    {
        pa[i] = i;
        ra[i] = 0;
    }
}

int find(int x)
{
    if(pa[x]!=x) pa[x] = find(pa[x]);
    return pa[x];
}

int unite(int x, int y)
{
    x = find(x);
    y = find(y);
    if(x==y)return 0;
    if(ra[x] < ra[y])
    {
        pa[x] = y;
    }else{
        pa[y] = x;
        if(ra[x] == ra[y]) ra[x]++;
    }
    return 1;
}

bool same(int x, int y)
{
    return find(x) == find(y);
}

struct Edge{
    int u, v;
    int l;
    Edge(){};
    Edge(int _u, int _v, int len):u(_u),v(_v),l(len){}
    bool operator<(const Edge &e) const
    {
        return this->l < e.l;
    }
}edge[1000*1000*2];
int e;

void addEdge(int u, int v, int len)
{
    edge[e++] = Edge(u, v, len);
}

int Kruskal(int n)
{
    init(n);
    //priority_queue<Edge> q;
   // for(int i = 0; i < e; i++)
    //    q.push(edge[i]);
    sort(edge,edge+e);
    int ans = 0;
    int u,v;
    int j=0;
    for(int i = 0; i < n-1; i++)
    {
        Edge E = edge[j++];
        while(same(E.u, E.v) && j < e)
        {
            E = edge[j++];
        }
        unite(E.u,E.v);
        ans += E.l;
    }
    return ans;
}
int Scan() {
    int res=0, ch;
    while(ch=getchar(), ch<'0'||ch>'9');
    res=ch-'0';
    while((ch=getchar())>='0'&&ch<='9')
        res=res*10+ch-'0';
    return res;
}
void Out(int a) {
    if(a>9)
        Out(a/10);
    putchar(a%10+'0');
}

bool in(int x,int y,int n,int m){
    if(x>=0&&x<n&&y>=0&&y<m)return 1;
    return 0;
}
int a[1010][1010];
int dirx[2]={0,1};
int diry[2]={1,0};
int main()
{
    ios::sync_with_stdio(false);
    int t;
   // int a[1010][1010];
    int cas=1;
    t=Scan();
    while(t--){
        int n,m;
        e=0;
        n=Scan();
        m=Scan();
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                a[i][j]=Scan();
            }
        }
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                for(int k=0;k<2;k++){
                    int tx = i+dirx[k];
                    int ty = j+diry[k];
                    if(in(tx,ty,n,m)){
                        addEdge(i*m+j,tx*m+ty,abs(a[i][j]-a[tx][ty]));
                    }
                }
            }
        }
        cout<<"Case #"<<cas++<<":"<<endl;
        cout<<Kruskal(n*m)<<endl;
    }
    return 0;
}
