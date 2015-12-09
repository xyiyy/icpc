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
char a[110][110];
bool vis[110][110];
int w,h;
int dirx[4]={-1,0,0,1};
int diry[4]={0,-1,1,0};
bool in(int x,int y){
    if(x>=0&&x<w&&y>=0&&y<h&&a[x][y]=='.')return 1;
    return 0;
}
int main()
{
	ios::sync_with_stdio(false);
    int t;
    cin>>t;
    int cas=1;
    while(t--){

        cin>>h>>w;
        int sx,sy;
        for(int i=0;i<w;i++){
            for(int j=0;j<h;j++){
                cin>>a[i][j];
                vis[i][j]=0;
                if(a[i][j]=='@'){
                    sx = i;
                    sy = j;
                    a[i][j]='.';
                    vis[i][j]=1;
                }
            }
        }
        queue<PII>q;
        q.push(MP(sx,sy));
        int ans = 1;
        while(!q.empty()){
            PII p = q.front();
            q.pop();
            int x = p.first;
            int y = p.second;
            for(int i=0;i<4;i++){
                int tx = x + dirx[i];
                int ty = y + diry[i];
                if(in(tx,ty)&&!vis[tx][ty]){
                    q.push(MP(tx,ty));
                    vis[tx][ty]=1;
                    ans ++;
                }
            }
        }
        cout<<"Case "<<cas++<<": "<<ans<<endl;
    }
	return 0;
}




