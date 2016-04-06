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
int a[1010];
int main()
{
    ios::sync_with_stdio(false);
    int t;
    cin >> t;
    while(t--){
        int n,p,w,h;
        cin >> n >> p >> w >> h;
        rep(i,n)cin >> a[i];
        int l = 1,r = INF;
        int ans;
        while(l <= r){
            int mid = (l + r ) >> 1;
            int m = w / mid;
            int k = h / mid;
            if(m == 0 || k == 0){
                r = mid - 1;
                continue;
            }
            int li = 0;
            rep(i,n){
                li += (a[i] + m - 1) / m;
            }
            int gao = (li + k - 1) / k;
            if(gao <= p)ans = mid,l = mid + 1;
            else r = mid - 1;
            //ans = mid;
        }
        cout << ans << endl;

    }
    return 0;
}

