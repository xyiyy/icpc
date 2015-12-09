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
map<int,int>ms;
vector<int>G[10010];
int deg[10010];
int main()
{
	ios::sync_with_stdio(false);
	int t;
	cin>>t;
	while(t--){
		int n,k;
		cin>>n>>k;
		ms.clear();
		int x,y;
		int tot = 0;
		for(int i=0;i<3*k;i++)G[i].clear();
		CLR(deg,0);
		for(int i=0;i<k;i++){
			cin>>x>>y;
			if(!ms.count(x))ms[x]=tot++;
			if(!ms.count(y))ms[y]=tot++;
			int u = ms[x];
			int v = ms[y];
			G[u].PB(v);
			deg[ms[y]]++;
		}
		queue<int>q;
		for(int i=0;i<tot;i++)
			if(!deg[i])q.push(i);
		int num = 0;
		while(!q.empty()){
			int x = q.front();
			num++;
			q.pop();
			for(int i=0;i<G[x].size();i++){
				int y = G[x][i];
				deg[y]--;
				if(!deg[y])q.push(y);
			}
		}
		if(num==tot)cout<<"YES"<<endl;
		else cout<<"NO"<<endl;
	}	
	return 0;
}



