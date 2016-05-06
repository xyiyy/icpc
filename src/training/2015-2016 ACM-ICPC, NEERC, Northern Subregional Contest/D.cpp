#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
ll dp[100];
vector<ll>vec;
int main(){
    ios::sync_with_stdio(0);
    dp[0] = 1;
    for(int i = 1 ; i <= 59; i ++ ){
        dp[i] = (dp[i - 1] << 1);
    }
    ll tot = 1000000000LL;
    tot = tot * tot;
    for(int i = 0; i <= 59; i ++ ){
        ll tmp = dp[i];
        while(tmp <= tot){
            vec.push_back(tmp);
            tmp = tmp * 3LL;
        }
    }
    sort(vec.begin(),vec.end());
    cout << vec.size() << endl;


    return 0;
}

