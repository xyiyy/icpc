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

int a[1000];
int b[1000];
int main()
{
	ios::sync_with_stdio(false);
    int t;
    scanf("%d",&t);
    int cas = 1;
    while(t--){
        int p,l;
        scanf("%d%d",&p,&l);
        p-=l;
        int tot = 0;
        int tot2=0;
        ll tmp = p;
        for(ll i=1;i*i<=tmp;i++){
            int x = tmp/i;
            if(x*i==tmp){
                //cout<<i<<endl;
                if(i>l)a[tot++]=i;
                if(x>l&&x!=i)b[tot2++]=x;
            }
        }
        //sort(a,a+tot);
        printf("Case %d:",cas++);
        if(tot+tot2==0){
            printf(" impossible\n");
            continue;
        }
        for(int i=0;i<tot;i++){
            printf(" %d",a[i]);
        }
        for(int i=tot2-1;i>=0;i--){
            printf(" %d",b[i]);
        }
        printf("\n");

    }
	return 0;
}


