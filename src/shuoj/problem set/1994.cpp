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
#define mp(X,Y) make_pair(X,Y)
#define pb(X) push_back(X)
#define rep(X,N) for(int X=0;X<N;X++)
#define rep2(X,L,R) for(int X=L;X<=R;X++)
#define dep(X,R,L) for(int X=R;X>=L;X--)
#define clr(A,X) memset(A,X,sizeof(A))
#define IT iterator
typedef long long ll;
typedef pair<int,int> PII;
typedef vector<PII> vii;
typedef vector<int> vi;
typedef pair<PII,PII> PIII;
#define mmp(W,X,Y,Z) mp(mp(W,X),mp(Y,Z))
int n,m;

char a[110][110];
bool in(int x,int y){
    if(x < 0 || x >= n || y < 0 || y >= m || a[x][y] == 'X')return 0;
    return 1;
}
bool vis[110][110][30];
int dx[4] = {-1,0,0,1};
int dy[4] = {0,-1,1,0};
int main()
{
    ios::sync_with_stdio(false);
    int t;
    cin >> t;
    while(t--){
        int s,c;
        cin >> n >> m >> s >> c;
        int sx,sy;
        int gx,gy;
        rep(i,n){
            rep(j,m){
                cin >> a[i][j];
                if(a[i][j] == 'S')sx = i, sy = j;
                else if(a[i][j] == 'T')gx = i, gy = j;
            }
        }
        clr(vis,0);
        priority_queue<PIII,vector<PIII>,greater<PIII> >q;
        vis[sx][sy][s] = 1;
        q.push(mmp(0,s,sx,sy));
        int ans = -1;
        while(!q.empty()){
            PIII p = q.top();
            PII temp = p.first;
            int nowt = temp.first;
            int nows = temp.second;
            temp = p.second;
            int x = temp.first;
            int y = temp.second;
            q.pop();
            //cout << x << "  " << y << " " << nowt << " " << nows << endl;
            if(x == gx && y == gy){
                ans = nowt;
                break;
            }
            rep(i,4){
                int tx = x + dx[i];
                int ty = y + dy[i];
                if(in(tx,ty)){
                    if(a[tx][ty] == 'D'){
                        if(nows >= c){
                            int ps = nows - c;
                            if(vis[tx][ty][ps])continue;
                            vis[tx][ty][ps] = 1;
                            q.push(mmp(nowt+2,ps+1,tx,ty));
                        }else{
                            int ps = nows + 1;
                            if(ps > s || vis[tx][ty][ps])continue;
                            vis[x][y][ps] = 1;
                            q.push(mmp(nowt+1,ps,x,y));
                        }
                    }else{
                        int ps = min(s,nows + 1);
                        if(vis[tx][ty][ps])continue;
                        vis[tx][ty][ps] = 1;
                        q.push(mmp(nowt + 1,ps,tx,ty));
                    }
                }
            }
        }
        cout << ans << endl;
    }
    return 0;
}
