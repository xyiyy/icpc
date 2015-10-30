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
int a[500100];
int b[500100];
int main()
{
    ios::sync_with_stdio(false);
    #ifdef LOCAL
        freopen("in.txt","r",stdin);
    #endif // LOCAL
    int n;
    while(cin>>n){
        int ans  = 0;
        rep(i,n){
            cin>>a[i];
        }
        //int st = 1;
        //while(st<n-1&&a[st]==a[st-1])st++;
        //int en = n - 2;
        //while(en>0&&a[en]==a[st+1])en++;
        b[0] = a[0];
        b[n-1] = a[n-1];
        rep2(i,1,n-2){
            int len = 0;
            int st = i;
            b[i] = a[i];
            while(i<n-1&&a[i]!=a[i-1]&&a[i]!=a[i+1]){
                len++;
                i++;
            }
            int en = i;
            b[en] = a[i];
            en--;
            while(en>=st){
                b[st] = b[st-1];
                st++;
                b[en] = b[en+1];
                en--;
            }
            ans = max(len,ans);
        }
        cout << (ans+1)/2<<endl;
        rep(i,n){
            cout <<b[i] << " ";
        }
        cout << endl;
    }
    return 0;
}
