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
ll dp[60];
ll num[60];
ll dpsum[60];
int main()
{
    ios::sync_with_stdio(false);
    int t;
    cin>>t;
    dp[2]=1;
    dpsum[2]=1;
    num[0]=1;num[1]=2;num[2]=4;
    for(int i=3;i<32;i++){
        dp[i]=dp[i-1]*2+num[i-3];
        dpsum[i]=dpsum[i-1]+dp[i];
        num[i]=num[i-1]*2;
    }
    int cas = 1;
    while(t--){
        int n;
        cin>>n;
        ll ans =0;
        while(n>2){
            int i;
            for(i=31;i>=0;i--)
                if(n>=num[i])break;
            ans += dpsum[i];
            n -= num[i];
            if(n>=num[i-1])ans+=n-num[i-1]+1;
        }
        cout<<"Case "<<cas++<<": "<<ans<<endl;


    }
    return 0;
}
