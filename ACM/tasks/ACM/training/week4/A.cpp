#include <iostream>
using namespace std;
typedef long long ll;
ll a[1010];
int main(){
    ios::sync_with_stdio(false);
    ll n;
    cin>>n;
    ll i=1;
    while(n%i==0)i*=3;
    cout<<n/i+1<<endl;
    return 0;
}
