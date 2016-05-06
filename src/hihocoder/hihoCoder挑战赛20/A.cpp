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


int a[20][100010];
const int maxn = 100010;
void init(){
    rep2(i,1,19){
        rep(j,maxn){
            int p = (j + (1<<(i-1)));
            p = p < maxn ? p : maxn - 1;
            a[i][j] = max(a[i-1][j],a[i-1][p]);
        }
    }
}
int query(int l,int r){
    int k = log2(r - l + 1);
    return max(a[k][l],a[k][r - (1<<k) + 1]);
}


int main()
{
    ios::sync_with_stdio(false);
    int n,m;
    cin >> n >> m;
    rep(i,maxn)a[0][i] = -1;
    int x,y;
    rep(i,n){
        cin >> x >> y;
        a[0][x] = max(a[0][x],y);
    }
    init();
    rep(i,m){
        cin >> x >> y;
        int ret = query(x,y);
        if(ret == -1)cout << "None" << endl;
        else cout << ret << endl;
    }

    return 0;
}

