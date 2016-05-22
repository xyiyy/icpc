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
typedef vector<PII> VII;
typedef vector<int> VI;
map<int,int>ms;
int a[200010],b[200010];
int main()
{
    ios::sync_with_stdio(false);
    #ifdef LOCAL
        freopen("in.txt","r",stdin);
    #endif // LOCAL
    int n;
    while(cin >> n){
        ms.clear();
        int t;
        rep(i,n){
            cin >> t;
            ms[t]++;
        }
        int m;
        cin >> m;
        rep(i,m)cin >> a[i];
        rep(i,m)cin >> b[i];
        PII p = mp(-1,-1);
        int id =1;
        PII tp;
        rep(i,m){
            tp = mp(ms[a[i]],ms[b[i]]);
            if(tp > p){
                p = tp;
                id = i + 1;
            }
        }
        cout << id <<endl;
    }
    return 0;
}

