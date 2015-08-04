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
string str[30];
int dp[110][110];
int ans =0;
int n;
int used[110];
void dfs(int x,int len){
    ans = max(len,ans);
    for(int i=0;i<n;i++){
        if(dp[x][i]!=-1&&used[i]<2){
            used[i]++;
            dfs(i,len+dp[x][i]);
            used[i]--;
        }
    }
}
int main()
{
	ios::sync_with_stdio(false);
    while(cin>>n){
        for(int i=0;i<n;i++)cin>>str[i];
        CLR(dp,-1);
        for(int i=0;i<n;i++){
            for(int j=0;j<n;j++){
                int len1 = str[i].length();
                int len2 = str[j].length();
                int len = min(len1,len2);
                for(int k=1;k<=len;k++){
                    bool flag = 1;
                    for(int l = 0;l<k;l++){
                        if(str[i][len1-1-l]!=str[j][k-1-l]){
                            flag=0;
                            break;
                        }
                    }
                    if(flag){
                        dp[i][j]=len2-k;
                        break;
                    }
                }
            }
        }
       /* for(int i=0;i<n;i++){
            for(int j=0;j<n;j++){
                cout<<dp[i][j]<<" ";
            }
            cout<<endl;
        }*/
        char s;
        cin>>s;
        ans =0;
        for(int i=0;i<n;i++){
            if(str[i][0]==s){
                used[i]++;
                dfs(i,str[i].length());
                used[i]--;
            }
        }
        cout<<ans<<endl;

    }
	return 0;
}


