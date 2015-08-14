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
char a[10][10];
int dirx[4]={-1,0,0,1};
int diry[4]={0,-1,1,0};
int ok;
int n,m;
int gx,gy;
bool in(int x,int y){
    if(x<0||y<0||x>=n||y>=m)return 0;
    return 1;
}
void dfs(int x,int y,int step){
    if(x==gx&&y==gy&&step==0)ok=1;
    if(ok)return;
    if(step<=0)return;
    if(a[x][y]=='X')return;
    if(abs(x-gx)+abs(y-gy)>step)return;
    a[x][y]='X';
    for(int i=0;i<4;i++){
        int tx = dirx[i] + x;
        int ty = diry[i] + y;
        if(in(tx,ty))dfs(tx,ty,step-1);
    }
    a[x][y]='.';
}
int main()
{
    ios::sync_with_stdio(false);
    int k;
    while(cin>>n>>m>>k&&(n||m||k)){
        int sx,sy;
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                cin>>a[i][j];
                if(a[i][j]=='S'){
                    sx = i;
                    sy = j;
                }else if(a[i][j]=='D'){
                    gx = i;
                    gy = j;
                }
            }
        }
        ok = 0;
        if(abs((abs(sx-gx)+abs(sy-gy))-k)&1)ok = 0;
        else dfs(sx,sy,k);
        if(ok)cout<<"YES"<<endl;
        else cout<<"NO"<<endl;

    }
    return 0;
}
