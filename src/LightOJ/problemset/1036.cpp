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
int a[510][510];
int b[510][510];
int dp[510][510];
int main()
{
    ios::sync_with_stdio(false);
    int t;
    int cas =1;
    scanf("%d",&t);
    while(t--){
        int n,m;
        scanf("%d%d",&n,&m);
        //cin>>n>>m;
        for(int i=1;i<=n;i++){
            for(int j=1;j<=m;j++){
                scanf("%d",&a[i][j]);
                a[i][j]+=a[i][j-1];
                //cin>>a[i][j];
                dp[i][j]=0;
            }
        }
        for(int i=1;i<=n;i++){
            for(int j=1;j<=m;j++){
                scanf("%d",&b[i][j]);
                b[i][j]+=b[i-1][j];
                //cin>>b[i][j];
            }
        }
        for(int i=1;i<=n;i++){
            for(int j=1;j<=m;j++){
                dp[i][j]=max(a[i][j]+dp[i-1][j],b[i][j]+dp[i][j-1]);
            }
        }
        cout<<"Case "<<cas++<<": "<<dp[n][m]<<endl;

    }
    return 0;
}
