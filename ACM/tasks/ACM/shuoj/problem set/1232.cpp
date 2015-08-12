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

 int cmp(const void *a,const void *b)
 {
     return *(int*)a-*(int*)b;
 }

 int a[1002],b[1002];
 inline void read(int *p,int n)
 {
     for (int i=0; i<n; ++i) scanf("%d",p+i);
 }
 int main()
 {
     int n;
     while (~scanf("%d",&n) && n)
     {
         read(a,n);
         read(b,n);
         qsort(a,n,sizeof(a[0]),cmp);
         qsort(b,n,sizeof(b[0]),cmp);
         int ans=0;
         int i=0,j=0,in=n-1,jn=n-1;
         while(i<=in)
         {
             if (a[i]>b[j]) {++ans;++i;++j;continue;}
             if (a[i]<b[j]) {--ans;++i;--jn;continue;}
             if (a[in]>b[jn]) {++ans;--in;--jn;continue;}
             if (a[i]<b[jn]) --ans;
             ++i;--jn;
         }
         printf(ans>0?"YES\n":"NO\n");
     }
 }
