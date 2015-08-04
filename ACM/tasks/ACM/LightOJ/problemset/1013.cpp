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
ll dp[110][35][35];
int main()
{
	ios::sync_with_stdio(false);
    int t;
    cin>>t;
    string str1;
    string str2;
    int cas=1;
    while(t--){
        cin>>str1;
        cin>>str2;
        int len1 = str1.length();
        int len2 = str2.length();
        int len = len1+len2;
        for(int i=0;i<=len;i++){
            for(int j=0;j<=len1;j++){
                for(int k=0;k<=len2;k++){
                    dp[i][j][k] = 0;
                }
            }
        }
        dp[0][0][0]=1;
        for(int i=0;i<len;i++){
            for(int j=0;j<=len1;j++){
                for(int k =0;k<=len2;k++){
                    if(j!=len1&&k!=len2&&str1[j]==str2[k]){
                        dp[i+1][j+1][k+1]+=dp[i][j][k];
                    }else{
                        dp[i+1][j+1][k]+=dp[i][j][k];
                        dp[i+1][j][k+1]+=dp[i][j][k];
                    }
                }
            }
        }
        for(int i=0;i<len+1;i++){
            if(dp[i][len1][len2]){
                cout<<"Case "<<cas++<<": "<<i<<" "<<dp[i][len1][len2]<<endl;
                break;
            }
        }
    }
	return 0;
}




