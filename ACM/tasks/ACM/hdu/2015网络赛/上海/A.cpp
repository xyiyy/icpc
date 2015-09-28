//#####################
//Author:fraud
//Blog: http://www.cnblogs.com/fraud/
//#####################
//#pragma comment(linker, "/STACK:102400000,102400000")
#include <iostream>
#include <sstream>
#include <ios>
#include <iomanip>
#include <functional>
#include <algorithm>
#include <vector>
#include <string>
#include <list>
#include <queue>
#include <deque>
#include <stack>
#include <set>
#include <map>
#include <cstdio>
#include <cstdlib>
#include <cmath>
#include <cstring>
#include <climits>
#include <cctype>
using namespace std;
#define XINF INT_MAX
#define INF 0x3FFFFFFF
#define mp(X,Y) make_pair(X,Y)
#define pb(X) push_back(X)
#define rep(X,N) for(int X=0;X<N;X++)
#define rep2(X,L,R) for(int X=L;X<=R;X++)
#define dep(X,R,L) for(int X=R;X>=L;X--)
#define clr(A,X) memset(A,X,sizeof(A))
#define IT iterator
typedef long long ll;
typedef pair<int,int> PII;
typedef vector<PII> VII;
typedef vector<int> VI;
const  int MAXN = 100010;
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
int main(){
    ios::sync_with_stdio(false);
    int n;
    Eular();
    while(scanf("%d",&n)!=EOF){

    }

    return 0;
}

