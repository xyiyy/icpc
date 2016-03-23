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
double a[110];
int b[110];
int c[110];
int main()
{
    ios::sync_with_stdio(false);
    int t;
    cin >> t;
    while(t--){
        int n;
        cin >> n;
        rep(i,n)cin>>a[i]>>b[i];
        rep(i,n)c[i] = a[i] * 2.0 + 0.1;
        int ans = 0;
        for(int i =0 ; i < n; i++){
            if(c[i] % 10 == 0)ans = max(ans,b[i]);
            for(int j = i+1;j<n;j++){
                if((c[i] + c[j])%10 == 0)ans = max(ans,b[i] + b[j]);
                for(int k = j+1;k<n;k++){
                    if((c[i] + c[j] + c[k] ) % 10 == 0)ans = max(ans , b[i] + b[j] + b[k]);
                }
            }
        }
        cout << ans << endl;
    }


    return 0;
}
