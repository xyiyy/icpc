#include <iostream>
using namespace std;
typedef long long ll;
ll fac[110];
int main(){
    ios::sync_with_stdio(0);
    int n;
    fac[0] = 1;
    for(int i=1;i<30;i++)fac[i] = fac[i-1] * i;
    while(cin>>n){
        ll ans =0;
        for(int i=0;i<=n;i++){
            if(i&1)ans -= fac[n]/fac[i];
            else ans += fac[n]/fac[i];
        }
        cout << ans << endl;
    }

    return 0;
}
