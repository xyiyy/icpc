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
#define f first
#define s second
char a[31][31][31];
int dis[31][31][31];
int dirx[6]={-1,0,0,0,0,1};
int diry[6]={0,-1,1,0,0,0};
int dirz[6]={0,0,0,-1,1,0};
int l,r,c;
bool in(int x,int y,int z){
    if(x<0||y<0||z<0||x>=l||y>=r||z>=c)return 0;
    return 1;
}
int main()
{
    ios::sync_with_stdio(false);
    while(cin>>l>>r>>c&&(l||r||c)){
        int sx,sy,sz;
        for(int i=0;i<l;i++){
            for(int j=0;j<r;j++){
                for(int k=0;k<c;k++){
                    cin>>a[i][j][k];
                    if(a[i][j][k]=='S'){
                        sx = i;
                        sy = j;
                        sz = k;
                    }
                }
            }
        }
        queue<pair<int,PII> >q;
        q.push(MP(sx,MP(sy,sz)));
        CLR(dis,-1);
        dis[sx][sy][sz]=0;
        int x,y,z;
        while(!q.empty()){
            pair<int,PII> p = q.front();
            x = p.f;
            y = p.s.f;
            z = p.s.s;
            q.pop();
            if(a[x][y][z]=='E')break;
            for(int i=0;i<6;i++){
                int tx = x + dirx[i];
                int ty = y + diry[i];
                int tz = z + dirz[i];
                if(in(tx,ty,tz)&&(a[tx][ty][tz]!='#')&&(dis[tx][ty][tz]==-1)){
                    dis[tx][ty][tz] = dis[x][y][z] + 1;
                    q.push(MP(tx,MP(ty,tz)));
                }
            }
        }
        if(a[x][y][z]!='E')cout<<"Trapped!"<<endl;
        else cout<<"Escaped in "<<dis[x][y][z]<<" minute(s)."<<endl;

    }
    return 0;
}
