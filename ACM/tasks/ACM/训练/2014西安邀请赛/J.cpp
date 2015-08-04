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
char a[110][110];
int dis[500][500];
int n,m;
bool  vis[20][20];
int dirx[4]={-1,0,0,1};
int diry[4]={0,-1,1,0};
bool in(int x,int y){
    if(x>=0&&x<n&&y>=0&&y<n&&a[x][y]=='.')return 1;
    return 0;
}
void bfs(int s){
    //cout<<s<<endl;
    CLR(vis,0);
    queue<int>q;
    q.push(s);
    vis[s/n][s%n]=1;
    dis[s][s]=0;
    while(!q.empty()){
        int temp = q.front();
        q.pop();
        int x = temp/n;
        int y =temp%n;
        for(int i=0;i<4;i++){
            int tx= x+dirx[i];
            int ty = y+diry[i];
            if(in(tx,ty)&&!vis[tx][ty]){
                vis[tx][ty]=1;
                dis[s][tx*n+ty]=dis[s][temp]+1;
                q.push(tx*n+ty);
            }
        }
    }
}
int dp[20][300000];
int mx[110],my[110];
int gx[110],gy[110];
int caldis(int i,int j){
    int s=gx[i]*n+gy[i];
    int t=mx[j]*n+my[j];
    return dis[s][t];
}
int main()
{
	ios::sync_with_stdio(false);

    while(cin>>n>>m){
        for(int i=0;i<n;i++){
            for(int j=0;j<n;j++){
                cin>>a[i][j];
            }
        }
        for(int i=0;i<n*n;i++){
            for(int j=0;j<n*n;j++){
                dis[i][j]=INF;
            }

        }
        for(int i=0;i<n;i++){
            for(int j=0;j<n;j++){
                if(a[i][j]!='#')
                    bfs(i*n+j);

            }
        }
        for(int i =0 ;i<m;i++){
            cin>>mx[i]>>my[i];
            mx[i]--;my[i]--;
            cin>>gx[i]>>gy[i];
            gx[i]--;gy[i]--;
        }
        int num =1<<m;
        for(int i=0;i<m;i++){
            for(int j=0;j<num;j++){
                dp[i][j]=INF;
            }
        }
        for(int i =0 ;i<m;i++){
            dp[i][1<<m]=0;
        }
        for(int i=1;i<num;i++){
            for(int j=0;j<m;j++){
                if(i&(1<<j))continue;
                cout<<j<<" "<<i<<" "<<dp[j][i]<<endl;
                for(int k=0;k<m;k++){
                    dp[j][i|(1<<j)]= min(dp[j][i|(1<<j)],dp[k][i]+caldis(k,j));
                }
            }
        }
        int ans= INF;
        for(int i=0;i<m;i++){
            ans=min(ans,dp[i][num-1]);
        }
        if(ans==INF)ans=-1;
        cout<<ans<<endl;




    }
	return 0;
}


