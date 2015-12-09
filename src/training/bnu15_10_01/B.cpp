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
int a[100010];
int b[100010];
int main()
{
	ios::sync_with_stdio(false);
    int  n;
    while(scanf("%d",&n)!=EOF){
        rep(i,n)scanf("%d",&a[i]);
        ll tmp = 10;
        ll ans = 0;
        rep(i,10){
            rep(j,n)b[j] = a[j] % tmp;
            sort(b,b+n);
            int l = 0,r = n-1;
            while(l<n){
                while(l<r&&r>=0&&b[l]+b[r]>=tmp)r--;
                if(l<=r)ans += n - 1 - r;
                else ans += n - 1 - l;
                l++;
            }
            tmp *= 10;
        }
        cout << ans << endl;
    }
	return 0;
}


