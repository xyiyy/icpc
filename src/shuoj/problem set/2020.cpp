//#####################
//Author:fraud
//Blog: http://www.cnblogs.com/fraud/
//#####################
//#pragma comment(linker, "/STACK:102400000,102400000")
#include <bits/stdc++.h>
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
const double pi = acos(-1.0);
int main()
{
    ios::sync_with_stdio(false);
    int t;
    cin >> t;
    while(t--){
        double a,b,c;
        cin >> a >> b >>c;
        cout << fixed << setprecision(2) << sqrt(a*a + b * b - 2 *a * b *cos(c/180.0 * pi)) << endl;
    }
    return 0;
}


