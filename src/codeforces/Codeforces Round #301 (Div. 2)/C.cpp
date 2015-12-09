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
char a[510][510];
int b[510][510];
int dirx[4]={-1,0,0,1};
int diry[4]={0,1,-1,0};
    int n,m;
    bool vis[510][510];
bool in(int x,int y){
    if(x>=0&&x<n&&y>=0&&y<m&&b[x][y])return 1;
    return 0;
}
int main()
{
	ios::sync_with_stdio(false);

    cin>>n>>m;
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            cin>>a[i][j];
            if(a[i][j]=='X')b[i][j]=0;
            else b[i][j]=1;
        }
    }
    int sx,sy;
    int gx,gy;
    cin>>sx>>sy;
    cin>>gx>>gy;
    sx--;sy--;
    gx--;gy--;
    int c=0;
    bool flag=0;
    queue<PII>q;
    q.push(MP(sx,sy));
    vis[sx][sy]=1;
    while(!q.empty()){
        PII p =q.front();
        q.pop();
        int dx= p.first;
        int dy = p.second;
        for(int i=0;i<4;i++){
            int tx=dx+dirx[i];
            int ty=dy+diry[i];
            if(tx==gx&&ty==gy){
                int d=0;
                for(int j=0;j<4;j++){
                    if(in(gx+dirx[j],gy+diry[j]))c++;
                    if(vis[gx+dirx[j]][gy+diry[j]]&&in(gx+dirx[j],gy+diry[j]))d=1;
                }
                if((((c>1&&d)||(c&&!d))&&b[gx][gy])||!b[gx][gy])cout<<"YES"<<endl;
                else cout<<"NO"<<endl;
                return 0;
            }
            if(in(tx,ty)&&!vis[tx][ty]){
                vis[tx][ty]=1;
                q.push(MP(tx,ty));
            }
        }
    }
    cout<<"NO"<<endl;
	return 0;
}



