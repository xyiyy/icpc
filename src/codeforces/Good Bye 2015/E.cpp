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

int a[10];
int t[200010];
int main()
{
    ios::sync_with_stdio(false);
    #ifdef LOCAL
       // freopen("in.txt","r",stdin);
    #endif // LOCAL
    int n;
    while(cin>>n){
        rep(i,3)cin>>a[i];
        sort(a,a+3);
        rep(i,n)cin>>t[i];
        sort(t,t+n);
        int ans = 0;
        if(t[n-1]>a[0]+a[1]+a[2]){
            cout << -1 << endl;
            continue;
        }
        int three =n - (upper_bound(t,t+n,a[0] + a[1] + a[2]) - t);
        int twomaxx = n - (upper_bound(t,t+n,a[1]+a[2]) - t) - three;
        int twomid = n - (upper_bound(t,t+n,a[0]+a[2]) - t) - three - twomaxx;
        int twomin = n - (upper_bound(t,t+n,a[1]+a[0])- t) - three - twomaxx - twomid;




    }
    return 0;
}

