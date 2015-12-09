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
using namespace std;
#define XINF INT_MAX
#define INF 0x3FFFFFFF
#define MP(X,Y) make_pair(X,Y)
#define PB(X) push_back(X)
#define REP(X,N) for(int X=0;X<N;X++)
typedef pair<int,int> PII;
typedef vector<int> VI;
typedef long long ll;
#define MAX(a,b) ((a)>(b)?(a):(b))



#define NODE 6400010
#define N 100010

long long n;
long long v[N];
long long node;
long long next[NODE][2];
long long end[NODE];

void add( long long cur, long long k) {
    memset(next[node], 0, sizeof(next[node]));
    end[node]=0;
    next[cur][k]=node++;
}

 long long cal( long long x) {
     long long i,k,cur=0x0;
    for(i=31; i>=0; i--) {
        k=((0x1<<i)&x)?0x0:0x1;
        if(next[cur][k]) cur=next[cur][k];
        else    cur=next[cur][1-k];
    }
    return end[cur];
}

int main() {
	ll n,ans,T,m,t,x,cur,k;
    scanf("%I64d", &T);
    for(ll Ca = 1; Ca <= T; ++Ca) {
        scanf("%I64d%I64d", &n, &m);
        node=1;
        memset(next[0],0,sizeof(next[0]));
        for(ll i=0; i<n; i++) {
            scanf("%I64d",&x);
            v[i]=x;
            cur=0;
            for(ll j=31; j>=0; j--) {
                k=((0x1<<j)&x)?0x1:0x0;
                if(next[cur][k]==0) add(cur,k);
                cur=next[cur][k];
            }
            end[cur]=x;
        }
        printf("Case #%I64d:\n",Ca);
        for (ll i = 0; i < m; ++i) {
            scanf("%I64d", &t);
            ans = cal(t);
            printf("%I64d\n", ans);
        }
    }
    return 0;
}


