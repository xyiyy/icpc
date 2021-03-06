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
const int MAXN =100010;
double dp[MAXN];
int num[MAXN];
int main()
{
    ios::sync_with_stdio(false);
    int t;
    for(int i=2;i<MAXN;i++){
        dp[i]=num[i]=1;
    }
    for(int i=2;i<MAXN;i++){
        dp[i]=(dp[i]+1)/num[i];
        for(int j=i+i;j<MAXN;j+=i){
            dp[j]+=dp[i]+1;
            num[j]++;
        }
    }
    int cas =1;
    cin>>t;
    while(t--){
        int n;
        cin>>n;
        cout<<"Case "<<cas++<<": "<<fixed<<setprecision(10)<<dp[n]<<endl;

    }
    return 0;
}
