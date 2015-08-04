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
int vis[110][110];
int a[110][110];
PII fa[110][110];
int dirx[4]={-1,0,0,1};
int diry[4]={0,-1,1,0};
bool in(int x,int y){
    if(x<0||x>=5||y<0||y>=5)return 0;
    return 1;
}
void dfs(int x,int y){
    if(x==-1&&y==-1)return;
    PII p =fa[x][y];
    int tx = p.first;
    int ty = p.second;
    dfs(tx,ty);
    cout<<"("<<x<<", "<<y<<")"<<endl;
}
int main()
{
    ios::sync_with_stdio(false);
    for(int i=0;i<5;i++){
        for(int j=0;j<5;j++){
            cin>>a[i][j];
        }
    }
    queue<PII> q;
    q.push(MP(0,0));
    vis[0][0] = 1;
    for(int i=0;i<10;i++){
        for(int j=0;j<10;j++){
            fa[i][j]=MP(-1,-1);
        }
    }
    while(!q.empty()){
        PII p = q.front();
        int x = p.first;
        int y = p.second;
        q.pop();
        for(int i=0;i<4;i++){
            int tx = x + dirx[i];
            int ty = y + diry[i];
            if(in(tx,ty)&&!vis[tx][ty]&&!a[tx][ty]){
                q.push(MP(tx,ty));
                fa[tx][ty] = MP(x,y);
                vis[tx][ty]  = 1;
            }
        }
    }
    dfs(4,4);

    return 0;
}
