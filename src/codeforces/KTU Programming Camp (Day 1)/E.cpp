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
ll a[210][210];
int main(){
    ios::sync_with_stdio(false);
    int n;
    cin>>n;
    ll sum = 0;
    rep(i,n)
    rep(j,n)cin>>a[i][j];
    rep(i,n)sum+=a[i][n-1-i];
    rep(i,n){
        ll tmp = 0;
        rep(j,n){
            if(j==i)continue;
            tmp += a[i][j];
        }
        a[i][i] = sum - tmp;
    }
    ll tot = 0;
    rep(i,n)tot += a[i][i];
    tot = sum - tot;
    tot /=n-1;
    rep(i,n)a[i][i] += tot;
    rep(i,n){
        rep(j,n)cout<<a[i][j]<<" ";
        cout<<endl;
    }

    return 0;
}
