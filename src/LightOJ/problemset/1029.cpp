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
#define MP(X,Y,Z) make_pair(X,make_pair(Y,Z))
#define PB(X) push_back(X)
#define REP(X,N) for(int X=0;X<N;X++)
#define REP2(X,L,R) for(int X=L;X<=R;X++)
#define DEP(X,R,L) for(int X=R;X>=L;X--)
#define CLR(A,X) memset(A,X,sizeof(A))
#define IT iterator
typedef long long ll;
typedef pair<int,pair<int,int> > PII;
typedef vector<PII> VII;
typedef vector<int> VI;
int pa[110];
int ra[110];
vector<PII> G;
void init(int n){
    for(int i=0;i<=n;i++){
        pa[i]=i;
        ra[i]=0;
    }
}
int find(int x){
    if(pa[x]!=x)pa[x]=find(pa[x]);
    return pa[x];
}
int unite(int x,int y){
    x = find(x);
    y = find(y);
    if(x==y)return 0;
    if(ra[x]<ra[y]){
        pa[x]=y;
    }else{
        pa[y]=x;
        if(ra[x]==ra[y])ra[x]++;
    }
    return 1;
}
bool same(int x,int y){
    return find(x) == find(y);
}
int main()
{
    ios::sync_with_stdio(false);
    int t;
    cin>>t;
    int cas = 1;
    while(t--){
        int n;
        G.clear();
        cin>>n;
        int u,v,w;
        while(cin>>u>>v>>w&&(u||v||w)){
            G.PB(MP(w,u,v));
        }
        sort(G.begin(),G.end());
        int sz = G.size();
        int x,y,d;
        cout<<"Case "<<cas++<<": ";
        int ans1 = 0;
        int num  = 0;
        init(n);
        for(int i=0;i<sz;i++){
            x = G[i].second.first;
            y = G[i].second.second;
            d = G[i].first;
            if(!same(x,y)){
                unite(x,y);
                ans1 += d;
                num++;
            }
            //if(num==n-1)break;
        }
        //cout<<ans1<<endl;
        int ans2 = 0;
        num = 0;
        init(n);
        for(int i=sz-1;i>=0;i--)
        {
            x = G[i].second.first;
            y = G[i].second.second;
            d = G[i].first;
            if(!same(x,y)){
                unite(x,y);
                ans2 += d;
                num++;
            }
           // if(num == n-1)break;
        }
        //cout<<ans2<<endl;
        int ans = ans1 + ans2;
        if(ans&1)cout<<ans<<"/"<<2<<endl;
        else cout<<ans/2<<endl;


    }
    return 0;
}
