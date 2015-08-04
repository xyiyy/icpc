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

ll dp[60][2510];
class DevuAndBeautifulSubstrings{
public:
    long long countBeautifulSubstrings(int n, int cnt){
        if(cnt<n)return 0;
        dp[0][0]=2;
        for(int i=1;i<=n;i++){
            for(int j=i;j<=cnt;j++){
                for(int k=1;k<=i;k++){
                    if(j>=k*(k+1)/2)
                    dp[i][j]+=dp[i][j-(k+1)*k/2];
                }
            }
        }
        /*for(int i=1;i<=n;i++){
            for(int j=1;j<=cnt;j++){
                for(int k=1;k<=n;k++){
                    cout<<dp[i][j][k]<<" ";
                }
                cout<<endl;
            }
            cout<<endl;
        }*/
        return dp[n][cnt];


    }
};
int main()
{
	ios::sync_with_stdio(false);
    DevuAndBeautifulSubstrings a ;
    int n,cnt;
    while(cin>>n>>cnt){
        cout<<a.countBeautifulSubstrings(n,cnt)<<endl;
    }
	return 0;
}



