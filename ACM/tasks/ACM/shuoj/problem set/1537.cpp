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
int pa[30010];
int ra[30010];
void init(int n){
    for(int i=0;i<=n;i++)pa[i]=i;
    CLR(ra,0);
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
int main()
{
	ios::sync_with_stdio(false);
    int t;
    cin>>t;
    while(t--){
        int n,m;
        cin>>n>>m;
        init(n);
        int u,v;
        for(int i=0;i<m;i++){
            cin>>u>>v;;
            unite(u,v);
        }
        int ans=0;
        for(int i=1;i<=n;i++){
            if(pa[i]==i)ans++;
        }
        cout<<ans<<endl;
    }
	return 0;
}


