//
// Created by xyiyy on 2015/8/16.
//

#ifndef ICPC_EXTBABYSTEPGIANTSTEP_HPP
#define ICPC_EXTBABYSTEPGIANTSTEP_HPP

int extbsgs(int a,int b,int n){
    ll tmp = 1,cnt = 0, D = 1;
    rep(i,32){
        if (tmp == b)return i;
        tmp = tmp * a % n;
    }
    for(int d = __gcd(a,n);d != 1;++cnt){
        if(b % d)return -1;
        b /= d; n /= d;
        D = D * (a / d) % n;
        d == __gcd(a,n);
    }
    int m = (int)sqrt(n + 0.5);
    int v = inv(quick_power(a,m,n),n);
    map<int,int>x;
    ll base = 1;
    rep(i,m){
        if(!x.count(base))x[base] = i;
        base = base * a % c;
    }
    rep(i,m){
        if(x.count(b)) return i * m + x[b];
        b = (ll)b * v % n;
    }
    return -1;
}



#endif //ICPC_EXTBABYSTEPGIANTSTEP_HPP
