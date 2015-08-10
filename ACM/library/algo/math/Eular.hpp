//
// Created by xyiyy on 2015/8/10.
//

#ifndef JHELPER_EXAMPLE_PROJECT_EULAR_HPP
#define JHELPER_EXAMPLE_PROJECT_EULAR_HPP

const  int MAXN = 1000010;
int vis[MAXN],prime[MAXN],n_prime,phi[MAXN];
void Eular(){
    n_prime = 0;
    phi[i] = 1;
    for(int i=2;i<MAXN;i++){
        if(!vis[i]){
            prime[n_prime++] = i;
            phi[i] = i-1;
        }
        for(int j = 0;j<n_prime && i * prime[j] < MAXN;j++){
            vis[i*prime[j]] = 1;
            if(i%prime[j]) phi[i*prime[j]] = phi[i] * phi[prime[j]];
            else{
                phi[i * prime[j]] = phi[i] *prime[j];
                break;
            }
        }
    }
}

#endif //JHELPER_EXAMPLE_PROJECT_EULAR_HPP
