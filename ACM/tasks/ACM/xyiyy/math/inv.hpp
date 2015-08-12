//
// Created by xyiyy on 2015/8/5.
//

#ifndef JHELPER_EXAMPLE_PROJECT_INV_HPP
#define JHELPER_EXAMPLE_PROJECT_INV_HPP
typedef  long long ll;
void extgcd(ll a,ll b,ll &d,ll &x,ll &y){
    if(!b){d = a;x=1;y=0;}
    else {extgcd(b,a%b,d,y,x);y-=x*(a/b);}
}

ll inv(ll a,ll mod){
    ll x,y,d;
    extgcd(a,mod,d,x,y);
    return d == 1 ? (x % mod + mod) % mod : -1;
}


#endif //JHELPER_EXAMPLE_PROJECT_INV_HPP
