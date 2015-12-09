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
ll dp[(1<<16)+10][21];
int a[21];
int check(char c){
    if(c>='0'&&c<='9')return c-'0';
    return c-'A'+10;
}

int main()
{
    ios::sync_with_stdio(false);
    int t;
    int cas = 1;
    cin>>t;
    while(t--){
        int n,k;
        cin>>n>>k;
        string str;
        cin>>str;
        int len = str.length();
        int tot = 1<<len;
        for(int i=0;i<tot;i++){
            for(int j=0;j<k;j++)
                dp[i][j]=0;
        }
        for(int i=0;i<len;i++)a[i]=check(str[i]);
        for(int i=0;i<len;i++)dp[1<<i][a[i]%k]++;
        for(int i=0;i<tot;i++){
            for(int j=0;j<len;j++){
                if(i&(1<<j))continue;
                for(int l=0;l<k;l++){
                    dp[i|(1<<j)][(l*n+a[j])%k]+=dp[i][l];
                }
            }
        }
        cout<<"Case "<<cas++<<": "<<dp[tot-1][0]<<endl;
    }
    return 0;
}
