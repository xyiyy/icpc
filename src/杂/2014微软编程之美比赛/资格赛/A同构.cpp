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
using namespace std;
#define XINF INT_MAX
#define INF 0x3FFFFFFF
#define MP(X,Y) make_pair(X,Y)
#define PB(X) push_back(X)
#define REP(X,N) for(int X=0;X<N;X++)
typedef pair<int,int> PII;
typedef vector<int> VI;
typedef long long ll;
const int MAXN=3001;
const int INF=1<<28;
int g[MAXN][MAXN],Mx[MAXN],My[MAXN],Nx,Ny;
int dx[MAXN],dy[MAXN],dis;
bool vst[MAXN];
bool searchP()
{
    queue<int>Q;
    dis=INF;
    memset(dx,-1,sizeof(dx));
    memset(dy,-1,sizeof(dy));
    for(int i=0;i<Nx;i++)
        if(Mx[i]==-1)
        {
            Q.push(i);
            dx[i]=0;
        }  
    while(!Q.empty())
    {
        int u=Q.front();
        Q.pop();
        if(dx[u]>dis)  break;
        for(int v=0;v<Ny;v++)
            if(g[u][v]&&dy[v]==-1)
            {
                dy[v]=dx[u]+1;
                if(My[v]==-1)  dis=dy[v];
                else
                {
                    dx[My[v]]=dy[v]+1;
                    Q.push(My[v]);
                }    
            }    
    }  
    return dis!=INF;    
}    
bool DFS(int u)
{
    for(int v=0;v<Ny;v++)
       if(!vst[v]&&g[u][v]&&dy[v]==dx[u]+1)
       {
           vst[v]=1;
           if(My[v]!=-1&&dy[v]==dis) continue;
           if(My[v]==-1||DFS(My[v]))
           {
               My[v]=u;
               Mx[u]=v;
               return 1;
           }    
       }  
    return 0;  
}
int MaxMatch()
{
    int res=0;
    memset(Mx,-1,sizeof(Mx));
    memset(My,-1,sizeof(My));
    while(searchP())
    {
        memset(vst,0,sizeof(vst));
        for(int i=0;i<Nx;i++)
          if(Mx[i]==-1&&DFS(i))  res++;
    }
    return res;   
}    

int main()
{
	ios::sync_with_stdio(false);
	return 0;
}

