#include <bits/stdc++.h>
using namespace std;
#define rep(A,X) for(int i=0;i<X;i++)
#define rep2(A,X,Y) for(int i=X;i<=Y;i++)
int a[100010];
typedef long long ll;
int main(){
    #ifdef LOCAL
        freopen("in.txt","r",stdin);
    #endif // LOCAL
    int t;
    ios::sync_with_stdio(0);
    cin>>t;
    while(t--){
        int n;
        cin>>n;
        rep(i,n)cin>>a[i];
        ll len = 1;
        ll ans = 0;
        rep2(i,1,n-1){
            if(a[i]<a[i-1]){
                ans += (len + 1)* len / 2;
                len = 1;
            }else len++;
        }
        ans += (len + 1) * len / 2;
        cout << ans << endl;
    }



}
