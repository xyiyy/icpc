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
int ans = 0;
char a[110][110];
int visr[110],visc[110];
void dfs(int x,int y,int num){
    if(x==n||y==n)return;
    if(visr[x]||visc[y])return;
    if(num == m){
        ans++;
        return;
    }
    visr[x]=1;
    visc[y]=1;
    for(int i=x+1;i<n;i++){
        for(int j=0;j<n;j++){
            if(a[i][j]=='#')dfs(i,j,num+1);
        }
    }
    visr[x]=0;
    visc[y]=0;
}
int main()
{
    ios::sync_with_stdio(false);
    while(cin>>n>>m&&(n!=-1||m!=-1)){
        for(int i=0;i<n;i++){
            for(int j =0;j<n;j++){
                cin>>a[i][j];
            }
        }
        ans = 0;
        for(int i=0;i<n;i++){
            for(int j=0;j<n;j++){
                if(a[i][j]=='#')dfs(i,j,1);
            }
        }
        cout<<ans<<endl;
    }
    return 0;
}
