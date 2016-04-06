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

const int MAXN = 110* 110 * 110;

int pa[MAXN]; // parent
int ra[MAXN]; // rank
 bool vis[110][110][110];
void init(int n)
{
	for(int i = 0; i < n; i++)
	{
		pa[i] = i;
		ra[i] = 0;
	}
}

int find(int x)
{
	if(pa[x]!=x) pa[x] = find(pa[x]);
	return pa[x];
}

// 0: already united;  1: successfully united;
int unite(int x, int y)
{
	x = find(x);
	y = find(y);
	if(x==y)return 0;
	if(ra[x] < ra[y])
	{
		pa[x] = y;
	}else{
		pa[y] = x;
		if(ra[x] == ra[y]) ra[x]++;
	}
	return 1;
}

bool same(int x, int y)
{
	return find(x) == find(y);
}
int a[100010],b[100010],c[100010];
bool in(int x,int y,int z){
    if(x < 0||y < 0 || z < 0 || x > 101 || y > 101 || z > 101)return 0;
    return 1;
}
int dx[6]={0,0,1,0,0,-1};
int dy[6]={0,1,0,0,-1,0};
int dz[6]={1,0,0,-1,0,0};
int main()
{
    ios::sync_with_stdio(false);
    int t;
    cin >> t;
    while(t--){
        clr(vis,0);
        int n;
        cin >> n;
        init(MAXN);
        int now;
        int tx,ty,tz;
        int ppp = 102 * 102;
        int pp = 102;
        rep2(i,0,101){
            rep2(j,0,101){
                int k = 0;
                now = i * ppp + j * pp;
                rep(d,3){
                    tx = i + dx[d];
                    ty = j + dy[d];
                    tz = k + dz[d];
                    if(in(tx,ty,tz)){//&&!vis[tx][ty][tz]){
                        unite(tx*ppp+ty*pp+tz,now);
                    }
                }
            }
        }
        bool ans = 1;
        rep(i,n){
            cin >> a[i] >> b[i] >> c[i];
            vis[a[i]][b[i]][c[i]] = 1;
            now = a[i] * ppp + b[i] * pp + c[i] ;
            bool ok = 0;
            rep(d,6){
                tx = a[i] + dx[d];
                ty = b[i] + dy[d];
                tz = c[i] + dz[d];
                if(in(tx,ty,tz)&&!vis[tx][ty][tz]){
                    ok |= same(tx * ppp + ty * pp + tz,now);
                    //unite(tx*ppp+ty*pp+tz,now);
                }
            }
            if(ok){
                rep(d,6){
                tx = a[i] + dx[d];
                ty = b[i] + dy[d];
                tz = c[i] + dz[d];
                if(in(tx,ty,tz)&&!vis[tx][ty][tz]){
                    //ok |= same(tx * ppp + ty * pp + tz,now);
                    unite(tx*ppp+ty*pp+tz,now);
                }
                }
            }else ans = 0;
        }
        if(!ans){

            cout << "No" << endl;
            continue;
        }

        init(MAXN);
        rep2(i,0,101){
            rep2(j,0,101){
                rep2(k,0,101){
                    now = i * ppp + j * pp + k;
                    rep(d,3){
                        tx = i + dx[d];
                        ty = j + dy[d];
                        tz = k + dz[d];
                        if(in(tx,ty,tz)&&!vis[tx][ty][tz]){
                            unite(tx*ppp+ty*pp+tz,now);
                        }
                    }
                }
            }
        }
        int gao = 101 * ppp + 101 * pp + 101;
        int p;
        //bool ans = 1;
        dep(i,n-1,0){
            vis[a[i]][b[i]][c[i]] = 0;
            now = a[i] * ppp + b[i] * pp + c[i];
            bool flag = 0;
            rep(j,6){
                tx = a[i] + dx[j];
                ty = b[i] + dy[j];
                tz = c[i] + dz[j];
                if(in(tx,ty,tz)&&!vis[tx][ty][tz]){
                    p = tx * ppp + ty * pp + tz;
                    unite(now,p);
                    flag |= same(now,gao);
                }
            }
            if(flag){
                continue;
            }else{
                ans = 0;
                break;
            }

            //if(!same())
        }
        if(!ans)cout << "No" << endl;
        else cout << "Yes" << endl;
    }
    return 0;
}

