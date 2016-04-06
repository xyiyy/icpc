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
typedef vector<PII> vii;
typedef vector<int> vi;
map<int,int>ms;
int main()
{
    ios::sync_with_stdio(false);
    int T;
    cin >> T;
    while(T--){
        int n,m,k;
        ms.clear();
        cin >> n >> m >> k;
        ll sum = 0;
        rep2(i,1,n){
            int x = min(m,i);
            sum += 1LL * (m - x) * x;
            sum += (1 + x) * x / 2;
        }
        ll gao = 1LL * n * m;
        /*if(n <= m){
            int gudinglen = m - n + 1;
            ll tsum = sum;
            rep2(i,1,n){

            }
        }*/
        ll ans = 1LL << 50;
        pair<ll,ll>ansxy = mp(ans,ans);
        bool f = 0;
        ll temp = sum;
        ms[temp] = 1;
        rep2(i,2,k){
            if(f)break;
            temp = temp + gao;
            temp %= k;
           // cout << temp << endl;
            if(ms.count(temp))break;
            if(temp % k == 0){
                ans = i + i;
                ansxy = mp(i,i);
                f = 1;
            }
            ms[temp] = i;
        }
        int num = 0;
        int sz = n - 1;
        ll now  = n * (n -1LL) / 2;
        dep(i,n-1,1){
            if(ms.count(k - (now % k))){
                ll x = ms[k - now % k];
                ll y = x + n - i;
                if(ans <= x + y){
                    ans = x + y;
                    ansxy = min(ansxy,mp(x,y));
                }
            }
            now -= i;
        }
        if(ans != (1LL << 50)){
            cout << ansxy.first << " " << ansxy.second << endl;
        }else cout << -1 <<endl;
    }
    return 0;
}
