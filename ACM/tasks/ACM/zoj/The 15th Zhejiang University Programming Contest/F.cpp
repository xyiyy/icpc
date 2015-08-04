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
char a[20][20];
int dp[20][20][4];
int dirx[4]={-1,1,0,0};
int diry[4]={0,0,-1,1};
int n,m,p;
bool ok(int x,int y){
    if(x>=0&&y>=0&&x<n&&y<m&&a[x][y]!='*')return 1;
    return 0;
}
int main()
{
	ios::sync_with_stdio(false);
	int t;
	cin>>t;
	while(t--){

        cin>>n>>m>>p;
        int sx,sy,gx,gy;
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                cin>>a[i][j];
                if(a[i][j]=='@')sx=i,sy=j;
                if(a[i][j]=='@')gx=i,gy=j;
            }
        }
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                for(int k=0;k<4;k++){
                    dp[i][j][k]=INF;
                }
            }
        }
        dp[sx][sy][0]=0;
        for(int i=0;i<4;i++){
            //for(int j=0;j<4;j++){
            //    dp[sx][sy][j]=min(dp[sx][sy][j],p-dp[sx][sy][i]+(i-(j-4)-1)*p);
            //}
            int tmp=p-dp[sx][sy][i]%p-1;
            for(int j=-2;j<2;j++){
                int nt=tmp;
                int cost=abs(j);
                int nx=i+j;
                //if(nx<0)nx+=4;
                while(cost>nt){
                    nx--;
                    nt=p-1;
                    cost-=p;
                }
                while(nx<0)nx+=4;
                dp[sx][sy][nx]=min(dp[sx][sy][nx],dp[sx][sy][i]+abs(j));
                for(int k=0;k<4;k++){
                    if(k==i)continue;
                    dp[sx][sy][k]=min
                }

            }
            /*for(int j=0;j<4;j++){
                if(i==j)continue;
                if(p==1){
                    dp[sx][sy][j]=dp[sx][sy][i]+(i-(j-4)+1)/2;
                    continue;
                }


            }
        }
        for(int i=0;i<4;i++){
            dp[sx][sy][i]=min(dp[sx][sy][i],min(i,4-i));
            for(int j=1;j<4;j++){
                int t=i-j;
                if(t<0)t+=4;
                dp[sx][sy][t]=min(dp[sx][sy][t],dp[sx][sy][i]+j*p);
            }
            int tmp=p-dp[sx][sy][i]%p-1;
            tmp=min(2,tmp);
            for(int j=1;j<=tmp;j++){

            }
        }
        /*for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                for(int k=0;j<4;k++){
                    for(int l=0;l<4;l++){
                        dp[i][j][k][l]=INF;
                    }
                }
            }
        }
        queue <PII> q;
        for(int i=0;i<4;i++){
            dp[sx][sy][0][i]=min(i-0,4-i);
        }
        if(p<=2)dp[sx][sy][0][2]=4*p;
        for(int i=1;i<4;i++){
            for(int j=0;j<4;j++){
                dp[sx][sy][i][j]=i*p;
            }
        }
        if(p==1)dp[sx][sy][1][0]=5;
        q.push(sx*m+sy);
        while(!q.empty()){
            int tmp=q.front();
            q.pop();
            int x=tmp/m;
            int y=tmp%m;
            for(int i=0;i<4;i++){
                for(int j=0;j<4;j++){
                    if(dp[x][y][i][j]==INF)continue;
                    for(int k=0;k<4;k++){
                        if(!ok(x+dirx[k],y+diry[k]))continue;
                        int t=(4-i)%4;
                        dp[x+dirx[k]][y+diry[k]][][]

                    }
                }
            }
        }*/
	}
	return 0;
}



