//#####################
//Author:fraud
//Blog: http://www.cnblogs.com/fraud/
//#####################
//#pragma comment(linker, "/STACK:102400000,102400000")
#include <bits/stdc++.h>
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
typedef pair<int,PII> PIII;
typedef vector<PII> VII;
typedef vector<int> VI;
PIII p[100010];
int num[100010];
int u[100010],v[100010];
int main()
{
    ios::sync_with_stdio(false);
    #ifdef LOCAL
        freopen("in.txt","r",stdin);
    #endif // LOCAL
    int n,m;
    cin>>n>>m;
    rep(i,m)cin>>p[i].first>>p[i].second.first;
    rep(i,m)p[i].second.second = i;
    sort(p,p+m);
    int num = 0;
    rep(i,m)if(p[i].second.first)num++;
    if(num != n-1){

        cout << -1 <<endl;
        return 0;
    }
    int now = 0;
    int f = 2;
    int ff = 3;
    int gao = 2;
    rep(i,m){
        int j = p[i].second.second;
        if(!p[i].second.first){
            if(f == ff){
                f = 2;
                ff++;
            }
            u[j] = f;
            v[j] = ff;
            f++;
        }else{
            u[j] = 1;
            v[j] = gao;
            gao++;
        }
        if(ff > gao){
            cout << -1 << endl;
            return 0;
        }

    }
    rep(i,m)cout << u[i] << " " << v[i] << endl;
    return 0;
}

