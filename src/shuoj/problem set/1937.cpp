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
ll fac[21];
void getdata(){
    int t = 1000;
    cout<<t<<endl;
    for(int i=0;i<t;i++){
        int n = rand()%21;
        int m = rand()%(n+1);
        cout<<n<<" "<<m<<endl;
    }
}
int main()
{
    ios::sync_with_stdio(false);
    #ifdef LOCAL
        //freopen("1937.in","w",stdout);
        //getdata();
        freopen("1937.in","r",stdin);
        freopen("1937.out","w",stdout);
    #endif // LOCAL
    int t;
    cin>>t;
    assert(t>=0&&t<=1000);
    fac[0] = 1;
    rep2(i,1,20)fac[i] = fac[i-1]*(ll)i;
    while(t--){
        int n,m;
        cin>>n>>m;
        assert(n>=0&&m>=0&&n<=20&&m<=n);
        cout<<fac[n]/fac[m]/fac[n-m]<<endl;
    }
    return 0;
}
