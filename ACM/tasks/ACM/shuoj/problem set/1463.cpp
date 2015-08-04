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
bool in(int x, int y ){
    if(x>0&&x<=8&&y>0&&y<=8)return 1;
    return 0;
}
int vis[10][10];
int dirx[8]={-2,2,-1,1};
int diry[8]={1,1,2,2};
int main()
{
	ios::sync_with_stdio(false);
    int sx,sy;
    while(cin>>sx>>sy){
        CLR(vis,0);
        vis[sx][sy]=1;
        queue<PII>q;
        q.push(MP(sx,sy));
        while(!q.empty()){
            PII p = q.front();
            q.pop();
            int x = p.first;
            int y = p.second;
            if(x==8&&y==8)break;
            for(int i=0;i<4;i++){
                int tx = x+dirx[i];
                int ty = y+diry[i];
                if(in(tx,ty)&&!vis[tx][ty]){
                    vis[tx][ty]=vis[x][y]+1;
                    q.push(MP(tx,ty));
                }
            }
        }
        if(!vis[8][8])cout<<"Impossible"<<endl;
        else cout<<vis[8][8]-1<<endl;
    }
	return 0;
}


