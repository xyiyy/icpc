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
      //  freopen("in.txt","r",stdin);
    #endif // LOCAL
    int a,b,c;
    int x,y,z;
    cin>>a>>b>>c;
    cin>>x>>y>>z;
    int f = max(x- a,0) + max(y - b ,0) + max(z-c,0);
    int g = max(a-x,0) + max(b-y,0) + max(c -z,0);
    //cout << f << g << endl;
    if(2 *f > g){
        cout << "No" << endl;
    }else{
        if(g == 1){
            cout << "No" << endl;
        }else cout << "Yes" << endl;
    }
    return 0;
}

