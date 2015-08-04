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
int G[110][110];
int deg[110];
int vis[110];
char a[110];
char ans[110];
int n;
void toposort(int d){
    if(d>=n){
        cout<<ans<<endl;
        return;
    }
    for(int i=0;i<n;i++){
        if(!deg[i]&&!vis[i]){
            ans[d] = a[i];
            vis[i] = 1;
            for(int j=0;j<n;j++){
                if(G[i][j])deg[j]--;
            }
            toposort(d+1);
            vis[i]=0;
            for(int j=0;j<n;j++){
                if(G[i][j])deg[j]++;
            }
        }
    }
}
int main()
{
    ios::sync_with_stdio(false);
    string s;
    int k=0;
    while(getline(cin,s,'\n')){
        CLR(G,0);
        CLR(deg,0);
        CLR(vis,0);
        CLR(a,0);
        CLR(ans,0);
        if(k)cout<<endl;
        k++;
        stringstream ss(s);
        n=0;
        while(ss>>a[n])n++;
        sort(a,a+n);
        getline(cin,s,'\n');
        stringstream ss1(s);
        char u,v;
        while(ss1>>u>>v){
            for(int i=0;i<n;i++){
                if(a[i]==u){
                    for(int j=0;j<n;j++){
                        if(a[j]==v){
                            G[i][j] = 1;
                            deg[j]++;
                        }
                    }
                }
            }
        }
        toposort(0);
    }
    return 0;
}
