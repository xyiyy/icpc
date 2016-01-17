#include <bits/stdc++.h>
using namespace std;
#define rep(X,N) for(int X=0;X<N;X++)
#define rep2(X,L,R) for(int X=L;X<=R;X++)
#define dep(X,R,L) for(int X=R;X>=L;X--)
#define clr(A,X) memset(A,X,sizeof(A))
bool vis[1010];
int main(){
cout << "ok" << endl;
    int n,m;
    while(cin>>n>>m){
        int k;
        clr(vis,0);
        rep(i,n){
            cin>>k;
            rep(j,k){
                int t;
                cin>>t;
                vis[t]= 1;
            }
        }
        int num = 0;
        for(int i=1;i<=m;i++){
            num += vis[i];
        }
        if(num==m)cout<<"YES"<<endl;
        else cout << "NO" << endl;

        }
        return 0;
}
