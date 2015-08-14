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
int n,m;
bool vis[1010][1010];
char a[1010][1010];
int dp[1010][1010];
int dp1[1010][1010];
int dp2[1010][1010];
bool in(int x,int y){
    if(x>=0&&x<n&&y>=0&&y<m&&!vis[x][y])return 1;
    return 0;
}
int dirx[4]={-1,0,0,1};
int diry[4]={0,1,-1,0};
int main()
{
	ios::sync_with_stdio(false);
    int t;
    cin>>t;
    while(t--){
        cin>>n>>m;
        int sx,sy,gx,gy;
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                cin>>a[i][j];
                dp[i][j]=INF;
                vis[i][j]=0;
                if(a[i][j]=='E'){
                    sx=i,sy=j;
                }else if(a[i][j]=='S'){
                    gx=i,gy=j;
                }
            }
        }
        queue<PII>q;
       /* q.push(MP(sx,sy));
        vis[sx][sy]=1;
        int ans=INF;
        int minn=INF-1;
        dp[sx][sy]=0;
        while(!q.empty()){
            PII p= q.front();
            q.pop();
            int dx=p.first;
            int dy=p.second;
            for(int i=0;i<4;i++){
                int tx=dx+dirx[i];
                int ty=dy+diry[i];
                if(in(tx,ty)&&a[tx][ty]!='#'){
                    dp[tx][ty]=dp[dx][dy]+1;
                    vis[tx][ty]=1;
                    q.push(MP(tx,ty));
                    if(a[tx][ty]=='!'){
                        minn=min(minn,dp[tx][ty]);
                    }else if(tx==gx&&ty==gy){
                        ans=dp[tx][ty];
                    }
                }
            }
        }*/
        bool flag=0;
        //if(ans==minn){

            for(int i=0;i<n;i++){
                for(int j=0;j<m;j++){
                    vis[i][j]=0;
                    dp1[i][j]=INF;
                    if(a[i][j]=='!'){
                   // if(dp[i][j]==ans&&(a[i][j]=='!')){
                        q.push(MP(i,j));
                        dp1[i][j]=0;
                        vis[i][j]=1;
                    }
                }
            }
            while(!q.empty()){
                PII p= q.front();
                q.pop();
                int dx=p.first;
                int dy=p.second;
                for(int i=0;i<4;i++){
                    int tx=dx+dirx[i];
                    int ty=dy+diry[i];
                    if(in(tx,ty)&&a[tx][ty]!='#'){
                        dp1[tx][ty]=dp1[dx][dy]+1;
                        vis[tx][ty]=1;
                        q.push(MP(tx,ty));
                    }
                }
            }
            for(int i=0;i<n;i++){
                for(int j=0;j<m;j++){
                    vis[i][j]=0;
                    dp2[i][j]=INF;
                }
            }
            q.push(MP(gx,gy));
            vis[gx][gy]=1;
            dp2[gx][gy]=0;
            while(!q.empty()){
                PII p= q.front();
                q.pop();
                int dx=p.first;
                int dy=p.second;
                for(int i=0;i<4;i++){
                    int tx=dx+dirx[i];
                    int ty=dy+diry[i];
                    if(in(tx,ty)&&a[tx][ty]!='#'){
                        int temp=dp2[dx][dy]+1;
                        vis[tx][ty]=1;
                        if(temp<dp1[tx][ty]){
                            q.push(MP(tx,ty));
                            dp2[tx][ty]=temp;
                        }
                        if(tx==sx&&ty==sy&&temp==dp1[tx][ty])dp2[tx][ty]=temp;
                    }
                }
            }
            if(dp2[sx][sy]!=INF)flag=1;
            //if(dp2[sx][sy]==ans)flag=1;


        //}

        if(flag)cout<<"Yes"<<endl;
        else cout<<"No"<<endl;


    }
	return 0;
}


