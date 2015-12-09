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
int a[10010];
bool vis[300010];
int dp[300010];
vector<ll>b[210];
ll ans=1LL;
int n;
//ll fuc[210][10010];

void dfs(int x,ll lcm){
    if(lcm>=ans)return;
    if(x>n){
        ans=min(ans,lcm);
        return ;
    }
    ll tmp;
    for(int i=0;i<b[x].size();i++){
        tmp=b[x][i]/__gcd(b[x][i],lcm)*lcm;
        dfs(x+1,tmp);
        if(tmp==lcm)return;
    }
}
int main()
{
	ios::sync_with_stdio(false);
    cin>>n;
    for(int i=1;i<=n;i++)cin>>a[i];

    bool flag=0;
    int d=0;
    for(int i=1;i<=n;i++){
        dp[1]=a[i];
        vis[1]=0;
        for(int j=2;j<300010;j++){
            dp[j]=a[dp[j-1]];
            vis[j]=0;
        }
        for(int j=1;j<=150000;j++){
            if(dp[j]==dp[j*2]&&!vis[j]){
                b[i].PB(j);
                for(int k=j;k<=150000;k+=j){
                    vis[k]=1;
                }
                //break;
            }
        }
    }
    for(int i=1;i<=n;i++){
        ans=b[i][0]/__gcd(b[i][0],ans)*ans;
    }
    //cout<<"ok"<<endl;
    /*for(int i=1;i<=n;i++){
        fuc[i]=1;
        ans=b[i][0]/__gcd(b[i][0],ans)*ans;
        for(int j=1;j<=n;j++){
            if(j==i)continue;
            fuc[i]=b[j][0]/__gcd(b[j][0],fuc[i])*fuc[i];
        }
    }*/
    /*for(int i=1;i<=n;i++){
        int gao=b[i][0];
        for(int j=1;j<=b[i].size();j++){
            if(fuc[i]/__gcd(fuc[i]/))
        }
    }*/
   /* for(int i=0;i<b[1].size();i++){
        fuc[1][i]=b[1][i];
    }
    for(int i=2;i<=n;i++){
        int sz1=b[i-1].size();
        int sz=b[i].size();
        for(int j=0;j<sz;j++){
            fuc[i][j]=fuc[i-1][0]/__gcd(b[i][j],fuc[i-1][0])*b[i][j];
            if(fuc[i][j]==fuc[i-1][0])continue;
            for(int k=1;k<sz1;k++){
                fuc[i][j]=min(fuc[i-1][k]/__gcd(b[i][j],fuc[i-1][k])*b[i][j],fuc[i][j]);
            }
        }
    }
    ans=fuc[n][0];
    for(int i=0;i<b[n].size();i++)ans=min(fuc[n][i],ans);*/
    dfs(1,1LL);
    cout<<ans<<endl;


	return 0;
}



