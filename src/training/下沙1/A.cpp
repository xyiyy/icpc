
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
int a[110];
int b[110];
int dp[110];
int c[110][11];
int main()
{
	ios::sync_with_stdio(false);
    int n,k;
    cin>>n>>k;
    for(int i=0;i<n;i++){
        cin>>a[i];
        for(int j=0;j<k;j++){
            c[i][j]=a[i]%10;
            a[i]/=10;
        }

    }
    for(int i=0;i<k;i++)b[i]=i;
    dp[0]=1;
    for(int i=1;i<k;i++)dp[i]=dp[i-1]*10;

    int ans = INF;
    do{
        int maxx = -1;
        int minn = INF;
        int tmp;
        for(int i=0;i<n;i++){
            tmp = 0;
            for(int j=0;j<k;j++){
                tmp = tmp*10 + c[i][b[j]];
            }
            maxx = max(maxx,tmp);
            minn = min(minn,tmp);
        }
        ans = min(maxx- minn,ans);

    }while(next_permutation(b,b+k));
    cout<<ans<<endl;

	return 0;
}



