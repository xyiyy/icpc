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
char a[110][110];
int n,m;
int num;
int dirx[4] = {-1,0,0,1};
int diry[4] = {0,-1,1,0};
void dfs(int x,int y){
    if(x<0||y<0||x>=n||y>=m)return ;
    if(a[x][y]=='#')return ;
    num++;
    a[x][y]='#';
    for(int i=0;i<4;i++){
        int tx = dirx[i] + x;
        int ty = diry[i] + y;
        dfs(tx,ty);
    }
}
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    while(cin>>m>>n&&(n||m)){
        int sx,sy;
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                cin>>a[i][j];
                if(a[i][j]=='@'){
                    a[i][j] = '.';
                    sx = i;
                    sy = j;
                }
            }
        }
        num = 0;
        dfs(sx,sy);
        cout<<num<<endl;
    }
    return 0;
}

