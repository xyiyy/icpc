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
typedef vector<PII> vii;
typedef vector<int> vi;

void getdata(){
    int t = 100000;
    cout<<t<<endl;
    for(int i=0;i<t;i++){
        int n = rand()%1001;
        int m = rand()%(n+1);
        cout<<n<<" "<<m<<endl;
    }
}
int C[1010][1010];
const int MOD = 1000000007;
int main()
{
    ios::sync_with_stdio(false);
    #ifdef LOCAL
        //freopen("1938.in","w",stdout);
        //getdata();
        freopen("1938.in","r",stdin);
        freopen("1938.out","w",stdout);
    #endif // LOCAL
    int t;
    //cin>>t;
    scanf("%d",&t);
    assert(t>=0&&t<=100000);
    rep(i,1010){
        C[i][0] = 1;
        rep2(j,1,i)C[i][j] = (C[i-1][j] + C[i-1][j-1]) % MOD;
    }
    while(t--){
        int n,m;
        scanf("%d %d",&n,&m);
        assert(n>=0&&m>=0&&n<=1000&&m<=n);
        printf("%d\n",C[n][m]);
    }
    return 0;
}
