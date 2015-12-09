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
typedef unsigned long long ull;
typedef pair<int,int> PII;
typedef vector<PII> VII;
typedef vector<int> VI;
#define X first
#define Y second
#define MOD 0x100000000ll
typedef unsigned int UINT;

#define maxn 500100
  
UINT phi[maxn];
UINT ans[maxn];
UINT f[maxn];
int t;

UINT pre[maxn];
UINT pre2[maxn];

void init()
{  
    REP(i,maxn)
    {
        if(i) pre[i]=pre[i-1]+(UINT)i;
        if(i) pre2[i]=pre2[i-1]+(UINT)i*(UINT)i;
    }
    memset(phi, 0, sizeof(phi));
    phi[1] = 1;  
    for(int i = 2; i < maxn; i++)  
    {  
        if(!phi[i])  
        {  
            for(int j = i; j < maxn; j += i)  
            {  
                if(!phi[j])  
                {  
                    phi[j] = j;
                }
                phi[j] = phi[j] / i * (i - 1);  
            }
        }
    }
    memset(ans, 0, sizeof(ans));  
    memset(f, 0, sizeof(f));  
    for(int i = 2; i < maxn; i++)  
    {  
        for(int j = i; j < maxn; j += i)  
        {  
            f[j] += ((ull)phi[i])*i / 2 * j;  
        }  
        ans[i] = ans[i - 1] + f[i];
    }
}

UINT slcm(int n)
{
    return ans[n]+pre[n];
}

ull solve(int n)
{
    ull r=0;
    int l=0,t=0;
    for(int i=1; i<=n/i; i++)
    {
        r+=(UINT)i*(UINT)i*slcm(n/i);
        if(i!=n/i) r+=(pre2[n/(i)]-pre2[n/(i+1)])*slcm(i);
        r%=MOD;
    }
    /*UINT r2=0;
    for(int i=1; i<=n; i++)
    {
        r2+=(UINT)i*(UINT)i*slcm(n/i);
    }*/
    //cout<<r<<endl;
    //cout<<r2<<endl;
    return r;
}

int main()
{
    init();
    //ios::sync_with_stdio(false);
    int t,n,cs=1;
    scanf("%d",&t);
    /*REP(i,500000)
    {
        if(!solve(i+1)) cout<<i<<endl;
    }*/
    while(t--)
    {
        scanf("%d",&n);
        printf("Case #%d: %I64u\n", cs++, solve(n));
    }
    return 0;
}

