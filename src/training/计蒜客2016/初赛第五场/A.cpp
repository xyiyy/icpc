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

int main()
{
    ios::sync_with_stdio(false);
    int n,k;
    while(cin >> n >> k){
        double a;
        cin >> a;
        double ans = 0;
        double p = (n - 2) / (n * 1.0) * acos(-1.0);
        p = sqrt(2 - 2 * cos(p)) / 2.0;
       // cout << cos(p) << endl;
        for(int i = 0 ;i < k ;i++){
            //cout << i << endl;
            ans+= (n - 0.5) * a;
            a = a * p;
         //   cout << a << endl;
        }

       // cout << a << endl;
        ans += (n - 1) * a;
        cout << fixed << setprecision(10) << ans << endl;

    }
    return 0;
}

