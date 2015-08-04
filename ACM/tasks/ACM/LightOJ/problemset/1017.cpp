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
int y[1010];
int num[1010];
int dp[110][110];
int main()
{
	ios::sync_with_stdio(false);
    int t;
    cin>>t;
    int cas = 1;
    while(t--){
        int n,w,k;
        cin>>n>>w>>k;
        int x;
        for(int i=0;i<n;i++){
            cin>>x>>y[i];
        }
        sort(y,y+n);
        CLR(num,0);
        CLR(dp,0);
        for(int i=0;i<n;i++){
            int j = i;
            while(j>=0&&y[i]-y[j]<=w)j--;
            j++;
            num[i]=j;
            dp[1][i]=i-j+1;
        }
        //for(int i=0;i<n;i++)cout<<num[i]<<" ";
        //cout<<endl;
        for(int i=2;i<=k;i++){
            for(int j=0;j<n;j++){
                for(int l=0;l<num[j];l++){
                    dp[i][j]=max(dp[i][j],dp[i-1][l]+j-num[j]+1);
                }
                for(int l=num[j];l<=j;l++){
                    dp[i][j]=max(dp[i][j],dp[i-1][l]+j-l);
                }
            }
        }
        int ans =0 ;
        for(int i=0;i<n;i++)ans = max(dp[k][i],ans);
        cout<<"Case "<<cas++<<": "<<ans<<endl;
    }
	return 0;
}




