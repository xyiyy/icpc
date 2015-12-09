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
ll bit[MAXN]; 
int tot;
void init(int num)
{
	memset(bit,0,sizeof(bit));
	tot=num;
}
ll sum(int x)
{
	ll s=0;
	while(x>0){
		s+=bit[x];
		x-=x&-x;
	}
	return s;
}
void add(int i,int x)
{
	while(i<=tot){
		bit[i]+=x;
		i+=i&-i;
	}
}

int main()
{
	//ios::sync_with_stdio(false);
	int n,m;
	while(scanf("%d%d",&n,&m)!=EOF){
		init(n);
		int tmp;
		for(int i=0;i<n;i++)
		{
			scanf("%d",&tmp);
			add(i+1,tmp);
		}
		int type,l,r;
		while(m--){
			scanf("%d%d%d",&type,&l,&r);
			if(type==1){
				add(l,r);
			}else {
				printf("%lld\n",sum(r)-sum(l-1));
			}
		}
	}
			
	return 0;
}



