
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
#define MAXN 200000

int pa[MAXN]; // parent
int ra[MAXN]; // rank

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

int main()
{
	ios::sync_with_stdio(false);
    int n,m;
    cin>>n>>m;
    init(2*n+10);
    int num =0;
    int p,q;
    for(int i=0;i<m;i++){
        cin>>a>>b>>c;
        if(!c){
            num++;
            if(same(a,b+n)){
                cout<<0<<endl;
                return 0;
            }
            unite(a,b+n);
            unite(b+n,a);
        }
        else{
            unite(a,b);
            unite(a+n,b+n);
        }
    }





	return 0;
}


