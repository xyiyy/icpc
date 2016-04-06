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
int a[110][110];
int b[110][110];
int main()
{
    ios::sync_with_stdio(false);
   int n,m;
    rep(i,110){
        rep(j,110){
            a[i][j] = min(i+1,j+1);
        }
    }
    cin >> n >> m;
    rep(i,15){
        rep(j,15){
            int num = 0;
            rep(x,n){
                rep(y,m){
                    num += a[i + x][j + y];
                }
            }
            b[i][j] = num;
            cout << setw(4)<< num << " ";
        }
        cout << endl;
    }
   rep(i,15){
        rep2(j,1,14){
            cout << setw(4) << b[i][j] - b[i][j-1];
        }
        cout << endl;
    }
    cout << endl;
    rep2(i,1,15){
        rep(j,15){
            cout << setw(4) << b[i][j] - b[i-1][j] ;
        }
        cout << endl;
    }
    int q = 1;
//    cin >> q;
    while(q--){
        //int n,m,k;
        //cin >> n >> m >> k;
        ll sum = 0;
        rep2(i,1,n){
            int x = min(m,i);
            sum += 1LL * (m - x) * x;
            sum += (1 + x) * x / 2;
        }
        ll gao = 1LL * n * m;
        ll ans = 1LL << 50;
        pair<ll,ll>ansxy = mp(ans,ans);
        ll tsum = sum;
        flag sss = 0;
        if(n > m){
            swap(n,m);
            sss = 1;
        }
        if(n <= m){
            int gudinglen = m - n + 1;
            rep2(i,1,n){
                int initlen = max(0,i - 2*(n-1) -gudinglen);
                if(gao * initlen >= k || (tsum + gao * initlen ) % k < tsum % k){
                    ll temp = tsum;
                    bool flag = false;
                    rep2(j,0,initlen){
                        if(temp % k == 0){
                            //ans = min(ans,i + j + 1);
                            flag = true;
                            if(i + j <= ans){
                                ans = i + j;
                                if(sss){
                                    ansxy = min(ansxy,mp(i,j));
                                }else ansxy = min(ansxy,mp(i,j));
                            }
                        }
                        temp += gao;
                        if(flag)break;
                    }
                    if(flag)continue;
                    int totd = (n - 1) * 2  + (gudinglen);
                    if(totd < (i - ))
                }
            }
            //int initlen =

        }

//        ll nowr = max()
//        int len =
        //cout << sum << endl;
    }
    return 0;
}
