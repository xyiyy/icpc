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
map<string,int>ms;
int deg[20010];
vector<int>G[20010];
int main()
{
	ios::sync_with_stdio(false);
    int t;
    cin>>t;
    int cas=1;
    while(t--){
        int n;
        cin>>n;
        ms.clear();
        CLR(deg,0);
        int u,v;
        int tot=0;
        for(int i=0;i<2*n;i++)G[i].clear();
        string str;
        for(int i=0;i<n;i++){
            cin>>str;
            if(!ms.count(str)){
                ms[str]=tot++;
            }
            u=ms[str];
            cin>>str;
            if(!ms.count(str)){
                ms[str]=tot++;
            }
            v=ms[str];
            G[u].PB(v);
            deg[v]++;
            //deg[ms[str]]++;
        }
        int num =0 ;
        queue<int>q;
       /* for(map<string,int>::iterator it=ms.begin();it!=ms.end();it++){
                num = it->second;
            if(deg[num]==0){
                q.push(num);
            }
        }*/
        for(int i=0;i<tot;i++){
            if(!deg[i])q.push(i);
        }
        while(!q.empty()){
            int x= q.front();
            num++;
            q.pop();
            for(int i=0;i<G[x].size();i++){
                v = G[x][i];
                deg[v]--;
                if(!deg[v]){
                    q.push(v);
                }
            }
        }
        cout<<"Case "<<cas++<<": ";
        if(num==tot)cout<<"Yes"<<endl;
        else cout<<"No"<<endl;
        //if(deg[ms["wine"]]==0)cout<<"Yes"<<endl;
        //else cout<<"No"<<endl;
    }
	return 0;
}


