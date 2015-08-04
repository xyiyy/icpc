//#####################
//Author:xyiyy
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
#define mp(X,Y) make_pair(X,Y)
#define pb(X) push_back(X)
#define rep(X,N) for(int X=0;X<N;X++)
#define rep2(X,L,R) for(int X=L;X<=R;X++)
#define dep(X,R,L) for(int X=R;X>=L;X--)
#define clr(A,X) memset(A,X,sizeof(A))
#define IT iterator
typedef long long ll;
typedef pair<int,int> PII;
typedef vector<PII> vii;
typedef vector<int> vi;
#define  fi first
#define  se second

int a[110][110];
int d[110];
int dirx[4] = {-1,1,0,0};
int diry[4] = {0,0,-1,1};
int ans1[110];
int ans2[110];
class hdu5336 {
public:
	void solve(std::istream& in, std::ostream& out) {
		int r,c,n,t;
		while(in>>r>>c>>n>>t){
			clr(a,-1);
			rep(i,n){
				int x,y,sz;
				in>>x>>y>>sz;
				a[x][y] = i;
				d[i] = sz;
			}
			int sx,sy;
			in>>sx>>sy;
			vector<pair<PII,int> > v;
			rep(i,4)v.pb(mp(mp(sx,sy),i));
			//rep(i,n)out<<d[i]<<endl;
			rep(k,t){
				vector<pair<PII,int> >tmp;
				vector<PII>f;
				rep(i,v.size()){
					int dir = v[i].se;
					int tx = v[i].fi.fi + dirx[dir];
					int ty = v[i].fi.se + diry[dir];
					if(tx<=0||tx>r||ty<=0||ty>c)continue;
					if(a[tx][ty]!=-1){
						int num = a[tx][ty];
						d[num]++;
						if(d[num]==5)f.pb(mp(tx,ty));
					}else{
						tmp.pb(mp(mp(tx,ty),dir));
					}
				}
				rep(i,f.size()){
					int x = f[i].fi;
					int y = f[i].se;
					if(a[x][y]!=-1){
						int num = a[x][y];
						a[x][y] = -1;
						ans1[num] = 0;
						ans2[num] = k+1;
						d[num] = -1;
						rep(j,4)tmp.pb(mp(mp(x,y),j));
					}
				}
				v=tmp;
			}
			//out<<"ok"<<endl;
			rep(i,n){
				if(d[i]!=-1)out<<1<<" "<<d[i]<<endl;
				else out<<ans1[i]<<" "<<ans2[i]<<endl;
			}
		}
	}
};
