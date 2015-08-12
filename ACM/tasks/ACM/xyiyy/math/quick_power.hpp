//
// Created by xyiyy on 2015/8/5.
//

#ifndef JHELPER_EXAMPLE_PROJECT_QUICK_POWER_HPP
#define JHELPER_EXAMPLE_PROJECT_QUICK_POWER_HPP
typedef long long ll;
ll quick_power(ll n,ll m,ll mod){
    ll ret = 1;
    while(m){
        if(m&1) ret = ret * n % mod;
        n = n * n % mod;
        m>>=1;
    }
    return ret;
}

#endif //JHELPER_EXAMPLE_PROJECT_QUICK_POWER_HPP
