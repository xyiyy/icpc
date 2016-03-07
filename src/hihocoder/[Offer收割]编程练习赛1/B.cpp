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
priority_queue<int>pq;
int a[100010];
int main()
{
    ios::sync_with_stdio(false);
    int n;
    ll q;
    cin >> n >> q;
    rep(i,n){
        cin >> a[i];
    }
    int l = 1,r = n;
    ll ans  = 0;
    int k = 1;
    bool ok = false;
    while(l <= r){
        int mid = (l + r) >> 1;
        while(!pq.empty())pq.pop();
        for(int i = 0;i < mid;i++){
            pq.push(a[i]);
        }
        ans = 0;
        ll now = 1;
        for(int i = mid;i<n;i++){
            ans += now * pq.top();
            pq.pop();
            pq.push(a[i]);
            now ++ ;
        }
        while(!pq.empty()){
            ans += now * pq.top();
            pq.pop();
            now++;
        }
        if(ans <= q){
                k = mid;
                ok = true;
            r = mid - 1;
        }else{
            l = mid + 1;
        }
    }
    if(!ok)k = -1;
    cout << k << endl;
    return 0;
}
