//gaoshenbaoyou  ------ pass system test
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
typedef pair<int,int> PII;
typedef vector<PII> VII;
typedef vector<int> VI;
#define  lld __int64
bool prim[100010];
lld p[100010];
lld primnum=0;
lld cntofprim[100010];
lld C3[100010];
lld cnt[100010]={0};
void init(){
    int i,j;
    memset(prim,0,sizeof(prim));
    for(i=2;i<=100000;i++){
        for(j=2*i;j<=100000;j+=i){
            prim[j]=true;
        }
    }
    for(i=2;i<=100000;i++){
        if(!prim[i]){
            p[primnum++]=i;
        }
    }
    for(i=0;i<primnum;i++){
        cnt[p[i]]=1;
        for(j=2;j<=100000&&j*p[i]<=100000;j++){
            if(j%p[i] && cnt[j])
                cnt[j*p[i]] = cnt[j]+1;
        }
    }
    for(i=2;i<=100000;i++)
        if(cnt[i])
            cnt[i]=(cnt[i]&1) ? 1 : -1;
        for(i=3;i<=100000;i++)
            C3[i]=(lld)(i*(i-1)/2)*(i-2)/3;
}
int main(){
    init();
   __int64 n,a,i,j,k;
    while(scanf("%I64d",&n)!=EOF){
        int Max=0;
        memset(cntofprim,0,sizeof(cntofprim));
        for(i=0;i<n;i++){
            scanf("%I64d",&a);
            if(a>Max) Max = a;
            cntofprim[a]++;
            for(j=2;j*j<=a;j++){
                if(a%j==0){
                    cntofprim[j]++;
                    if(j*j!=a){
                        cntofprim[a/j]++;
                    }
                }
            }
        }
        
        lld sum=0;
        for(i=2;i<=Max;i++){
            if(cnt[i]==0) continue;
            sum+=cnt[i]*C3[cntofprim[i]];
        }
        printf("%I64d\n",sum);
        //for(i=2;i<=Max;i++)
        //{
        //	if(prime[i]&&cnt[i])
        printf("%I64d\n",C3[n]-sum);
    }
    return 0;
}


