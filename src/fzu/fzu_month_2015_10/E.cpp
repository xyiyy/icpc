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
typedef vector<PII> VII;
typedef vector<int> VI;
int a[100010];
int b[100010];
int f[100010];
int vis[100010];
int main()
{
    ios::sync_with_stdio(false);
    #ifdef LOCAL
        freopen("in.txt","r",stdin);
    #endif // LOCAL
    int n,m;
    int t;
    scanf("%d",&t);
    while(t--){
        scanf("%d%d",&n,&m);
        int x;
        rep2(i,1,n)a[i] = b[i] = 0;
        int s1 = 0, s2 = 0;
        rep(i,n){
            scanf("%d",&x);
            f[i + 1] = x;
            if(x>0)a[x]++;
            else b[-x]++;
        }
        rep2(i,1,n){
            s1 += a[i];
            s2 += b[i];
        }
        //cout << s1 << " " << s2 << endl;
        int num = 0;
        rep2(i,1,n){
            vis[i] = 0;
            if(a[i] + s2 - b[i] == m){
                num++;
                vis[i] = 1;
            }
        }
        rep2(i,1,n){
            x = f[i];
            int y = abs(x);
            //cout << vis[i] << endl;
            if(vis[y]){
                if(x < 0){
                    if(num == 1)printf("Lie");
                    else printf("Not defined");
                }else{
                    if(num == 1)printf("Truth");
                    else printf("Not defined");
                }
            }else{
                if(x < 0){
                    printf("Truth");
                    //if(num == 1)printf("Truth");
                    //else printf("Not defined");
                }else{
                    printf("Lie");
                    //if(num == 1)printf("Lie");
                    //else printf("Not defined");
                }
            }
            puts("");
        }
    }

    return 0;
}

