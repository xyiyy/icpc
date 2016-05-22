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

string str;
bool check_prime(int n){
    if(n < 2)return 0;
    for(int i = 2; i * i <= n; i++){
        if(n % i == 0)return 0;
    }
    return 1;
}
int a[100010];
const int MOD = 9973;
int pw(int n,int m = MOD - 2){
    int ret = 1;
    while(m){
        if(m & 1)ret = ret * n % MOD;
        n = n * n % MOD;
        m >>= 1;
    }
    return ret;
}
int main()
{
    ios::sync_with_stdio(false);
    #ifdef LOCAL
        //freopen("in.txt","r",stdin);
    #endif // LOCAL
    int n;
    //cout << check_prime(9973) << endl;
    while(cin >> n){
        cin >> str;
        int len = str.length();
        a[0] = 1;
        rep2(i,1,len){
            a[i] = a[i - 1] * (str[i - 1] - 28) % MOD;
        }
        int u,v;
        rep(i,n){
            cin >> u >> v;
            cout << pw(a[u-1]) * a[v]  % MOD << endl;
        }

    }
    return 0;
}

