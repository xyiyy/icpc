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
#define mp(X,Y) make_pair(X,Y)
#define pb(X) push_back(X)
#define rep(X,N) for(int X=0;X<N;X++)
#define rep2(X,L,R) for(int X=L;X<=R;X++)
#define dep(X,R,L) for(int X=R;X>=L;X--)
#define clr(A,X) memset(A,X,sizeof(A))
#define IT iterator
typedef long long ll;
typedef pair<int,int> PII;
typedef vector<PII> vii;
typedef vector<int> vi;
vector<int> G[110];
bool used[110];
bool mark[110];
int dp[110][110];
int pa[110];
int n;
int dfs(int u){
    rep(i,G[u].size()){
        int v = dfs(G[u][i]);
        if(v)return v;
    }
    if(!used[u])return u;
    return 0;
}
bool check(int cur){
    int now = cur;
    rep(i,n+1)used[i] = mark[i];
    while(true){
        bool ok = true;
        rep2(i,1,n){
            ok = ok & used[i];
        }
        if(ok)return true;
        int v = now;
        int u = dfs(v);
        if(!u){
            while(v && used[v]) v = pa[v];
            if(used[v])return false;
            now = v;
            used[v] = true;
        }else{
            used[u] = 1;
            now = u;
        }
    }

}
class
EllysTree{
public:
    vector <int> getMoves(vector <int> parent){
        n = parent.size();
        rep(i,n){
            G[parent[i]].pb(i+1);
            pa[i+1] = parent[i];
        }
        rep2(i,1,n){
            int u = pa[i];
            while(true){
                dp[u][i] = dp[i][u] = 1;
                if(!u)break;
                u = pa[u];
            }
        }
        vector<int> ret;
        mark[0] = 1;
        if(!check(0))return ret;
        int now = 0 ;
        rep2(i,1,n){
            rep2(j,1,n){
                if(dp[now][j] && !mark[j]){
                    mark[j] = true;
                    if(check(j)){
                        now = j;
                        ret.pb(j);
                        break;
                    }else{
                        mark[j] = 0;
                    }
                }
            }
        }
        return ret;
    }

};


int main()
{
    ios::sync_with_stdio(false);
    int n;
    cin >> n;
    vector<int>vs;
    rep(i,n){
        int temp;
        cin >> temp;
        vs.pb(temp);
    }
    EllysTree *p = new EllysTree();
    vs = p->getMoves(vs);
    rep(i,vs.size()){
        cout << vs[i] << " " ;
    }
    cout << endl;
    return 0;
}

/*
5
3 4 5 0 2
*/

