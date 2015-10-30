#include <iostream>
using namespace std;
typedef long long ll;
ll fac[110];
ll C[110][110];
int main(){
    ios::sync_with_stdio(0);
    int n,r;
    fac[0] = 1;
    for(int i=1;i<=30;i++)fac[i] = fac[i-1] * i;
    C[0][0] = 1;
    for(int i = 1;i<=30;i++){
        C[i][0] = 1;
        for(int j =1;j<=i;j++){
            C[i][j] = C[i-1][j]+ C[i-1][j-1];
        }
    }
    while(cin>>r>>n){
        cout <<C[n+r-1][n-1]<<endl;
    }
    return 0;

}
