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
#define MP(X,Y) make_pair(X,Y)
#define PB(X) push_back(X)
#define REP(X,N) for(int X=0;X<N;X++)
#define REP2(X,L,R) for(int X=L;X<=R;X++)
#define DEP(X,R,L) for(int X=R;X>=L;X--)
#define CLR(A,X) memset(A,X,sizeof(A))
#define IT iterator
typedef long long ll;
typedef pair<int,int> PII;
typedef vector<PII> VII;
typedef vector<int> VI;
int a[10010];
int main()
{
    ios::sync_with_stdio(false);
    int n;
    int k;
    while(cin>>n>>k){
        for(int i=0;i<n;i++)cin>>a[i];
        sort(a,a+n);
        double ans = 1e10;
        for(int i=0;i<=n-k;i++){
            double sum = 0;
            for(int j=0;j<k;j++){
                sum +=a[i+j];
            }
            sum = sum/(k*1.0);
            double tmp = 0;
            for(int j=0;j<k;j++){
                tmp = tmp + (a[i+j]-sum)*(a[i+j]-sum);
            }
            ans = min(ans, tmp/(k*1.0));
        }
        cout<<fixed<<setprecision(2)<<ans<<endl;
    }
    return 0;
}
