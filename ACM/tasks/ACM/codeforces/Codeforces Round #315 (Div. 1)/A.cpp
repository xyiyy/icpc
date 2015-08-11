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
#define ALL(X) (X).begin(),(X).end()
#define PQ std::priority_queue
typedef long long ll;
typedef pair<int,int> PII;
typedef vector<PII> VII;
typedef vector<int> VI;

const int MAXN = 5000010;
bool is_prime[MAXN];
int dp2[MAXN];
int dp[MAXN];
bool check(int num){
    int f = 1;
    int a[10];
    int i =0;
    while(num){
        a[i++] = num % 10;
        num/=10;
    }
    i--;
    for(int j=0;j<i;j++,i--){
        if(a[i]!=a[j])return 0;
    }
    return 1;
}
void init(){
    for(int i=2;i<MAXN;i++)is_prime[i] = 1;
    dp2[1] =1;
    for(int i=2;i<MAXN;i++){
        if(is_prime[i]){
            for(int j = i+i;j<MAXN;j+=i)is_prime[j] = 0;
        }
        dp[i] += dp[i-1]+is_prime[i];
        dp2[i] = dp2[i-1];
        if(check(i))dp2[i]++;
    }
}

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    init();
    int p,q;
    cin>>p>>q;
    for(int i=MAXN-1;i>0;i--){
        if((ll)dp2[i]*p>=(ll)dp[i]*q){
            cout<<i<<endl;
            return 0;
        }
    }

    return 0;
}
