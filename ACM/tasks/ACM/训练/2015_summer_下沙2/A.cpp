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
int cost[510][510];
int dp[510][510];
int pre[510][510];
int gao[510];
int main()
{
    ios::sync_with_stdio(false);
    string str;
    int k;
    cin>>str;
    cin>>k;
    int len = str.length();
    for(int i=0;i<len;i++){
        for(int j=i;j<len;j++){
            for(int l=i,r=j;l<r;l++,r--){
                if(str[l]!=str[r])cost[i][j]++;
            }
        }
    }
    for(int i=0;i<len;i++)dp[i][1]=cost[0][i];
    for(int i = 1;i<len;i++){
        for(int j = 2;j<=k;j++){
            dp[i][j]=INF;
            for(int l=0;l<i;l++){
                if(dp[i][j]>dp[l][j-1]+cost[l+1][i]){
                    dp[i][j]=dp[l][j-1]+cost[l+1][i];
                    pre[i][j]=l;
                }
            }
        }
    }
    int minn=INF;
    int mink=0;
    for(int i=1;i<=k;i++){
        if(dp[len-1][i]<minn){
            minn = dp[len-1][i];
            mink = i;
        }
    }
    gao[mink]=len-1;
    for(int i=mink-1;i>0;i--){
        gao[i] = pre[gao[i+1]][i+1];
    }
    gao[0]=-1;
    cout<<minn<<endl;
    for(int i =1;i<=mink;i++){
        for(int l=gao[i-1]+1,r=gao[i];l<r;l++,r--){
            if(str[l]!=str[r])str[l]=str[r];
        }
        for(int l=gao[i-1]+1,r=gao[i];l<=r;l++)cout<<str[l];
        if(i<mink)cout<<"+";
    }
    cout<<endl;

    return 0;
}
