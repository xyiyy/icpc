ll fast_mod(ll n,ll m){
    ll ret=1;
    while(m){
        if(m&1)ret = ret*n%MOD;
        n=n*n%MOD;
        m>>=1;
    }
    return ret;
}

