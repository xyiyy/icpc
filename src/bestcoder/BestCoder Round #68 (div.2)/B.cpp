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
#define MAXN 300000

int pa[MAXN]; // parent
int ra[MAXN]; // rank
int sum[MAXN];
void init(int n)
{
	for(int i = 0; i < n; i++)
	{
		pa[i] = i;
		ra[i] = 0;
		sum[i]=0;
	}
}

int find(int x)
{
	if(pa[x]!=x) pa[x] = find(pa[x]);
	return pa[x];
}

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


int main()
{
    ios::sync_with_stdio(false);
    #ifdef LOCAL
       // freopen("in.txt","r",stdin);
    #endif // LOCAL
    int t;
    scanf("%d",&t);
    while(t--){
        int n;
        scanf("%d",&n);
        int u,v,w;
        init(n+10);
        rep(i,n-1){
            scanf("%d%d%d",&u,&v,&w);
            if(!w){
                unite(u,v);
            }
        }
        rep2(i,1,n){
            sum[find(i)]++;
        }
        int ans = 0;
        rep2(i,1,n){
            if(sum[i]&1)ans = ans^sum[i];
        }
        printf("%d\n",ans);

    }

    return 0;
}

