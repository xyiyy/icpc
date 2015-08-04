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
int n,m;
string str[2020];
int dirx[4] = {1,-1,0,0};
int diry[4] = {0,0,1,-1};
int deg[2010][2010];
bool in(int x,int y){
    if(x<0||x>=n||y<0||y>=m)return 0;
    return 1;
}
queue<PII> q;
int toposort(){
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            if(str[i][j]=='.'){
                for(int k=0;k<4;k++){
                    int x = i + dirx[k];
                    int y = j + diry[k];
                    if(in(x,y)&&str[x][y]=='.'){
                        deg[i][j]++;
                    }
                }
            }
        }
    }
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            if(deg[i][j]==1)q.push(MP(i,j));
        }
    }
    while(!q.empty()){
        PII p = q.front();
        q.pop();
        int x = p.first;
        int y = p.second;
        for(int i=0;i<4;i++){
            int tx = x + dirx[i];
            int ty = y + diry[i];
            if(in(tx,ty)&&str[tx][ty]=='.'){
                if(i==0){
                    str[x][y] = '^';
                    str[tx][ty] = 'v';
                }else if(i==1){
                    str[x][y] = 'v';
                    str[tx][ty] = '^';
                }else if(i==2){
                    str[x][y] = '<';
                    str[tx][ty] = '>';
                }else{
                    str[x][y] = '>';
                    str[tx][ty] = '<';
                }
                deg[tx][ty] = 0;
                deg[x][y] = 0;
                for(int j=0;j<4;j++){
                    int gx = tx + dirx[j];
                    int gy = ty + diry[j];
                    if(in(gx,gy)&&str[gx][gy]=='.'){
                        deg[gx][gy]--;
                        if(deg[gx][gy]==1)q.push(MP(gx,gy));
                    }
                }
            }
        }
    }
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            if(str[i][j]=='.')return 0;
        }
    }
    return 1;
}
int main()
{
    ios::sync_with_stdio(false);
    cin>>n>>m;
    for(int i=0;i<n;i++){
        cin>>str[i];
    }
    if(toposort()){
        for(int i=0;i<n;i++)cout<<str[i]<<endl;
    }else cout<<"Not unique"<<endl;

    return 0;
}
