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
int vis[200010];

queue<PII> q;
int main()
{
    ios::sync_with_stdio(false);
    int n,k;
    while(cin>>n>>k){
        int ans;
        if(k<=n){
            ans = n-k;
        }else{
            CLR(vis,0);
            while(!q.empty())q.pop();
            q.push(MP(n,0));
            vis[n] = 1;
            while(!q.empty()){
                PII p = q.front();
                q.pop();
                int x = p.first;
                int y = p.second;
                if(y>k-n)continue;
                if(x==k){
                    ans = y;
                    break;
                }
                if(x<k){
                    if(!vis[x+1]){
                        q.push(MP(x+1,y+1));
                        vis[x+1]=1;
                    }
                    if(!vis[2*x]){
                        q.push(MP(2*x,y+1));
                        vis[2*x] = 1;
                    }
                }
                if(x>0&&!vis[x-1]){
                    q.push(MP(x-1,y+1));
                    vis[x-1]=1;
                }
            }
        }
        cout<<ans<<endl;
    }
    return 0;
}
