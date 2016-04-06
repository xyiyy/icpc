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
set<ll>s;
int main()
{
    ios::sync_with_stdio(false);
    ll n , m;
    cin >> n >> m;
    ll p = sqrt(n + 1);
    ll x , y;
    ll tx = 0,ty = 0;
    rep2(i,1,p){
        x = i;
        y = n / x;
        if(x * y == n)s.insert(x),s.insert(y);
    }
    tx = s.size();
    p = sqrt(m + 0.5);
   // cout << tx <<endl;
     ll num = 0;
     rep2(i,1,p){
        x = i;
        y = m / x;
        if(x * y == m){
            if(s.count(x))num++;
            ty++;
            if(x != y){
                if(s.count(y))num++;
                ty++;
            }
        }
     }
     ll ans = tx * ty;
     ll gcd = __gcd(ans,num);
   //  cout << ty << endl;
     cout << ans  / gcd << " " << num / gcd<< endl;
    return 0;
}

