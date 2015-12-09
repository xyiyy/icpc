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
#define MAXN 100010
ll sum[MAXN];
int num[MAXN],size[MAXN];
ll add[MAXN],mul[MAXN];
void push_up(int r){
	size[r]=size[r<<1]+size[r<<1|1];
	sum[r]=sum[r<<1]+sum[r<<1|1];
}
void build(int l,int r,int cur){
	if(l==r){
		add[cur]=0;mul[cur]=0;
		sum[cur]=num[l];
		size[cur]=1;
	}
	int mid=(l+r)>>1;
	build(l,mid,cur<<1);
	build(mid+1,r,cur<<1|1);
	push_up(cur);
}
void update()
		
int main()
{
	ios::sync_with_stdio(false);

	return 0;
}



