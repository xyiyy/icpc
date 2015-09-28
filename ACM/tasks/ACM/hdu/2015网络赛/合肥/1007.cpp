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
int b[10010];
int a[10010];
ll C[1010][1010];
int main()
{
	ios::sync_with_stdio(false);
	int t;
	cin>>t;
	rep(i,20){
	    C[i][0] = 1;
        rep2(j,1,i){
            C[i][j] = C[i-1][j] + C[i-1][j-1];
        }
	}
	/*rep2(i,1,10){
        rep2(j,1,10){
            cout<<C[i][j]<<" ";
        }
        cout<<endl;
	}*/
	while(t--){
        int b1,a1,q,d,n,m;
        cin>>b1>>q>>a1>>d>>n>>m;
        b[1] = b1;
        a[1] = a1;
        rep2(i,2,m){
            b[i] = b[i-1]*q;
        }
        rep2(i,2,n){
            a[i] = a[i-1]+d;
        }
        ll ans = 0;
        rep2(i,1,n){
            ans += C[m+i-2][i-1]*a[n+1-i];
        }
        rep2(i,1,m){
            ans+=C[n+m-1-i][m-i]*b[i];
        }
        cout<<ans<<endl;

	}
	return 0;
}



