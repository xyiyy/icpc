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
int B[4010];
int T[4010];
void Bell(int T[],int N,int MOD){
    B[0] = 1;B[1] = 1;T[0] = 1;
    for(int i=2;i<N;i++){
        T[i-1] = B[i-1];
        for(int j=i-2;j>=0;j--)T[j] = (T[j]+T[j+1])%MOD;
        B[i] = T[0];
    }
}

int main()
{
    ios::sync_with_stdio(false);
    #ifdef LOCAL
        freopen("in.txt","r",stdin);
    #endif // LOCAL
    Bell(T,4000,1000);
    int t;
    cin>>t;
    while(t--){
        int n;
        cin>>n;
        cout<< B[n] << endl;
    }
    return 0;
}
