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
int a[5010][4],b[5010][4];
int dp[5010][25];
int cao[100][4];
int now[4];
int last[4];
int main()
{
	ios::sync_with_stdio(false);
	int t;
	cin>>t;
	int ini[4]={0,1,2,3};
	for(int i=0;i<24;i++){
        for(int j=0;j<4;j++){
            cao[i][j]=ini[j];
            //cout<<cao[i][j]<<" ";
        }
        //cout<<endl;
        next_permutation(ini,ini+4);
	}
	int cas=1;
	while(t--){
        int n;
        cin>>n;
        for(int i=0;i<25;i++){
            dp[0][i]=INF;
        }
        dp[0][0]=0;
        for(int i=0;i<4;i++)b[0][i]=i,a[0][i]=0;
        for(int i=1;i<=n;i++){
            for(int j=0;j<25;j++)dp[i][j]=INF;
            for(int j=0;j<4;j++){
                cin>>a[i][j]>>b[i][j];
                b[i][j]--;
            }
        }
        for(int i=1;i<=n;i++){
            for(int j=0;j<24;j++){
                for(int k=0;k<4;k++){
                    now[k]=cao[j][k];
                }
                bool flag=0;
                for(int k=0;k<3;k++){
                    if(b[i][now[k]]>b[i][now[k+1]])flag=1;
                }
                if(flag)continue;
                for(int k=0;k<24;k++){
                    for(int l=0;l<4;l++){
                        last[l]=cao[k][l];
                    }
                    flag=0;
                    int num=0;
                    for(int l=0;l<3;l++){
                        if(b[i-1][last[l]]>b[i-1][last[l+1]])flag=1;
                    }
                    if(flag)continue;
                    for(int l=0;l<4;l++){
                        num+=abs(a[i][now[l]]-a[i-1][last[l]])+abs(b[i][now[l]]-b[i-1][last[l]]);
                    }
                    dp[i][j]=min(dp[i][j],dp[i-1][k]+num);
                }
            }
        }
        int ans=INF;
        for(int i=0;i<24;i++){
             //   cout<<dp[n][i]<<endl;
            ans=min(dp[n][i],ans);
        }
        cout<<"Case #"<<cas++<<":"<<endl;
        cout<<ans<<endl;

	}
	return 0;
}


