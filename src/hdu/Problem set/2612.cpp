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
int dis[2][210][210];
int ans[210][210];
char a[210][210];
int dirx[4]={-1,0,0,1};
int diry[4]={0,1,-1,0};
int n,m;
bool in(int x,int y){
    if(x<0||x>=n||y<0||y>=m)return 0;
    return 1;
}
void bfs(int sx,int sy,int f){
    queue<PII> q;
    dis[f][sx][sy] = 0;
    q.push(MP(sx,sy));
    while(!q.empty()){
        PII p = q.front();
        int x = p.first;
        int y = p.second;
        q.pop();
        for(int i=0;i<4;i++){
            int tx = x + dirx[i];
            int ty = y + diry[i];
            if(in(tx,ty)&&dis[f][tx][ty]==INF&&a[tx][ty]!='#'){
                q.push(MP(tx,ty));
                dis[f][tx][ty] = dis[f][x][y] + 1;
            }
        }
    }
}
int main()
{
    ios::sync_with_stdio(false);
    while(cin>>n>>m){
        int sx,sy,gx,gy;
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                dis[0][i][j] = dis[1][i][j]  = INF;
                cin>>a[i][j];
                if(a[i][j]=='Y'){
                    sx = i; sy = j;
                }else if(a[i][j]=='M'){
                    gx = i; gy = j;
                }
            }
        }
        bfs(sx,sy,0);
        bfs(gx,gy,1);
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                ans[i][j] = dis[0][i][j] + dis[1][i][j];
            }
        }
        int res = INF;
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(a[i][j]=='@'){
                    res = min(ans[i][j], res);
                }
            }
        }
        cout<<res*11<<endl;

    }
    return 0;
}
