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
int a[110][110];
int dirx[4]={-1,0,0,1};
int diry[4]={0,-1,1,0};
int ans ;
int n,m;
bool in(int x,int y){
    if(x<0||x>=n||y<0||y>=m)return 0;
    return 1;
}
void dfs(int x,int y,int step){
    if(step>=ans)return;
    for(int i=0;i<4;i++){
        int tx = x + dirx[i];
        int ty = y + diry[i];
        if(!in(tx,ty))continue;
		if(a[tx][ty]==3)ans = min(ans,step);
		if(a[tx][ty]==1)continue;
		while(in(tx,ty)&&a[tx][ty]==0)
		{
			tx = tx + dirx[i];
			ty = ty + diry[i];
			if(!in(tx,ty))break;
			if(a[tx][ty]==3)
			{
				ans = min(ans,step);
				break;
			}
			if(a[tx][ty] == 1)
			{
				a[tx][ty] = 0;
				dfs(tx - dirx[i],ty - diry[i],step+1);
				a[tx][ty] = 1;
				break;
			}
		}
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
                if(a[i][j]==2){
                    sx = i;
                    sy = j;
                    a[i][j] = 0;
                }
            }
        }
        ans = 11;
        dfs(sx,sy,1);
        if(ans > 10)ans = -1;
        cout<<ans<<endl;


    }
    return 0;
}
