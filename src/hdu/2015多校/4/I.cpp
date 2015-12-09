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
char a[1010][1010];
bool vis[1010][1010];
priority_queue<pair<string,PII>,vector<pair<string,PII> >,greater<pair<string,PII> > >q;
int dirx[4]={1,0,0,-1};
int diry[4]={0,1,-1,0};
int n,m;
bool in(int x,int y){
	if(x<1||y<1||x>n||y>m)return 0;
	return 1;
}
int main()
{
	ios::sync_with_stdio(false);
	int t;
	scanf("%d",&t);
	while(t--){
		scanf("%d%d",&n,&m);
		for(int i=1;i<=n;i++){
			getchar();
			for(int j=1;j<=m;j++){
				scanf("%c",&a[i][j]);
				vis[i][j] = 0;
			}
		}
		while(!q.empty())q.pop();
		string tmp = "";
		if(a[1][1]=='1')tmp = "1";
		q.push(MP(tmp,MP(-1,-1)));
		vis[1][1] = 1;
		string ans;
		int f= 0;
		while(!q.empty()){
			pair<string,PII> p = q.top();q.pop();
			tmp = p.first;
			int x = -p.second.first;
			int y = -p.second.second;
			if(x==n&&y==m){
				ans = tmp;
				break;
			}
			for(int i=0;i<4;i++){
				int tx = x + dirx[i];
				int ty = y + diry[i];
				if(in(tx,ty)&&!vis[tx][ty]){
					if(a[tx][ty]=='1')q.push(MP(tmp+'1',MP(-tx,-ty)));
					else if(a[tx][ty]=='0'&&tmp.size()>0)q.push(MP(tmp+'0',MP(-tx,-ty)));
					else q.push(MP(tmp,MP(-tx,-ty)));
					vis[tx][ty] = 1;
					if(tx==n&&ty==m){
						ans = tmp+a[tx][ty];
						f = 1;
					}
				}
				if(f)break;
			}
			if(f)break;
		}
		if(ans=="")ans="0";
		cout<<ans<<endl;
	}
	return 0;
}



