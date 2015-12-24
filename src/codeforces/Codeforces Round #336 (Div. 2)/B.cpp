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
string s1,s2;
int a[200010];
int b[200010];
int main()
{
    ios::sync_with_stdio(false);
    #ifdef LOCAL
        freopen("in.txt","r",stdin);
    #endif // LOCAL
    while(cin>>s1>>s2){
        int len = s1.length();
        int n = s2.length();
       // rep2(i,1,len){
            //a[i] = a[i-1]+s1[i-1]-'0';
            //cout << a[i] << " ";
       // }
       // cout << endl;
        rep2(i,1,n){
            b[i] = b[i-1] + s2[i-1]-'0';
         //   cout << b[i] << " ";
        }
        //cout << endl;
        ll ans = 0;
        int d = n - len;
     //   cout << d <<endl;
        rep2(i,1,len){
            ans += abs(b[i+d] - b[i-1] - (d + 1) * (s1[i-1]-'0'));
           // cout << ans <<endl;
        }
        cout << ans <<endl;
    }
    return 0;
}

