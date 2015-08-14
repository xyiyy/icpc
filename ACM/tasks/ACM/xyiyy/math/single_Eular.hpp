//
// Created by xyiyy on 2015/8/10.
//

#ifndef ICPC_SINGLE_EULAR_HPP
#define ICPC_SINGLE_EULAR_HPP

ll Eular(ll n){
    ll ret = n;
    for(int i=2;(ll)i*i<=n;i++){
        if(n%i==0){
            ret = ret / i * (i-1);
            while(n%i==0)n/=i;
        }
    }
    if(n!=1)ret = ret / n * (n-1);
    return ret;
}

#endif //ICPC_SINGLE_EULAR_HPP
