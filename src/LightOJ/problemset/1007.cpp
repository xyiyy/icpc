#pragma comment(linker, "/STACK:102400000,102400000")
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
typedef unsigned long long ll;
typedef pair<int,int> PII;
typedef vector<PII> VII;
typedef vector<int> VI;
const int MAXN = 5000010;
ll phi[MAXN];
void Eular(){
    phi[1]=1;
    for(int i=2;i<=MAXN;i++){
        if(!phi[i])
        for(int j=i;j<=MAXN;j+=i){
            if(!phi[j])phi[j]=j;
            phi[j]=phi[j]/i*(i-1);
        }
    }
    phi[0]=0;
    for(int i=1;i<MAXN;i++){
        phi[i]=phi[i]*phi[i]+phi[i-1];
    }
}
int main()
{
	ios::sync_with_stdio(false);
    int t;
    int cas=1;
    Eular();
    scanf("%d",&t);
    while(t--){
        int a,b;
        scanf("%d%d",&a,&b);
        printf("Case %d: %llu\n",cas++,phi[b]-phi[a-1]);
    }
	return 0;
}




