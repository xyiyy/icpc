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

int main()
{
    ios::sync_with_stdio(false);
    #ifdef LOCAL
        freopen("in.txt","r",stdin);
    #endif // LOCAL
    int t;
    cin>>t;
    int cas = 1;
    while(t--){
        int a[10];
        int vis[1000] = {0};
        rep(i,3)cin>>a[i];
        cout << "Case #"<<cas++<<":"<<endl;
        sort(a,a+3);
        do{
            int num = a[0] * 100 + a[1] * 10 + a[2];
            if(vis[num]){
                continue;
            }
            vis[num] = 1;
            rep(i,3){
                if(i)cout << " ";
                cout << a[i];
            }
            cout << endl;
        }while(next_permutation(a,a+3));

    }
    return 0;
}

