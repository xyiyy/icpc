#include <iostream>
using namespace std;
typedef long long ll;
ll fac[110];
int main(){
    ios::sync_with_stdio(0);
    fac[0] = 1;
    for(int i=1;i<30;i++)fac[i] = fac[i-1] * i;
    int n,m;
    while(cin>>m>>n){
        cout << fac[n]/fac[n-m]*fac[n-1]<<endl;
    }
    return 0;
}
