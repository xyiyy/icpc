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

vector<int>G[1010];
int deg[1010];
int xx1[1010],yy1[1010],xx2[1010],yy2[1010];
int px[1010][4],py[1010][4];
bool ok[1010][4];
bool can[1010];
bool vis[1010];
int main()
{
    ios::sync_with_stdio(false);
    int w,h,n;
    cin >> w >> h >> n;
    rep(i,n){
        cin >> xx1[i] >> yy1[i] >> xx2[i] >> yy2[i];
        px[i][0] = px[i][1] = xx1[i];
        px[i][2] = px[i][3] = xx2[i];
        py[i][0] = py[i][2] = yy1[i];
        py[i][1] = py[i][3] = yy2[i];
    }
    rep(i,n){
        rep(k,4){
            ok[i][k] = true;
        }
    }
    rep(i,n){
        for(int j = i + 1;j < n ; j ++ ){
            int zx = abs(xx1[i] + xx2[i] - xx1[j] - xx2[j]);
            int zy = abs(yy1[i] + yy2[i] - yy1[j] - yy2[j]);
            int lx = xx2[i] - xx1[i] + xx2[j] - xx1[j];
            int ly = yy2[i] - yy1[i] + yy2[j] - yy1[j];
            if(zx < lx && zy < ly){
                //cout << i << " " << j << endl;
                rep(k,4){
                    if(ok[i][k]){
                        if(px[i][k] >= xx1[j] && px[i][k] <= xx2[j] && py[i][k] >= yy1[j] && py[i][k] <= yy2[j]){
                            ok[i][k] = false;
                        }
                    }
                }
                G[i].pb(j);
            }

        }
    }
    rep(i,n){
        rep(k,4){
            if(ok[i][k])can[i] = true;
        }
        //cout << can[i] << endl;
    }
    queue<int> q;
    int ans = -1;
    int num = 0;
    rep(i,n){
        if(can[i]){
            clr(vis,0);
            while(!q.empty())q.pop();
            int temp = 1;
            rep(j,G[i].size()){
                int p = G[i][j];
                q.push(p);
                vis[p] = true;
                temp++;
            }
            //cout << temp << endl;
            while(!q.empty()){
                int p = q.front();
                q.pop();
                rep(j,G[p].size()){
                    int pp = G[p][j];
                    if(vis[pp])continue;
                    q.push(pp);
                    vis[pp] = true;
                    temp++;
                }
            }
            if(temp > ans){
                num = i + 1;
                ans = temp;
            }

        }
    }
    cout << ans << " " << num << endl;


    return 0;
}

