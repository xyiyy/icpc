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
ll dp[110][110];
int main()
{
	ios::sync_with_stdio(false);
    int t;
    cin>>t;
    int cas=1;
    while(t--){
        string str;
        cin>>str;
        CLR(dp,0);
        for(int i=0;i<str.length();i++){
            dp[i][i]=1;
        }
        for(int len =1;len<str.length();len++){
            for(int i=0;i<str.length();i++){
                if(i+len>=str.length())break;
                dp[i][i+len]-=dp[i+1][i+len-1];
                dp[i][i+len]+=dp[i+1][i+len]+dp[i][i+len-1];
                if(str[i]==str[i+len])dp[i][i+len]+=dp[i+1][i+len-1]+1;
            }
        }

        cout<<"Case "<<cas++<<": "<<dp[0][str.length()-1]<<endl;
    }

	return 0;
}
