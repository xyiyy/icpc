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
vector<int>G[110];
int deg[110];
int main()
{
	ios::sync_with_stdio(false);
    int n,m;
    while(cin>>n>>m){
        int u,v;
        for(int i=0;i<n;i++)G[i].clear();
        for(int i=0;i<n;i++)deg[i]=0;
        for(int i=0;i<m;i++){
            cin>>u>>v;
            u--;
            v--;
            G[v].PB(u);
            deg[u]++;
        }
        queue<int>q;
        for(int i=0;i<n;i++){
            if(!deg[i])q.push(i);
        }
        int num=0;
        while(!q.empty()){
            int x= q.front();
            q.pop();
            num++;
            for(int i=0;i<G[x].size();i++){
                int v=G[x][i];
                deg[v]--;
                if(deg[v]==0)q.push(v);
            }
        }
        if(num==n)cout<<"YES"<<endl;
        else cout<<"NO"<<endl;

    }
	return 0;
}


